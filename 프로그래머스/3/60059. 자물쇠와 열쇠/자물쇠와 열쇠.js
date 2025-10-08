function solution(key, lock) {
    const [N, M] = [lock.length, key.length];

    const rlockSize = N + 2 * M - 2;
    const rlock = Array.from({ length: rlockSize }, () => Array.from({ length: rlockSize }, () => 0));
    
    for (let i = M - 1; i <= rlockSize - M; i++) {
        for (let j = M - 1; j <= rlockSize - M; j++) {
            rlock[i][j] = lock[i - M + 1][j - M + 1];
        }
    }
    
    function rotate(key) {
        const rst = Array.from({ length: M }, () => Array.from({ length: M }, () => 0));
        for (let i = 0; i < M; i++) {
          for (let j = 0; j < M; j++) {
            rst[j][M - 1 - i] = key[i][j];
          }
        }
        return rst;
      }
    
    let rotated = key;
    for (let r = 0; r < 4; r++) {
        for (let i = 0; i <= rlockSize - M; i++) {
            for (let j = 0; j <= rlockSize - M; j++) {
                const tmp = rlock.map(row => [...row]);
                
                for (let y = 0; y < M; y++) {
                    for (let x = 0; x < M; x++) {
                        tmp[i + y][j + x] += rotated[y][x];
                    }
                }
                
                let flag = true;
                
                for (let y = 0; y < N; y++) {
                    for (let x = 0; x < N; x++) {
                        if (tmp[M - 1 + y][M - 1 + x] !== 1) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) 
                        break;
                }
                
                if (flag) 
                    return true;
            }
        }
        rotated = rotate(rotated);
    }
    
    return false;
}