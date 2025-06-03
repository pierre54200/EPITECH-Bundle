const express = require('express');
const bcrypt  = require('bcryptjs');
const jwt     = require('jsonwebtoken');
const router = express.Router();

const JWT_SECRET = process.env.SECRET;
const SALT_ROUNDS = 10;

router.post('/register', async (req, res) => {
    const { email, password, name, firstname } = req.body;

    const missing = [email, password, name, firstname]
        .map((v, i) => (!v ? ['email', 'password', 'name', 'firstname'][i] : null))
        .filter(Boolean);

    if (missing.length > 0) {
        return res
                .status(400)
                .json({ msg: `Missing required fields: ${missing.join(', ')}` });
    }

    const hashed = await bcrypt.hash(password, SALT_ROUNDS);

    const [found] = await global.connection.execute(
        `SELECT id FROM user WHERE email = ?`,
        [email]
    );
    if (found.length > 0) {
        return res.status(409)
            .json({msg: 'Account already exists'});
    }
    const [result] = await global.connection.execute(
        `INSERT INTO user (email, password, name, firstname)
        VALUES (?, ?, ?, ?)`,
        [email, hashed, name, firstname]
    );

    const token = jwt.sign(
        { email, password: hashed },
        JWT_SECRET,
        { expiresIn: '1h' }
    );

    console.log(`Registering new user {@:${email} P:${password} N:${name} F:${firstname}} !`);
    return res
        .status(201)
        .json({ token: token });
});

module.exports = router;