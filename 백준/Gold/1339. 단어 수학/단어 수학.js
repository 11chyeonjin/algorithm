const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const ans = solution(input.slice(1));
  console.log(ans);
  process.exit();
})

function solution(arr) {
  const map = new Map();
  arr.forEach(w => {
    for (let i = w.length - 1; i >= 0; i--) {
      const curWeight = 10 ** (w.length - 1 - i);
      if (!map.has(w[i])) {
        map.set(w[i], curWeight);
      } else {
        map.set(w[i], curWeight + map.get(w[i]));
      }
    }
  })

  const tmp = [...map];
  tmp.sort((a, b) => b[1] - a[1]);
  
  let curN = 9;
  tmp.forEach(e => {
    map.set(e[0], curN);
    curN--;  
  })

  let answer = 0;

  arr.forEach(w => {
    for (let i = w.length - 1; i >= 0; i--) {
      const curWeight = 10 ** (w.length - 1 - i);
      answer += curWeight * map.get(w[i]);
    }
  })

  return answer;
}
