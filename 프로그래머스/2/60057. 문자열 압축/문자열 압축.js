function solution(s) {
    function compare(str1, str2) {
        if (str1.length !== str2.length) {
            return false;
        }
        
        for (let i = 0; i < str1.length; i++) {
            if (str1[i] !== str2[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    function func(len) {
        let rst = 0;
        
        let prev = s.slice(0, len);
        let stack = 0;
        for (let i = len; i < s.length; i += len)  {
            const cur = s.slice(i, i + len);
            
            if (compare(prev, cur)) {
                // 이전 문자와 동일
                stack++;
            } else {
                // 이전 문자와 상이
                if (stack > 0) {
                    rst += len + String(stack + 1).length;
                    stack = 0;
                } else {
                    rst += prev.length;
                }
                prev = cur;
            }
        }
        
        if (stack > 0) {
            rst += len + String(stack + 1).length;
            stack = 0;
        } else {
            rst += prev.length;
        }
        
        return rst;
    }
    
    let answer = s.length;
    
    for (let l = 1; l <= Math.trunc(s.length / 2); l++) {
        answer = Math.min(answer, func(l));
    }
    
    return answer;
}