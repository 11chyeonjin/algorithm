const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  let answer = 0;

  for (let i = 0; i < input[2].length; i++) {
    if (input[1][i] <= input[2][i]) {
      answer++;
    }
  }

  console.log(answer);
  
  process.exit();
})