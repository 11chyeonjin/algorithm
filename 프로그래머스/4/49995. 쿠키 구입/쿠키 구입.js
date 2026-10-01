function solution(cookie) {
    let ans = 0;
    
    let bb = cookie[0];
    for (let bLI = 1; bLI < cookie.length; bLI++) {
        bb += cookie[bLI];
        let b = bb;
        
        let a = 0;
        let aFrontI = 0;
        for (let i = 0; i < bLI; i++) {
            a += cookie[i];
            b -= cookie[i];
            
            while (a > b) {
                a -= cookie[aFrontI++];
            }
            
            if (a === b) {
                ans = Math.max(ans, a); 
                break;
            }
        }
    }
    
    return ans;
}