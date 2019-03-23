let http = require('http');
let server = http.createServer(function(request, response){
    response.writeHead(200,{
        'Content-type': 'text/plain'
    });

    response.write('Hello World!');

    response.end();


});

server.listen(8000);

console.log('Server running on port 8000');