// 문제
// 그들은 불편함을 참지 못하고 수도관을 설치하여 거리 D(7 ≤ D ≤ 100,000)만큼 떨어진 곳의 강에서 물을 끌어오기로 했다.
// 근처의 인간 마을에서 P개(1 ≤ P ≤ 350)의 파이프를 매입했는데, 각각은 길이 Li와 용량 Ci로 나타낼 수 있다.
// (Li와 Ci는 모두 223보다 작거나 같은 양의 정수이다)

// 파이프들은 일렬로 이어서 수도관 하나로 만들 수 있으며, 이때 수도관의 용량은 그것을 이루는 파이프들의 용량 중 최솟값이 되고, 수도관의 길이는 파이프들 길이의 총합이다.

// 수도관을 한 개 만들어 총 길이가 정확히 D와 같게 할 때, 가능한 최대 수도관 용량을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 D와 P가 주어진다. 두 번째 줄부터 P개의 줄이 차례로 주어지고, 각 줄마다 Li와 Ci가 주어진다. 길이 합이 D가 되게 하는 수도관의 부분집합이 적어도 하나 존재한다.

// 출력
// 가능한 최대 수도관 용량을 첫째 줄에 출력한다.

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0], input.slice(1));
  console.log(ans);
  process.exit();
});

function solution([D, P], arr) {
  const dp = Array.from({ length: D + 1 }, () => -Infinity);
  dp[0] = Infinity;

  for (let i = 0; i < arr.length; i++) {
    const [curL, curC] = arr[i];

    for (let j = D; j >= curL; j--) {
      if (dp[j - curL] === -Infinity) {
        continue;
      }

      dp[j] = Math.max(dp[j], Math.min(dp[j - curL], curC));
    }
  }

  return dp[D];
}
