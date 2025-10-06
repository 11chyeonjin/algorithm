function solution(maps) {
    const answer = [];
    
    const [N, M] = [maps.length, maps[0].length];
    
    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];
    
    const visited = Array.from({ length: N }, () => Array.from({ length: M } , () => false));
    
    function bfs(y, x) {
        const q = [[y, x]];
        let qi = 0;
        visited[y][x] = true;
        
        let rst = 0;
        
        while(qi < q.length) {
            const [curY, curX] = q[qi++];
            
            rst += +maps[curY][curX];
        
            for (let i = 0; i < 4; i++) {
                const [nextY, nextX] = [curY + dy[i], curX + dx[i]];

                if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
                    if (maps[nextY][nextX] !== 'X' && !visited[nextY][nextX]) {
                        q.push([nextY, nextX]);
                        visited[nextY][nextX] = true;
                    }
                }
            }
        }
        
        return rst;
    }
    
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (maps[i][j] !== 'X' && !visited[i][j]) {
                answer.push(bfs(i, j));
            }
        }
    }
    
    answer.sort((a, b) => a - b);
    
    if (answer.length === 0) {
        answer.push(-1);
    }
    
    return answer;
}