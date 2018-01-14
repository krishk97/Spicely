const serialport = require('serialport');


// list serial ports:
serialport.list(function (err, ports) {
    ports.forEach(function (port) {
        console.log(port.comName);
    });
});

var portName = process.argv[2];
console.log('=====================');

var myPort = new serialport('/dev/tty.usbmodem1441', 9600);

var Readline = serialport.parsers.Readline; // make instance of Readline parser
var parser = new Readline(); // make a new parser to read ASCII lines
myPort.pipe(parser); // pipe the serial stream to the parser

function showPortOpen() {
    console.log('port open. Data rate: ' + myPort.baudRate);
    myPort.on('data', readSerialData);
}

function readSerialData(data) {
    console.log(data);
}

function showPortClose() {
    console.log('port closed.');
}

function showError(error) {
    console.log('Serial port error: ' + error);
}

myPort.on('open', showPortOpen);
myPort.on('data', readSerialData);
myPort.on('close', showPortClose);
myPort.on('error', showError);
