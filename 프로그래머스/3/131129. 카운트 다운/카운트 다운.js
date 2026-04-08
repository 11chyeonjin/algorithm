function solution(target) {
    const map = new Map();
    for (let i = 1; i <= 20; i++) {
        map.set(i * 2, false);
        map.set(i * 3, false);
    }
    map.set(50, true);
    for (let i = 1; i <= 20; i++) {
        map.set(i, true);
    }
    
    const dp = Array.from({ length: target + 1 }, () => [Infinity, -Infinity]);
    
    for (const [s, f] of map) {
        if (s > target) {
            continue;
        }
        
        dp[s] = [1, (f ? 1 : 0)];
    }
    
    for (let i = 1; i <= target; i++) {
        for (const [s, f] of map) {
            if (i - s > 0) {
                if (dp[i][0] > dp[i - s][0] + 1) {
                    dp[i] = [dp[i - s][0] + 1, dp[i - s][1] + (f ? 1 : 0)];
                    continue;
                }
                
                if ((dp[i][0] === dp[i - s][0] + 1) && (dp[i][1] < (dp[i - s][1] + (f ? 1 : 0)))) {
                    dp[i][1] = dp[i - s][1] + (f ? 1 : 0);
                    continue;
                }
            }
        }
    }
    
    return dp[target];
}