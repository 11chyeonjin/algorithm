function solution(board) {
    const [n, m] = [board.length, board[0].length];
    
    let goal = [];
    let robot = [];
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (board[i][j] === 'G') {
                goal = [i, j];
                continue;
            }
            
            if (board[i][j] === 'R') {
                robot = [i, j];
            }
        }
    }
    
    const visited = Array.from({ length: n }, () => Array.from({ length: m }, () => 0)); // cost(+1)로 계산
    const q = [robot];
    let qi = 0;
    visited[robot[0]][robot[1]] = 1;
    
    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];
    
    while(qi < q.length) {
        const [curY, curX] = q[qi++];
        
        if (curY === goal[0] && curX === goal[1]) {
            return visited[curY][curX] - 1;
        }
        
        for (let i = 0; i < 4; i++) {
            let [nY, nX] = [curY, curX];
            
            while(true) {
                nY += dy[i];
                nX += dx[i];
                
                if (0 > nY || nY >= n || 0 > nX || nX >= m) {
                    nY -= dy[i];
                    nX -= dx[i];
                    break;
                }
                
                if (board[nY][nX] === 'D') {
                    nY -= dy[i];
                    nX -= dx[i];
                    break;
                }
            }
            
            if (nY === curY && nX === curX) {
                // 이동할 수 없는 방향
                continue;
            }
            
            if (!visited[nY][nX]) {
                q.push([nY, nX]);
                visited[nY][nX] = visited[curY][curX] + 1;
            }
        }
    }
    
    return -1;
}