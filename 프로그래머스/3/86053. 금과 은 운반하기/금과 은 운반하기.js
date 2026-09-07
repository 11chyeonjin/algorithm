function solution(a, b, g, s, w, t) {
    const targetGs = a + b;
    
    const n = g.length;
    
    let left = 0;
    let right = 2000000000 * 1000000;
    
    let ans = -1;
    
    while (left <= right) {        
        const mid = Math.floor((left + right) / 2);
        
        let totalGs = 0;
        let [totalG, totalS] = [0, 0];
        
        for (let i = 0; i < n; i++) {
            let curR = 0;
            
            if (mid > t[i]) {
                curR++;
                curR += Math.floor((mid - t[i]) / (t[i] * 2));
            }
            
            totalGs += Math.min(curR * w[i], g[i] + s[i]);
            totalG += Math.min(curR * w[i], g[i]);
            totalS += Math.min(curR * w[i], s[i]);
        }
        
        if (totalGs >= targetGs && totalG >= a && totalS >= b) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return ans;
}