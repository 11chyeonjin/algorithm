function solution(n, times) {
    times.sort((a, b) => {
        return a - b;
    });
    
    let left = 0;
    let right = times[times.length - 1] * n; // 최대 소요 시간
    let answer = Infinity;
    
    while(left <= right) {
        let mid = Math.floor((left + right) / 2);
        
        let cnt = 0;
        times.forEach((time) => {
            cnt += Math.floor(mid / time);
        });
        
        if (cnt >= n) {
            answer = Math.min(answer, mid)
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}