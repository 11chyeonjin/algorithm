function solution(N, stages) {
    const stage_fail_cnt = Array.from({ length: N + 1 }, () => 0);
    const stage_cnt = Array.from({ length: N + 1 }, () => 0);
    
    stages.forEach((s) => {
        if (s !== N + 1) {
            stage_fail_cnt[s]++;
            stage_cnt[s]++;
        } else {
            stage_cnt[s - 1]++;
        }
    })
    
    let answer = Array.from({ length: N }, () => []);
    
    for (let i = N; i > 1; i--) {
        stage_cnt[i - 1] += stage_cnt[i];
    }
    
    for (let i = 1; i <= N; i++) {
        answer[i - 1][0] = i;
        
        if (stage_cnt === 0) {
            answer[i - 1][1] = 0;
            continue;
        }
        
        answer[i - 1][1] = stage_fail_cnt[i] / stage_cnt[i];
    }
    
    answer = answer.sort((a, b) => b[1] - a[1]).map(e => e[0]);
    
    return answer;
}