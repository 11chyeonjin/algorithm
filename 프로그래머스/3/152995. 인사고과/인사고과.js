function solution(scores) {
    // [근로태도점수, 동료평가점수]
    // scores[0] 가 완호의 점수
    // 인센제외 직원부터 제외하고, 석차를 확인하는 과정을 구현
    
    const user = scores[0];
    const userSum = user[0] + user[1];
    
    scores.sort((a, b) => {
        if (a[0] === b[0]) {
            return a[1] - b[1];
        } else {
            return b[0] - a[0];
        }
    });
    
    let answer = 0;
    
    let maxValue = -1;
    for (const sc of scores) {
        if (sc[0] > user[0] && sc[1] > user[1])
                return -1;
        if (sc[1] >= maxValue) {
            maxValue = sc[1];
            if (sc[0] + sc[1] > userSum) {
                answer++;
            }
        }
    }
    
    return answer + 1;
}