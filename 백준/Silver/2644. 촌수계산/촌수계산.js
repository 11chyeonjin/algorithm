/* 
  문제
  우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한 문화를 가지고 있다. 이러한 촌수는 다음과 같은 방식으로 계산된다. 
  기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산한다. 
  예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.
  여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.

  입력
  사람들은 1, 2, 3, …, n (1 ≤ n ≤ 100)의 연속된 번호로 각각 표시된다. 
  입력 파일의 첫째 줄에는 전체 사람의 수 n이 주어지고, 둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다. 
  그리고 셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다. 넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다. 
  이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.

  각 사람의 부모는 최대 한 명만 주어진다.

  출력
  입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다. 이때에는 -1을 출력해야 한다.

  예제 입력 1 
  9
  7 3
  7
  1 2
  1 3
  2 7
  2 8
  2 9
  4 5
  4 6
*/

const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline
  .on("line", function (line) {
    input.push(line.split(" "));
  })
  .on("close", function () {
    const n = +input[0][0];
    const targetPair = input[1].map((e) => +e);
    const m = +input[2][0];
    const arr = input.slice(3).map((r) => r.map((e) => +e));
    const answer = solution(n, targetPair, arr);
    console.log(answer);
    process.exit();
  });

function solution(n, targetPair, arr) {
  const graph = Array.from({ length: n + 1 }, () => []);

  arr.forEach(([p, c]) => {
    graph[p].push(c);
    graph[c].push(p);
  });

  const queue = [];
  const visited = Array.from({ length: n + 1 }, () => false);
  const calcul = Array.from({ length: n + 1 }, () => -1);
  queue.push(targetPair[0]);
  let qF = 0;
  visited[targetPair[0]] = true;
  calcul[targetPair[0]] = 0;

  while (qF < queue.length) {
    const cur = queue[qF];
    const curCal = calcul[cur];
    qF++;

    if (cur === targetPair[1]) {
      break;
    }

    for (const next of graph[cur]) {
      if (!visited[next]) {
        queue.push(next);
        visited[next] = true;
        calcul[next] = curCal + 1;
      }
    }
  }

  return calcul[targetPair[1]];
}