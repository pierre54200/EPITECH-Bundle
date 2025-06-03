const express = require('express');
const router = express.Router();
const auth = require('../middleware/auth');

router.get('/todos', auth, async (req, res) => {
    const [result, fields] = await global.connection.query(
        `SELECT *, DATE_FORMAT(due_time, '%Y-%m-%d %H:%i:%s') AS due_time, DATE_FORMAT(created_at, '%Y-%m-%d %H:%i:%s') AS created_at FROM todo`
    );
    if (result.length <= 0) {
        return res.status(404).json({ msg: "Not found" });
    }
    return res.json(result);
});

router.get('/todos/:id', auth, async (req, res) => {
    const [result, fields] = await global.connection.query(
        `SELECT *, DATE_FORMAT(due_time, '%Y-%m-%d %H:%i:%s') AS due_time, DATE_FORMAT(created_at, '%Y-%m-%d %H:%i:%s') AS created_at FROM todo WHERE id = ?`,
        [req.params.id]
    );
    if (result.length <= 0) {
        return res.status(404).json({ msg: "Not found" });
    }
    return res.json(result[0]);
});

router.post('/todos', async (req, res) => {
    let { title, description, due_time, user_id, status } = req.body;

    const status_enum = ['not started', 'todo', 'in progress', 'done'];

    const missing = [title, description, due_time, user_id]
        .map((v, i) => (!v ? ['title', 'description', 'due_time', 'user_id'][i] : null))
        .filter(Boolean);
    if (missing.length > 0) {
        return res.status(400).json({ msg: 'Bad parameter' });
    }
    const date = new Date(due_time);
    if (isNaN(date.getTime())) {
        return res.status(400).json({ msg: 'Bad parameter' });
    }
    const [user] = await global.connection.query(
        `SELECT id FROM user WHERE id = ?`,
        [user_id]
    );
    console.log("The user id: " + user_id);
    if (user.length === 0) {
        return res.status(404).json({ msg: 'Not found' });
    }
    const min_status = (status || 'not started').toLowerCase();
    if (!status_enum.includes(min_status)) {
        status = 'not started';
    }
    const [result] = await global.connection.query(
        `INSERT INTO todo (title, description, due_time, user_id, status) VALUES (?, ?, ?, ?, ?)`,
        [title, description, due_time, user_id, status]
    );
    const [rows] = await global.connection.query(
        `SELECT *, DATE_FORMAT(due_time, '%Y-%m-%d %H:%i:%s') AS due_time, DATE_FORMAT(created_at, '%Y-%m-%d %H:%i:%s') AS created_at FROM todo WHERE id = ?`,
        [result.insertId]
    );
    return res.status(201).json(rows[0])
});

router.delete('/todos/:id', async (req, res) => {
    const [result] = await global.connection.query(
        `SELECT *, DATE_FORMAT(due_time, '%Y-%m-%d %H:%i:%s') AS due_time, DATE_FORMAT(created_at, '%Y-%m-%d %H:%i:%s') AS created_at FROM todo WHERE id = ?`,
        [req.params.id]
    );
    if (result.length === 0) {
        return res.status(404).json({msg: "Not found"})
    }
    await global.connection.query(
        'DELETE FROM todo WHERE id = ?',
        [req.params.id]
    );
    return res.json({
        msg: "Successfully deleted record number: " + req.params.id
    });
});

router.put('/todos/:id', async (req, res) => {
    const { title, description, due_time, user_id, status } = req.body;
    const status_enum = ['not started', 'todo', 'in progress', 'done'];
    const missing = [title, description, due_time, user_id]
        .map((v, i) => (!v ? ['title', 'description', 'due_time', 'user_id'][i] : null))
        .filter(Boolean);
    if (missing.length > 0) {
        return res.status(400).json({ msg: 'Bad parameter' });
    }
    const date = new Date(due_time);
    if (isNaN(date.getTime())) {
        return res.status(400).json({ msg: 'Bad parameter' });
    }
    const [user] = await global.connection.query(
        `SELECT id FROM user WHERE id = ?`,
        [user_id]
    );
    if (user.length === 0) {
        return res.status(404).json({ msg: 'Not found' });
    }
    const min_status = (status || 'not started').toLowerCase();
    if (!status_enum.includes(min_status)) {
        status = 'not started';
    }
    const [todo] = await global.connection.query(
        `SELECT *, DATE_FORMAT(due_time, '%Y-%m-%d %H:%i:%s') AS due_time, DATE_FORMAT(created_at, '%Y-%m-%d %H:%i:%s') AS created_at FROM todo WHERE id = ?`,
        [req.params.id]
    );
    if (todo.length === 0) {
        return res.status(404).json({ msg: 'Not found' });
    }
    await global.connection.query(
        `UPDATE todo SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id = ?`,
        [title, description, due_time, user_id, status, req.params.id]
    );
    const [updatedTodo] = await global.connection.query(
        `SELECT *, DATE_FORMAT(due_time, '%Y-%m-%d %H:%i:%s') AS due_time, DATE_FORMAT(created_at, '%Y-%m-%d %H:%i:%s') AS created_at FROM todo WHERE id = ?`,
        [req.params.id]
    );
    return res.status(200).json(updatedTodo[0]);
});

module.exports = router;
