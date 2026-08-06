function solution(storage, requests) {
    const deleteSet = new Set();
    
    const arr = Array.from({ length: storage.length + 2 }, () => Array.from({ length: storage[0].length + 2 }, () => ' '));
    
    const dy = [ 0, 0, 1, -1 ];
    const dx = [ 1, -1, 0, 0 ];
    
    const storageArr = storage.forEach(s => {
        for (let i = 1; i <= storage.length; i++) {
            for (let j = 1; j <= storage[0].length; j++) {
                arr[i][j] = storage[i - 1][j - 1];
            }
        }
    });
    
    function allFunc(char) {
        if (deleteSet.has(char)) {
            return;
        }
        
        deleteSet.add(char);
        
        for (let i = 0; i < arr.length; i++) {
            for (let j = 0; j < arr[0].length; j++) {
                if (arr[i][j] === char) {
                    arr[i][j] = ' ';
                }
            }
        }
    }
    
    function avaFunc(char) {
        const visited = Array.from({ length: arr.length }, () => Array.from({ length: arr[0].length }, () => false));
        
        const q = [];
        let qi = 0;
        
        for (let j = 1; j <= storage[0].length; j++) {
            q.push([0, j]);
            q.push([storage.length + 1, j]);
        }
        
        for (let i = 1; i <= storage.length; i++) {
            q.push([i, 0]);
            q.push([i, storage[0].length + 1]);
        }
        
        const rstQ = [];
        
        while(qi < q.length) {
            const [cY, cX] = q[qi++];
            
            if (visited[cY][cX]) {
                continue;
            }
            
            visited[cY][cX] = true;
            
            if (arr[cY][cX] !== ' ') {
                if (arr[cY][cX] === char) {
                    rstQ.push([cY, cX]);
                }
                
                continue;
            }
            
            for (let i = 0; i < 4; i++) {
                const [nY, nX] = [cY + dy[i], cX + dx[i]];
                
                if (0 <= nY && nY < arr.length && 0 <= nX && nX < arr[0].length) {
                    if (!visited[nY][nX]) {
                        q.push([nY, nX]);
                    }
                }
            }
        }
        
        for (const [y, x] of rstQ) {
            arr[y][x] = ' ';
        }
    }
    
    for (const curR of requests) {
        if (curR.length === 2) {
            allFunc(curR[0]);
        } else {
            avaFunc(curR);
        }
    }
    
    let answer = 0;
    
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr[0].length; j++) {
            if (arr[i][j] !== ' ') {
                answer++;
            }
        }
    }
    
    return answer;
}
