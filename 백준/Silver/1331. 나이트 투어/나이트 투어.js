const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const answer = solution(input);
  console.log(answer);
});

function solution(arr) {
  let cur = arr[0];
  let result = "Valid";
  const visited = Array.from({ length: 6 }, () => Array.from({ length: 6 }, () => false));
  visited[+cur.charAt(1) - 1][cur.charCodeAt(0) - 'A'.charCodeAt(0)] = true;

  for (let i = 1; i < arr.length; i++) {
    let next = arr[i];

    let xDiff = Math.abs(cur.charCodeAt(0) - next.charCodeAt(0));
    let yDiff = Math.abs(+cur.charAt(1) - next.charAt(1));

    if (Math.abs(xDiff - yDiff) !== 1 || (xDiff + yDiff) !== 3) {
      result = "Invalid";
      break;
    }

    if (visited[+next.charAt(1) - 1][next.charCodeAt(0) - 'A'.charCodeAt(0)]) {
      result = "Invalid";
      break;
    }

    visited[+next.charAt(1) - 1][next.charCodeAt(0) - 'A'.charCodeAt(0)] = true;
    cur = next;
  }

  let xDiff = Math.abs(cur.charCodeAt(0) - arr[0].charCodeAt(0));
  let yDiff = Math.abs(+cur.charAt(1) - arr[0].charAt(1));

  if (Math.abs(xDiff - yDiff) !== 1 || (xDiff + yDiff) !== 3) {
    result = "Invalid";
  }

  return result;
}