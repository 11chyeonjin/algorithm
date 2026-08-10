function solution(diffs, times, limit) {
    function solve(lev) {
        let rst = 0;
        
        for (let i = 0; i < diffs.length; i++) {
            if (diffs[i] <= lev) {
                rst += times[i];
            } else {
                rst += (diffs[i] - lev) * (times[i - 1] + times[i]) + times[i]; 
            }
        }
        
        return rst;
    }
    
    let left = 1;
    let right = 100000;
    
    while(left < right) {
        const mid = Math.floor((left + right) / 2);
        
        const rst = solve(mid);
        
        if (rst <= limit) {
            // 소요시간이 여유있을 경우
            right = mid;
        } else {
            // 제한시간을 초과할 경우
            left = mid + 1;
        }
    }
    
    return Math.floor((left + right) / 2);
}