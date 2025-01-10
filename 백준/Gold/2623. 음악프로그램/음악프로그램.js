const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

readline.on("line", function(line) {
  input.push(line.split(' '));
}).on("close", function() {
  let N = +input[0][0]; // 가수의 수
  let M = +input[0][1]; // 보조 pd의 수
  let answerArr = solution(N, M, input.slice(1, M + 1).map(row => row.map(e => +e)).map(row => {
    row.splice(0, 1);
    return row;
  }));
  console.log(answerArr.join('\n'));
  process.exit();
})

function solution(N, M, singerArr) {
  const graph = Array.from({length: N + 1}, () => []); // 연결리스트, 각 원소는 후행 노드를 나타냄.
  const indegree = Array.from({length: N + 1}, () => 0); // 진입 차수
  
  singerArr.forEach((arr) => {
    for (let i = 0; i < arr.length - 1; i++) {
      if (graph[arr[i]].findIndex(e => e === arr[i - 1]) !== -1)
        continue;

      graph[arr[i]].push(arr[i + 1]);
      indegree[arr[i + 1]]++;
    }
  });

  let answer = [];
  let queue = [];
  let qFrontI = 0;

  for (let i = 1; i <= N ; i++) {
    if (indegree[i] === 0) {
      // 진입 차수가 0인 노드를 queue에 push
      queue.push(i);
    }
  }
  
  while(queue.length && qFrontI < queue.length) {
    let cur = queue[qFrontI];
    qFrontI++;

    answer.push(cur);

    for (let next of graph[cur]) {
      indegree[next]--;
      
      if (indegree[next] === 0) {
        queue.push(next);
      }
    }
  }

  if (answer.length !== N) {
    return answer = [ 0 ];
  }

  return answer;
}