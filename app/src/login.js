const app = require('electron');
const pipes = require('./pipe.js');


function get_data_login() {
    email = document.getElementById("loginuser");
    pass = document.getElementById("loginpass");

    arr = [1, email,pass];

    try {
        pipes.send_msg_to_c(arr);
    }catch(error){
        console.error(error);
    }
    console.log("shit 1");
}

function get_data_signup() {
    email = document.getElementById("signinemail");
    user = document.getElementById("signinuser");
    pass = document.getElementById("signinpass");

    arr = [2,email,user,pass];

    try {
        pipes.send_msg_to_c(arr);
    }catch(error){
        console.error(error);
    }

    console.log("shit 2");
}