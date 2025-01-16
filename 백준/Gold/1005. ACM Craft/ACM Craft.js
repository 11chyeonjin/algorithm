const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

readline.on("line", function(line) {
  input.push(line.split(' '));
}).on("close", function() {
  let T = input[0][0];
  let answer = [];
  let idx = 0;
  for (let i = 0; i < T; i++) {
    let [N, K] = [+input[++idx][0], +input[idx++][1]];
    let costs = input[idx++].map(e => +e);
    let orders = input.slice(idx, idx + K).map(row => row.map(e => +e));
    idx += K;
    let target = +input[idx];
    let rst = solution(N, K, costs, orders, target);
    answer.push(rst);
  }

  console.log(answer.join('\n'));
  process.exit();
})

function solution(N, K, costs, orders, target) {
  costs.unshift(0);
  
  const graph = Array.from({ length: N + 1 }, () => []);
  const indegree = Array.from({ length: N + 1 }, () => 0);
  orders.forEach((e) => {
    let [pre, post] = [e[0], e[1]];
    graph[pre].push(post);
    indegree[post]++;
  });
  const dp = [...costs];
  
  const queue = [];
  let qFront = 0;
  for(let i = 1; i <= N; i++) {
    if (indegree[i] === 0) {
      queue.push(i);
    }
  }
  
  while(qFront < queue.length) {
    const cur = queue[qFront];
    qFront++;
    
    for (let i = 0; i < graph[cur].length; i++) {
      const next = graph[cur][i];
      
      if (dp[cur] + costs[next] > dp[next]) {
        dp[next] = dp[cur] + costs[next];
      }
      
      indegree[next]--;
      
      if (indegree[next] === 0) {
        queue.push(next);
      }
    }
  }

  return dp[target];
}