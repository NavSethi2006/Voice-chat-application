const app = require('electron');
const pipes = require('./pipe.js');


function get_data_login() {
    email = document.getElementById("loginuser").value;
    pass = document.getElementById("loginpass").value;

    arr = [1, email,pass];

    pipes.send_msg_to_c(arr);
}

function get_data_signup() {
    email = document.getElementById("signinemail").value;
    user = document.getElementById("signinuser").value;
    pass = document.getElementById("signinpass").value;

    arr = [2,email,user,pass];

    pipes.send_msg_to_c(arr);
}