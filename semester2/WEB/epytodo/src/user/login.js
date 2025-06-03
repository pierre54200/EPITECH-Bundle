const express = require('express');
const bcrypt  = require('bcryptjs');
const jwt     = require('jsonwebtoken');
const router = express.Router();

const JWT_SECRET = process.env.SECRET;

router.post('/login', async (req, res) => {
    const { email, password } = req.body;

    const missing = [email, password]
        .map((v, i) => (!v ? ['email', 'password'][i] : null))
        .filter(Boolean);

    if (missing.length > 0) {
        return res
                .status(400)
                .json({ msg: 'Bad parameter' });
    }

    const [rows] = await global.connection.execute(
        `SELECT id, password AS hash FROM user WHERE email = ?`,
        [email]
    );
    if (rows.length === 0) {
        return res.status(401).json({ msg: 'Invalid credentials' });
    }

    const { id, hash } = rows[0];

    const isMatch = await bcrypt.compare(password, hash);
    if (!isMatch) {
        return res.status(401).json({ msg: 'Invalid credentials' });
    }

    const token = jwt.sign(
        { email, password: hash, id: id },
        JWT_SECRET,
        { expiresIn: '1h' }
    );

    console.log(`Create token for user: { ID:${id} } !`);
    return res.status(200).json({ token: token });
});

module.exports = router;