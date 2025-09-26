function solution(distance, rocks, n) {
    let answer = 0;
    
    rocks.push(0);
    rocks.push(distance);
    rocks.sort((a, b) => a - b);
    
    let left = 0;
    let right = distance;
    
    while (left <= right) {
        const mid = Math.floor((left + right) / 2); // 최솟값 검증을 해야하는 대상값
        let remove = 0;
        let prev = 0;
        
        for (let i = 1; i < rocks.length; i++) {
            if (remove > n) {
                break;
            }
            
            if (rocks[i] - prev < mid) {
                remove++;
            } else {
                prev = rocks[i];
            }
        }
        
        if (remove <= n) {
            // 조건 만족한 경우에만 answer 갱신
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}