function solution(matrix_sizes) {
    const N = matrix_sizes.length;
    
    const dp = Array.from({ length: N }, () => Array.from({ length: N }, () => Infinity));

    for (let i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    for (let l = 2; l <= N; l++) {
        for (let i = 0; i <= N - l; i++) {
            const j = i + l - 1;
            
            for (let k = i; k < j; k++) {
                dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k+1][j] + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1]);
            }
        }
    }

    return dp[0][N - 1];
}