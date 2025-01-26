const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const answer = solution(input[0]);
  console.log(answer);
  process.exit();
});

function solution(str) {
  const words = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z='];
  
  for (const word of words) {
    str = str.replaceAll(word, 'a');
  }

  return str.length;
}