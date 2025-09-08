function solution(board, r, c) {
    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];

    const remainCard = new Set();
    for (let i = 0; i < 4; i++) {
        for (let j = 0; j < 4; j++) {
            if (board[i][j] !== 0) {
                remainCard.add(board[i][j]);
            }
        }
    }

    let answer = Infinity;

    function bfs(startY, startX, endY, endX, curBoard) {
        const visited = Array.from({ length : 4 }, () => Array.from({ length: 4 }, () => false));
        const q = [[startY, startX, 0]];
        let qI = 0;
        visited[startY][startX] = true;

        while (qI < q.length) {
            const [y, x, dist] = q[qI++];
            
            if (y === endY && x === endX) {
                return dist;
            }

            for (let i = 0; i < 4; i++) {
                // 이동
                let ny = y + dy[i];
                let nx = x + dx[i];
                if (0 <= ny && ny <4 && 0 <= nx && nx < 4 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push([ny, nx, dist + 1]);
                }

                // Ctrl 이동
                [ny, nx] = [y, x];
                while (0 <= ny + dy[i] && ny + dy[i] < 4 && 0 <= nx+dx[i] && nx+dx[i] < 4) {
                    ny += dy[i];
                    nx += dx[i];
                    if (curBoard[ny][nx] !== 0) break;
                }
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push([ny, nx, dist + 1]);
                }
            }
        }
        return Infinity;
    }

    function dfs(curY, curX, curRemainCard, curBoard, curAnswer) {
        if (curRemainCard.size === 0) {
            answer = Math.min(answer, curAnswer);
            return;
        }

        // 남은 카드 순서대로 선택
        for (const card of [...curRemainCard]) {
            // 해당 카드 두 좌표 찾기
            
            const targets = [];
            for (let i = 0; i < 4; i++) {
                for (let j = 0; j < 4; j++) {
                    if (curBoard[i][j] === card) {
                        targets.push([i,j]);
                    }
                }
            }
            const [p1, p2] = targets;

            for (const [first, second] of [[p1,p2],[p2,p1]]) {
                const move1 = bfs(curY, curX, first[0], first[1], curBoard) + 1;
                const move2 = bfs(first[0], first[1], second[0], second[1], curBoard) + 1;

                const newBoard = curBoard.map(row => [...row]);
                newBoard[first[0]][first[1]] = 0;
                newBoard[second[0]][second[1]] = 0;

                const nextRemain = new Set(curRemainCard);
                nextRemain.delete(card);

                dfs(second[0], second[1], nextRemain, newBoard, curAnswer + move1 + move2);
            }
        }
    }

    dfs(r, c, remainCard, board, 0);
    return answer;
}