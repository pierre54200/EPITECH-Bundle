const mysql   = require('mysql2/promise');
const express = require('express');

require('dotenv').config()


async function init() {
    global.connection = await mysql.createConnection({
        host:     process.env.MYSQL_HOST,
        user:     process.env.MYSQL_USER,
        database: process.env.MYSQL_DATABASE,
        password: process.env.MYSQL_ROOT_PASSWORD,
        port:     3306
    });

    const app = express();
    const port = +process.env.PORT || 3000;

    app.use(express.json());
    app.use((err, req, res, next) => {
        if (err instanceof SyntaxError &&
                err.status === 400 &&
                'body' in err) {
            return res.status(400).json({ error: 'Invalid JSON payload' });
        }
        next(err);
    });
    app.use('/', require('./user/register'));
    app.use('/', require('./user/login'));
    app.use('/', require('./user/user'));
    app.use('/', require('./user/todos'));
    app.listen(port, () => {
        console.log(`Server running at http://localhost:${port}`);
    });
}

init().catch(err => {
    console.error('Failed to start server:', err);
    process.exit(1);
});
