const express = require('express');
const SerialPort = require("serialport");

var serialport = new SerialPort("/dev/tty.usbmodem1421");
serialport.on('open', function(){
    console.log('Serial Port Opend');
    serialport.on('data', function(data){
        console.log(data[0]);
    });
});




const app = express();
const port = process.env.PORT || 5000;

app.get('/api/hello', (req, res) => {
    res.send({ express: 'Hello From Express' });
});

app.listen(port, () => console.log(`Listening on port ${port}`));
