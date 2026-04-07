function solution(game_board, table) {
    const [n, m] = [game_board.length, game_board[0].length]
    
    const visited = Array.from({ length: n }, () => Array.from({ length: m }, () => false));
    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];
    
    let pieces = [];
    
    function check(s, flag, targetBoard, visitArr, returnTarget) {
        const q = [s]
        let qi = 0;
        visitArr[s[0]][s[1]] = true;
        
        while(qi < q.length) {
            const [cY, cX] = q[qi++];
            
            for (let i = 0; i < 4; i++) {
                const nY = cY + dy[i];
                const nX = cX + dx[i];
                
                if (0 <= nY && nY < n && 0 <= nX & nX < m) {
                    if (!visitArr[nY][nX] && targetBoard[nY][nX] === flag) {
                        q.push([nY, nX]);
                        visitArr[nY][nX] = true;
                    }
                }
            }
        }
        
        let yMin = Infinity;
        let xMin = Infinity;
        q.forEach(([y, x]) => {
            yMin = Math.min(yMin, y);
            xMin = Math.min(xMin, x);
        });
        
        returnTarget.push(q.map(([y, x]) => {
            return [Math.max(0, y - yMin), Math.max(0, x - xMin)];
        }));
    }
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (!visited[i][j] && table[i][j]) {
                check([i, j], 1, table, visited, pieces);
            }
        }
    }
    
    pieces = pieces.map(pArr => {
        let yMax = -Infinity;
        let xMax = -Infinity;
        pArr.forEach(([y, x]) => {
            yMax = Math.max(yMax, y);
            xMax = Math.max(xMax, x);
        });
        
        const tmp = Array.from({ length: yMax + 1 }, () => Array.from({ length: xMax + 1 }, () => false));
        
        const rst = [];
        
        pArr.forEach(([y, x]) => {
            tmp[y][x] = true;
        })
        
        let line = "";
        for (let i = 0; i < tmp.length; i++) {
            for (let j = 0; j < tmp[0].length; j++) {
                if (!tmp[i][j]) {
                    line += "0";
                } else {
                    line += "1";
                }
            }
            line += "\n";
        }
        
        rst.push(line);
        line = "";
        
        for (let j = tmp[0].length - 1; j >= 0; j--) {
            for (let i = 0; i < tmp.length; i++) {
                if (!tmp[i][j]) {
                    line += "0";
                } else {
                    line += "1";
                }
            }
            line += "\n";
        }
        
        rst.push(line);
        line = "";
        
        for (let i = tmp.length - 1; i >= 0; i--) {
            for (let j = tmp[0].length - 1; j >= 0; j--) {
                if (!tmp[i][j]) {
                    line += "0";
                } else {
                    line += "1";
                }
            }
            line += "\n";
        }
        
        rst.push(line);
        line = "";
        
        for (let j = 0; j < tmp[0].length; j++) {
            for (let i = tmp.length - 1; i >= 0; i--) {
                if (!tmp[i][j]) {
                    line += "0";
                } else {
                    line += "1";
                }
            }
            line += "\n";
        }
        
        rst.push(line);
        
        return rst;
    })
    
    const boardVisited = Array.from({ length: n }, () => Array.from({ length: m }, () => false));
    
    let boardPieces = [];
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (!boardVisited[i][j] && game_board[i][j] === 0) {
                check([i, j], 0, game_board, boardVisited, boardPieces);
            }
        }
    }
    
    // console.log(pieces);
    
    boardPieces = boardPieces.map(pArr => {
        let yMax = -Infinity;
        let xMax = -Infinity;
        pArr.forEach(([y, x]) => {
            yMax = Math.max(yMax, y);
            xMax = Math.max(xMax, x);
        });
        
        const tmp = Array.from({ length: yMax + 1 }, () => Array.from({ length: xMax + 1 }, () => false));
        
        pArr.forEach(([y, x]) => {
            tmp[y][x] = true;
        })
        
        let line = "";
        for (let i = 0; i < tmp.length; i++) {
            for (let j = 0; j < tmp[0].length; j++) {
                if (tmp[i][j]) {
                    line += "1";
                } else {
                    line += "0";
                }
            }
            line += "\n";
        }
        
        return line;
    })
    
    // console.log(boardPieces);
    
    const usedCheck = Array.from({ length: pieces.length }, () => false);
    
    let answer = 0;
    
    for (const bp of boardPieces) {
        let flag = false;
        for (let i = 0; i < pieces.length; i++) {
            if (flag) {
                break;
            }
            
            if (usedCheck[i]) {
                continue;
            }
            
            for (const rp of pieces[i]) {
                if (bp === rp) {
                    flag = true;
                    usedCheck[i] = true;
                    
                    for (let j = 0; j < bp.length; j++) {
                        if (bp[j] === "1") {
                            answer++;
                        }
                    }
                    break;
                }
            }
        }
    }
                                  
    return answer;
}