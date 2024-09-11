function solution(begin, target, words) {
    let visited = Array(words.length).fill(false);
    
    let q = [[begin, 0]]; // 현재 단어, 변환 횟수
    let qFrontIndex = 0;
    
    while(qFrontIndex < q.length) {
        let [curWord, curCount] = q[qFrontIndex];
        
        if (curWord === target) {
            return curCount;
        }
        
        for (let i = 0; i < words.length; i++) {
            if (!visited[i] && convertFunc(curWord, words[i])) {
                q.push([words[i], curCount + 1]);
                visited[i] = true;
            }
        }
        
        qFrontIndex++;
    }
    
    return 0;
}

function convertFunc(firstWord, secondWord) {
    let count = 0;
    for (let i = 0; i < firstWord.length; i++) {
        if (firstWord[i] !== secondWord[i])
            count++;
        
        if (count > 1) {
            return false;
        }
    }
    
    return true;
}