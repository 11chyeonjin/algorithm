/**
 * 문제
  n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

  입력
  첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

  출력
  첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.

  3 15
  1
  5
  12
  ---
  3
 */
const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on("line", function(line) {
  input.push(line.split(' '));
}).on("close", function() {
  const [n, k] = [+input[0][0], +input[0][1]];
  const coins = input.slice(1).map((e => +e));
  const result = solution(n, k, coins);
  console.log(result);
  process.exit();
});

function solution(n, k, coins) {
  const coinSet = new Set();
  
  coins.forEach((el) => {
    coinSet.add(el);
  });

  const dp = Array.from({ length: 10001 }, () => Infinity);
  
  dp[0] = 0;
  for (let i = 1; i <= k; i++) {
    for (const curCoin of coinSet) {
      if (i - curCoin < 0)
        continue;
      dp[i] = Math.min(dp[i], dp[i - curCoin] + 1);
    }
  }

  if (dp[k] === Infinity)
    return -1;
  
  return dp[k];
}