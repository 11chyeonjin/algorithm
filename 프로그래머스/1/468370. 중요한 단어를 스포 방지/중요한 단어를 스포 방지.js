function solution(message, spoiler_ranges) {
    function checkEdge(idx, flag) {        
        if (message[idx] === ' ') {
            return flag ? idx + 1 : idx - 1;
        }
        
        if (idx === 0 || idx === message.length - 1) {
            return idx;
        }
        
        return checkEdge(flag ? idx - 1 : idx + 1, flag);
    }
    
    const real_ranges = [];
    
    let curMax = -1;
    
    for (let [start, end] of spoiler_ranges) {
        const front = checkEdge(start, true);
        const back = checkEdge(end, false);
        
        if (curMax > front) {
            real_ranges[real_ranges.length - 1][1] = back;
        } else {
            real_ranges.push([front, back]);
        }
        
        curMax = back;
    }
    
    const spoWord = [];
    
    for (const [start, end] of real_ranges) {
        spoWord.push(...message.slice(start, end + 1).split(' '));
    }
    
    const allMap = new Map();
    
    for (const word of message.split(' ')) {
        allMap.has(word) ? allMap.set(word, allMap.get(word) + 1) : allMap.set(word, 1);
    }
    
    const spoMap = new Map();
    
    for (const word of spoWord) {
        spoMap.has(word) ? spoMap.set(word, spoMap.get(word) + 1) : spoMap.set(word, 1);
    }
    
    let answer = 0;
    
    for (const [word, cnt] of spoMap) {
        if (allMap.get(word) === cnt) {
            answer++;
        }
    }
    
    return answer;
}