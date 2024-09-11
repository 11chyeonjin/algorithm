function solution(numbers, target) {
    let answer = 0;
    
    let q = [[0, 0]];
    
    let qFrontIndex = 0;
    
    while(q.length && qFrontIndex < q.length) {
        let [curIdx, curSum] = q[qFrontIndex];
        
        // 마지막 인덱스까지 탐색한 경우
        if (curIdx === numbers.length) {
            if (curSum === target) {
                answer++;
            }
        } else {
            // 다음 인덱스를 큐에 추가
            q.push([curIdx + 1, curSum + numbers[curIdx]]);
            q.push([curIdx + 1, curSum - numbers[curIdx]]);
        }
        
        qFrontIndex++;
    }
    
    return answer;
}