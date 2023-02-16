
const fs   = require('fs');
const {spawn, fork} = require('child_process');

let fifo = spawn('mkfifo', ['../Cwrite']);
let write_fifo = spawn('mkfifo', ['../JSwrite']);
const fd = fs.openSync("../Cwrite",'r+');
let fifoRs = fs.createReadStream(null, {fd});
let fifoWs = fs.createWriteStream("../JSwrite");


exports.initilize_pipes = function () {
  console.log("named pipe created");
}


exports.send_msg_to_c = function (params) {
  params.forEach(value => fifoWs.write(`${value}\n`));
}

