function solution(babbling) {
    let answer = 0;
    
    const bab = ["aya", "ye", "woo", "ma"];
    
    for (let word of babbling) {
        const used = [false, false, false, false];
        
        while(!(used[0] && used[1] && used[2] && used[3])) {
            let flag = false;
            for (let i = 0; i < 4; i++) {
                if (!used[i]) {
                    if (word.indexOf(bab[i]) === 0) {
                        word = word.slice(bab[i].length);
                        used[i] = true;
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }
        
        if (word.length === 0) {
            answer++;
        }
    }
    
    return answer;
}