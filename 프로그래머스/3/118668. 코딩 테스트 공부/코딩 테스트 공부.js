function solution(alp, cop, problems) {
    let targetA = 0;
    let targetC = 0;

    for (const [aReq, cReq] of problems) {
        targetA = Math.max(targetA, aReq);
        targetC = Math.max(targetC, cReq);
    }

    // 이미 목표를 초과한 능력은 목표치로 압축
    alp = Math.min(alp, targetA);
    cop = Math.min(cop, targetC);

    const dp = Array.from(
        { length: targetA + 1 },
        () => Array(targetC + 1).fill(Infinity)
    );

    dp[alp][cop] = 0;

    for (let a = alp; a <= targetA; a++) {
        for (let c = cop; c <= targetC; c++) {
            if (dp[a][c] === Infinity) {
                continue;
            }

            // 알고력 공부
            if (a < targetA) {
                dp[a + 1][c] = Math.min(
                    dp[a + 1][c],
                    dp[a][c] + 1
                );
            }

            // 코딩력 공부
            if (c < targetC) {
                dp[a][c + 1] = Math.min(
                    dp[a][c + 1],
                    dp[a][c] + 1
                );
            }

            // 현재 능력으로 풀 수 있는 문제
            for (const [aReq, cReq, aRwd, cRwd, cost] of problems) {
                if (a < aReq || c < cReq) {
                    continue;
                }

                const nextA = Math.min(targetA, a + aRwd);
                const nextC = Math.min(targetC, c + cRwd);

                dp[nextA][nextC] = Math.min(
                    dp[nextA][nextC],
                    dp[a][c] + cost
                );
            }
        }
    }

    return dp[targetA][targetC];
}