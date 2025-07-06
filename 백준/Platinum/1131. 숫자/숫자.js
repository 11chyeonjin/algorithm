const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line.split(' '));
}).on('close', function() {
  const rst = solution(input[0].map(Number));
  console.log(rst);
  process.exit();
});

function solution([A, B, K]) {
  let answer = 0;
  const map = new Map(); // 사이클에서의 최소값 확인용 [num, target]
  const pow = Array.from({length:10}, (_, d) => d**K);
  function func(n) {
    let s = 0;
    while (n > 0) {
      s += pow[n % 10];
      n = Math.floor(n / 10);
    }
    return s;
  }

  for (let num = A; num <= B; num++) {
    if (map.has(num)) {
      answer += map.get(num);
      continue;
    }

    const set = new Set();

    let cur = num;

    let minValue = cur;
    while(true) {
      if (map.has(cur)) {
        // 이미 파악한 사이클 구성요소라면
        minValue = Math.min(minValue, map.get(cur));
        break;
      }

      if (set.has(cur)) {
        // 완전한 미확인 사이클임을 확인했다면
        const target = cur;
        let tmpCur = func(cur);
        const tmpArr = [ cur ];
        let tmpMinValue = cur;

        while(target != tmpCur) {
          tmpArr.push(tmpCur);
          tmpMinValue = Math.min(tmpMinValue, tmpCur);
          tmpCur = func(tmpCur);
        }

        tmpArr.forEach(e => {
          map.set(e, tmpMinValue);
        })

        minValue = Math.min(minValue, map.get(cur));
        
        break;
      } else {
        set.add(cur);
      }

      minValue = Math.min(minValue, cur);
      cur = func(cur);
    }

    answer += minValue;
  }

  return answer;
}
