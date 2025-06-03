const jwt     = require('jsonwebtoken');
const JWT_SECRET = process.env.SECRET;

function authenticateToken(req, res, next) {
    const authHeader = req.headers["authorization"];
    var token = authHeader;

    if (token == null) {
        return res.
        status(401).json({msg: 'No token, authorization denied'});
    }
    if (token.startsWith('Bearer ')) {
        token = token.slice(7);
    } else {
        return res.status(401).json({msg: 'Token is not valid'});
    }
    jwt.verify(token, JWT_SECRET, (err, user) => {
        if (err != null) {
            return res.status(401).json({msg: 'Token is not valid'});
        }
        req.user = user;
        next();
    });
}

module.exports = authenticateToken
