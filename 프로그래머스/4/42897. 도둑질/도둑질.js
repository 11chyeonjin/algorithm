function solution(money) {
    const houseCnt = money.length;
    
    const dp0 = Array.from({ length: houseCnt }, () => 0); // 첫 집을 털지 않고 시작
    dp0[1] = money[1];
    
    const dp1 = Array.from({ length: houseCnt }, () => 0); // 첫 집을 털고 시작
    dp1[0] = money[0];
    dp1[1] = money[0];
    
    for (let i = 2; i < houseCnt - 1; i++) {
        dp0[i] = Math.max(dp0[i - 1], dp0[i - 2] + money[i]);
        dp1[i] = Math.max(dp1[i - 1], dp1[i - 2] + money[i]);
    }
    
    dp0[houseCnt - 1] = Math.max(dp0[houseCnt - 2], dp0[houseCnt - 3] + money[houseCnt - 1]);
    dp1[houseCnt - 1] = dp1[houseCnt - 2];
    
    return Math.max(dp0[houseCnt - 1], dp1[houseCnt - 1]);
}