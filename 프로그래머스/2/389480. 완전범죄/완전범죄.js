function solution(info, n, m) {
    const dp = Array.from({ length: info.length + 1 }, () => Array.from({ length: n }, () => Array.from({ length: m }, () => false)));
    
    dp[0][0][0] = true;
    
    for (let i = 1; i <= info.length; i++) {
        const [infoA, infoB] = info[i - 1];
        
        for (let a = 0; a < n; a++) {
            for (let b = 0; b < m; b++) {
                if (a - infoA >= 0 && dp[i - 1][a - infoA][b]) {
                    dp[i][a][b] = true;
                }
                
                if (b - infoB >= 0 && dp[i - 1][a][b - infoB]) {
                    dp[i][a][b] = true;
                }
            }
        }
    }
    
    for (let a = 0; a < n; a++) {
        for (let b = m; b >= 0; b--) {
            if (dp[info.length][a][b]) {
                return a;
            }
        }
    }
    
    return -1;
}