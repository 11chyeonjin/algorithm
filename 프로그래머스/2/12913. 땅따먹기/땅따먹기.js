function solution(land) {
    const dp = Array.from({ length: land.length }, () => Array.from({ length: 4 }, () => -1));
    
    for (let i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];
    }
    
    for (let i = 1; i < land.length; i++) {
        for (let a = 0; a < 4; a++) {
            for (let b = 0; b < 4; b++) {
                if (a === b) {
                    continue;
                }
                dp[i][a] = Math.max(dp[i][a], land[i][a] + dp[i - 1][b]);
            }
        }
    }
    
    return Math.max(...dp[land.length - 1]);
}