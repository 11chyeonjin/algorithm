const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(Number(line));
}).on('close', function() {
  const ans = solution(input[0], input.slice(1));
  console.log(ans);
  process.exit();
})

function solution(N, arr) {
  let total = 0

  for (let i = 0; i < arr.length; i++) {
    total += arr[i];
  }

  const dp = new Map();

  function dfs([prev, cur], index) {
    const key = `${prev}${cur}${arr.join('')}`;
    
    if (dp.has(key)) {
      return dp.get(key);
    }

    if (index === total - 1 ) {
      dp.set(key, 1);
      return 1;
    }

    let curCase = 0;

    for (let i = 0; i < arr.length; i++) {
      if (prev !== i && cur !== i) {
        if (arr[i] > 0) {
          arr[i]--;
          curCase += dfs([cur, i], index + 1);
          arr[i]++;
        }
      }
    }
    
    dp.set(key, curCase);
    return curCase;
  }

  const answer = dfs([-1, -1], -1);

  return answer;
}