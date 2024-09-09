function solution(maps) {
    // 목표 지점까지의 최소 거리 => 너비 우선 탐색인 bfs 해법이 유력
    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];
    
    const N = maps.length;
    const M = maps[0].length;
    
    const visited = new Array(N).fill().map(() => new Array(M).fill(0));
    
    let q = [[0, 0]];
    visited[0][0] = 1;
    
    while(q.length) {
        let [curY, curX] = q.shift();
        
        if (curY === N - 1 && curX === M - 1)
            return visited[curY][curX];
        
        for (let i = 0; i < 4; i++) {
            let nextY = curY + dy[i];
            let nextX = curX + dx[i];
            
            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
                if (maps[nextY][nextX] && !visited[nextY][nextX]) {
                    q.push([nextY, nextX]);
                    visited[nextY][nextX] = visited[curY][curX] + 1;
                }
            }
        }
    }
    
    if (visited[N - 1][M - 1] === 0)
        return -1;
    else
        return visited[N - 1][M - 1];
}