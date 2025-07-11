const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const rst = solution(input[1], input[2][0]);
  console.log(rst.join(' '));
  process.exit();
})

function solution(arr, S) {
  let start = 0;
  while(S > 0 && start < arr.length - 1) {
    const limit = Math.min(start + S, arr.length - 1);
    // console.log(start, limit);
    let [maxI, maxV] = [-1, arr[start]];
    for (let i = start + 1; i <= limit; i++) {
      if (maxV < arr[i]) {
        // 교체 후보가 된다면
        [maxI, maxV] = [i, arr[i]];
      }
    }

    if (maxI !== -1) {
      // 후보가 있다면
      // console.log(arr[start], maxV);
      for (let i = maxI; i > start; i--) {
        [arr[i], arr[i - 1]] = [arr[i - 1], arr[i]];
      }
      S -= maxI - start;
    }

    start++;
  }

  return arr;
}