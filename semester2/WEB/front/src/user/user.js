const express = require('express');
const bcrypt  = require('bcryptjs');
const jwt     = require('jsonwebtoken');
const auth = require('../middleware/auth')
const router = express.Router();

const JWT_SECRET = process.env.SECRET;
const SALT_ROUNDS = 10;

router.get('/user', auth, async (req, res) => {

    const [result, fields] = await global.connection.query(
        `SELECT * FROM user WHERE email = ?`,
        [req.user.email]
    );
    if (result.length <= 0) {
        res.status(404).json({msg: "Not found"})
    }
    const info = result[0];
    return res.json({
        id: info.id,
        email: info.email,
        password: info.password,
        created_at: info.created_at,
        firstname: info.firstname,
        name: info.name
    });
});

router.get('/users/:target', auth, async (req, res) => {

    const [result, fields] = await global.connection.query(
        `SELECT * FROM user WHERE email = ? or id = ?`,
        [req.params.target, req.params.target]
    );
    if (result.length <= 0) {
        return res.status(404).json({msg: "Not found"})
    }
    const info = result[0];
    return res.json({
        id: info.id,
        email: info.email,
        password: info.password,
        created_at: info.created_at,
        firstname: info.firstname,
        name: info.name
    });
});

router.delete('/users/:id', auth, async (req, res) => {

    const [result, fields] = await global.connection.query(
        `SELECT * FROM user WHERE id = ?`,
        [req.params.id]
    );
    if (result.length <= 0) {
        return res.status(404).json({msg: "Not found"})
    }
    await global.connection.query(
        'DELETE FROM user WHERE id = ?',
        [req.params.id]
    );
    return res.json({
        msg: "Successfully deleted record number: " + req.params.id
    });
});

router.put('/users/:id', auth, async (req, res) => {
    // Check if the given information are valid
    const { email, password, firstname, name } = req.body;
    const missing = [email, password, firstname, name]
        .map((v, i) => (!v ? ['email', 'password', 'firstname', 'name'][i] : null))
        .filter(Boolean);
    if (missing.length > 0) {
        return req.status(400).json({ msg: 'Bad parameter' });
    }

    // Check if the target user exist
    [result, fields] = await global.connection.query(
        `SELECT * FROM user WHERE id = ?`,
        [req.params.id]
    );
    if (result.length <= 0) {
        return res.status(404).json({msg: "Not found"})
    }

    // hash the new password
    const hashed = await bcrypt.hash(password, SALT_ROUNDS);

    await global.connection.query(
        `UPDATE user
        SET email = ?, password = ?, firstname = ?, name = ?
        WHERE id = ?`,
        [email, hashed, firstname, name, req.params.id]
    );

    [result, fields] = await global.connection.query(
        `SELECT * FROM user WHERE email = ? or id = ?`,
        [req.params.target, req.params.id]
    );
    if (result.length <= 0) {
        return res.status(404).json({msg: "Not found"})
    }
    const info = result[0];
    return res.json({
        id: info.id,
        email: info.email,
        password: info.password,
        created_at: info.created_at,
        firstname: info.firstname,
        name: info.name,
    });
});

router.get('/user/todos', auth, async (req, res) => {
    const [user] = await global.connection.query(
        `SELECT id FROM user WHERE email = ?`,
        [req.user.email]
    );
    if (user.length === 0) {
        return res.status(404).json({ msg: "User not found" });
    }
    const user_id = user[0].id;
    const [user_todos] = await global.connection.query(
        `SELECT * FROM todo WHERE user_id = ?`,
        [user_id]
    );
    return res.json(user_todos);
});

module.exports = router;
