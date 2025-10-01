function solution(arr) {
    function isSame(start, end) {
        const [startY, startX] = start;
        const [endY, endX] = end;
        
        const v = arr[startY][startX];
        for (let i = startY; i <= endY; i++) {
            for (let j = startX; j <= endX; j++) {
                if (arr[i][j] !== v) {
                    return -1;
                }
            }
        }
        
        return v;
    }
    
    const answer = [0, 0];
    
    function recur(start, end) {
        const rst = isSame(start, end);
        
        if (rst !== -1) {
            answer[rst]++;
            return;
        }
        
        const [startY, startX] = start;
        const [endY, endX] = end;
        const nextLen = Math.floor((endY - startY + 1) / 2);
        
        recur([startY, startX], [endY - nextLen, endX - nextLen]);
        recur([startY + nextLen, startX], [endY, endX - nextLen]);
        recur([startY, startX + nextLen], [endY - nextLen, endX]);
        recur([startY + nextLen, startX + nextLen], [endY, endX]);
    }
    
    recur([0, 0], [arr.length - 1, arr.length - 1]);
    
    return answer;
}