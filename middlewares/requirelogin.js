
const firebase = require('firebase/app');
require('firebase/auth');


module.exports = (req, res, next) => {
    firebase.auth().onAuthStateChanged(function(user) {
    
        if (!user) {
            return res.render('signin');
        }
        });
    next();
};

// var middleware = {};
// middleware.isLoggedIn =   function(req,res,next){
//     if(req.isAuthenticated()){
//         return next()
//     }else{
//         res.redirect("/sessionExpired")
//     }
// }

// module.exports = middleware