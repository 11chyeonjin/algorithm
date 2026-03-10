function solution(n, money) {
    const dp = Array.from({ length: n + 1 }, () => 0);
    
    // dp[x] = dp[1] * dp[x - 1] + ... + dp[x / 2] + dp[x - x / 2]
    
    // dp[x] = dp[x - coin1] + dp[x - coin2] + ...
    
    dp[0] = 1;
    
    for (const coin of money) {
        for (let cur = coin; cur <= n; cur++) {
            dp[cur] = (dp[cur] + dp[cur - coin]) % 1000000007;
        }
    }
    
    return dp[n];
}