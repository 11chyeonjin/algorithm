const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  console.log(input.join('\n'));
  process.exit();
});

