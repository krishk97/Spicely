const five = require("johnny-five");


const board = new five.Board({
    port: '/dev/tty.usbmodem1441'
});

board.on("ready", function () {

    console.log('connected to Board');

    const servo = new five.Servo(8);

    // Sweep from 0-180 and repeat.
    servo.sweep();
});
