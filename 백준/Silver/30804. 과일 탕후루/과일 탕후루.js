const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const ans = solution(input[0][0], input[1]);
  console.log(ans);
  process.exit();
});

function solution(N, arr) {
  let answer = 0;

  const map = new Map();

  let front = 0;
  for (let back = 0; back < arr.length; back++) {
    const cur = arr[back];
    map.set(cur, map.has(cur) ? map.get(cur) + 1 : 1);

    while(front < back && map.size > 2) {
      const tmp = arr[front];
      const tmpNum = map.get(tmp);
      
      if (tmpNum === 1) {
        map.delete(tmp);
      } else {
        map.set(tmp, tmpNum - 1);
      }

      front++;
    }

    answer = Math.max(answer, back - front + 1);
  }

  return answer;
}