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

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function showPortOpen() {
    console.log('sending data to aurdrino');
    for (i = 0; i < 5; i++) {
        console.log('sending 0');
        await sleep(1000);
        myPort.write('update', 0);
        await sleep(1000);
        console.log('sending 90');
        myPort.write('update', 90);
        await sleep(1000);

    }

}

function readSerialData(data) {
    console.log(data.toString());
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
