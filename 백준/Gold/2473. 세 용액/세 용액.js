const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const ans = solution(input[0][0], input.slice(1)[0]);
  console.log(ans.join(' '));
  process.exit();
})

function solution(N, arr) {
  let minV = Infinity;
  const rstArr = [-1, -1, -1];

  arr.sort((a, b) => a - b);
  
  for (let i = 0; i < N; i++) {
    let left = i + 1;
    let right = N - 1;
    
    while(left < right) {
      const cur = arr[i] + arr[left] + arr[right];
      if (minV > Math.abs(cur)) {
        minV = Math.abs(cur);
        rstArr[0] = i;
        rstArr[1] = left;
        rstArr[2] = right;
      }

      if (cur > 0) {
        right--;
      } else {
        left++;
      }
    }
  }

  return rstArr.map(e => arr[e]);
}
