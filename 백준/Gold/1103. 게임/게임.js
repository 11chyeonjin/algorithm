const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const arr = solution(input[0].split(' ').map(Number), input.slice(1));
  console.log(arr);
  process.exit();
})

const dy = [ 0, 0, 1, -1 ];
const dx = [ 1, -1, 0, 0 ];


function solution([N, M], arr) {
  const board = arr.map(r => r.split('').map(e => e === 'H' ? -1 : Number(e)));
  const visited = Array.from({ length: N }, () => Array.from({ length: M }, () => false));
  const dp = Array.from({ length: N }, () => Array(M).fill(0));
  let flag = false;

  function dfs(curY, curX) {
    if (flag) {
      return 0;
    }

    if (dp[curY][curX]) {
      return dp[curY][curX];
    }

    const curNum = board[curY][curX];
    let curMaxAns = 0;
    
    let nextY, nextX;
    for (let i = 0; i < 4; i++) {
      [nextY, nextX] = [curY + dy[i] * curNum, curX + dx[i] * curNum];
      
      if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
        if (board[nextY][nextX] !== -1) {
          if (visited[nextY][nextX]) {
            flag = true;
            break;
          } else {
            visited[nextY][nextX] = true;
            curMaxAns = Math.max(curMaxAns, dfs(nextY, nextX));
            visited[nextY][nextX] = false;
          }
        }
      }
    }

    dp[curY][curX] = curMaxAns + 1;
    return dp[curY][curX];
  }

  visited[0][0] = true;

  const answer = dfs(0, 0);

  if (flag)
    return -1;

  return answer;
}