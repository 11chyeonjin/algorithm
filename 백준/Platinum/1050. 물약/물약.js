const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' '));
}).on('close', function() {
  const [N, M] = input[0].map(e => +e);
  const ingdMap = new Map();
  const strArr = [];
  for (let i = 1; i <= N; i++) {
    ingdMap.set(input[i][0], +input[i][1]);
  }
  for (let i = N + 1; i < N + 1 + M; i++) {
    strArr.push(input[i][0]);
  }
  const answer = solution(ingdMap, strArr);
  console.log(answer);
});

function solution(map, strArr) {
  let flag = true;
  while(flag) {
    flag = false;
    strArr.forEach((str) => {
      let rstFlag = true;
      const [rst, remains] = str.split('=');
      const ingdArr = remains.split('+');
      let sum = 0;
      for (const Ningd of ingdArr) {
        const [N, ingd] = [+Ningd[0], Ningd.slice(1)];
        if (!map.has(ingd)) {
          rstFlag = false;
          break;
        }
        sum += map.get(ingd) * N;
      }

      if (rstFlag) {
        if (map.has(rst)) {
          if (map.get(rst) > sum) {
            map.set(rst, sum);
            flag = true;
          }
        } else  {
          map.set(rst, sum);
          flag = true;
        }
      }
    });
  }

  if (!map.has("LOVE")) {
    return -1;
  } else {
    const result = map.get("LOVE");
    if (result > 1000000000) {
      return 1000000001;
    } else {
      return result;
    }
  }
}