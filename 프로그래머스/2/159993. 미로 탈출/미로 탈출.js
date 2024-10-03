function solution(maps) {
    // 통로로만 이동 가능, 레버를 당겨야 탈출 가능하며 레버를 당기지 않아도 출구를 통로로 이용가능
    // 이동시간은 1초로 동일
    // S -> L 를 위한 BFS, L -> E 를 위한 BFS
    
    const [m, n] = [maps.length, maps[0].length];
    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];
    
    function bfs(startChar, targetChar) {
        let startY, startX;
        for(let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (maps[i][j] === startChar) {
                    [startY, startX] = [i, j];
                }
            }
        }
        
        const visited = Array.from({length: m}, () => Array(n).fill(0));
        
        const q = [];
        q.push([startY, startX]);
        visited[startY][startX] = 1; // push와 동시에 visited 갱신 (boolean으로 이용하기 위해 시작지점부터 +1)
        
        let qFront = 0;
        while(q.length && qFront < q.length) {
            const [curY, curX] = q[qFront++];
            
            if (maps[curY][curX] === targetChar) {
                return visited[curY][curX];
            }
            
            for (let i = 0; i < 4; i++) {
                const [nextY, nextX] = [curY + dy[i], curX + dx[i]];
                if (0 <= nextY && nextY < m && 0 <= nextX && nextX < n) {
                    if (maps[nextY][nextX] !== 'X' && !visited[nextY][nextX]) {
                        q.push([nextY, nextX]);
                        visited[nextY][nextX] = visited[curY][curX] + 1;
                    }
                }
            }
        }
        return -1;
    }
    
    const stolResult = bfs('S', 'L');
    if (stolResult === -1)
        return -1;
    
    const ltoeResult = bfs('L', 'E');
    if (ltoeResult === -1)
        return -1;
    
    return stolResult + ltoeResult - 2;
}