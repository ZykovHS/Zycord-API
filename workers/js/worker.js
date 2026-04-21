// e.g
const net = require('net');
const c = net.createConnection("/tmp/worker.sock");
c.on('data', (d) => {
    try {
        const m = JSON.parse(d.toString().split('\r\n\r\n').pop());
        console.log("Event:", m.t);
    } catch (e) {}
});
