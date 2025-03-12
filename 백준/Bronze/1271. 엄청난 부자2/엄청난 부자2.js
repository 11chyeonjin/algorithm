const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line.split(' '));
}).on('close', function() {
  const [n, m] = input[0].map(e => BigInt(e));
  console.log((n / m).toString());
  console.log((n % m).toString());
  process.exit();
})