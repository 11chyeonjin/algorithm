function solution(board) {
    const N = board.length;
    
    const cost = Array.from({ length: N }, () => Array.from({ length: N }, () => Array.from({ length: 5 }, () => Infinity)));
    
    const q = [[0, 0, 4]];
    cost[0][0][4] = 0;
    let qi = 0;
    
    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];
    
    let answer = Infinity;
    
    while(qi < q.length) {
        const [y, x, dir] = q[qi++];
        const curCost = cost[y][x][dir];
        
        if (y === N - 1 && x === N - 1) {
            answer = Math.min(answer, curCost);
            continue;
        }
        
        for (let i = 0; i < 4; i++) {
            const [nextY, nextX] = [y + dy[i], x + dx[i]];
            
            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N) {
                if (!board[nextY][nextX]) {
                    let nextCost = curCost + 100;
                    if ((dir === 0 || dir === 1) && (i === 2 || i === 3)) {
                        nextCost += 500;
                    }
                    
                    if ((dir === 2 || dir === 3) && (i === 0 || i === 1)) {
                        nextCost += 500;
                    }
                    
                    if (cost[nextY][nextX][i] > nextCost) {
                        q.push([nextY, nextX, i]);
                        cost[nextY][nextX][i] = nextCost;
                    }
                }
            }
        }
    }
    
    return answer;
}