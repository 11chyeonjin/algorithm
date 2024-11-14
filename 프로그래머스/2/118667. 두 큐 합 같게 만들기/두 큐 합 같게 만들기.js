function solution(queue1, queue2) {
    
    function sum(arr) {
        let total = 0;
        arr.forEach((num) => {
            total += num;
        });
        return total;
    }
    
    let totalSize = queue1.length + queue2.length;
    
    let curQ1Total = sum(queue1);
    let curQ2Total = sum(queue2);
    let curQ1Front = 0; // Q1 front Idx
    let curQ2Front = 0; // Q2 front Idx
    
    let rst = 0;
    
    while(curQ1Front < queue1.length && curQ2Front < queue2.length) {
        if (curQ1Total > curQ2Total) {
            // Q1이 크다면,
            queue2.push(queue1[curQ1Front]);
            curQ2Total += queue1[curQ1Front];
            curQ1Total -= queue1[curQ1Front];
            curQ1Front++;
        } else if (curQ1Total < curQ2Total) {
            // Q2가 크다면,
            queue1.push(queue2[curQ2Front]);
            curQ1Total += queue2[curQ2Front];
            curQ2Total -= queue2[curQ2Front];
            curQ2Front++;
        } else {
            // 동일할 때
            return rst;
        }
        
        rst++;
        if (rst > totalSize * 2)
            return -1;
    }
    
    return -1;
}