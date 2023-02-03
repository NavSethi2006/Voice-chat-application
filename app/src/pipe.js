
const fs   = require('fs');
const {spawn, fork} = require('child_process');

let fifo = spawn('mkfifo', ['../Cwrite']);
let write_fifo = spawn('mkfifo', ['../JSwrite']);
let fifoRs;
let fifoWs;

exports.initilize_pipes = function () {
  const fd = fs.openSync("../Cwrite",'r+');
  fifoRs = fs.createReadStream(null, {fd});
  fifoWs = fs.createWriteStream("../JSwrite");
  console.log("named pipe created");
}


exports.send_msg_to_c = function (params) {
  params.forEach(value => fifoWs.write(`${value}\n`));
}

