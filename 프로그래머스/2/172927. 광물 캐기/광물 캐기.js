function solution(picks, minerals) {
    const dp = Array.from({ length: Math.ceil(minerals.length / 5) }, () =>
                          Array.from({ length: picks[0] + 1 }, () => 
                                     Array.from({ length : picks[1] + 1 }, () =>
                                                Array.from({ length: picks[2] + 1 }, () => Infinity)
    )));
    
    minerals = minerals.map(e => e[0]);
    
    function calc(tool, start) {
        let rst = 0;
        
        for (let i = start; i < Math.min(start + 5, minerals.length); i++) {
            if (tool === "d") {
                rst++;
                continue;
            }
            
            const curM = minerals[i];
            
            if (tool === "i") {
                if (curM === "d") {
                    rst += 5;
                } else {
                    rst++;
                }
                continue;
            }
            
            if (tool === "s") {
                if (curM === "d") {
                    rst += 25;
                } else if (curM === "i") {
                    rst += 5;
                } else {
                    rst++;
                }
                continue;
            }
        }
        
        return rst;
    }
    
    if (picks[0] > 0) {
        dp[0][picks[0] - 1][picks[1]][picks[2]] = calc("d", 0);
    }
    
    if (picks[1] > 0) {
        dp[0][picks[0]][picks[1] - 1][picks[2]] = calc("i", 0);
    }
    
    if (picks[2] > 0) {
        dp[0][picks[0]][picks[1]][picks[2] - 1] = calc("s", 0);
    }
    
    for (let i = 1; i < Math.ceil(minerals.length / 5); i++) {
        for (let dd = picks[0]; dd >= 0; dd--) {
            for (let ii = picks[1]; ii >= 0; ii--) {
                for (let ss = picks[2]; ss >= 0; ss--) {
                    const prev = dp[i - 1][dd][ii][ss];
                    
                    if (prev === Infinity) {
                        continue;
                    }
                    
                    if (dd > 0) {
                        dp[i][dd - 1][ii][ss] = Math.min(dp[i][dd - 1][ii][ss], prev + calc('d', i * 5));
                    }
                    
                    if (ii > 0) {
                        dp[i][dd][ii - 1][ss] = Math.min(dp[i][dd][ii - 1][ss], prev + calc('i', i * 5));
                    }
                    
                    if (ss > 0) {
                        dp[i][dd][ii][ss - 1] = Math.min(dp[i][dd][ii][ss - 1], prev + calc('s', i * 5));
                    }
                }
            }
        }
    }
    
    let flag = true;
    let answer = Infinity;
    
    for (let i = Math.ceil(minerals.length / 5) - 1; i >= 0; i--) {
        if (!flag) {
            break;
        }
        
        for (let dd = picks[0]; dd >= 0; dd--) {
            for (let ii = picks[1]; ii >= 0; ii--) {
                for (let ss = picks[2]; ss >= 0; ss--) {
                    const cur = dp[i][dd][ii][ss];
                    
                    if (cur !== Infinity) {
                        flag = false;
                    }
                    
                    answer = Math.min(answer, cur);
                }
            }
        }
    }
    
    return answer;
}