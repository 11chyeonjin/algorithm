function solution(enroll, referral, seller, amount) {
    const nameMap = new Map();
    
    for (let i = 0; i < enroll.length; i++) {
        nameMap.set(enroll[i], i);
    }
    
    const result = Array.from({ length: enroll.length }, () => 0);
    
    const graph = Array.from({ length: enroll.length }, () => -1); // 자식 -> 부모 역순으로 이동 가능
    
    for (let i = 0; i < referral.length; i++) {
        const cI = i;
        
        if (referral[i] === "-") {
            continue;
        }
        
        const pI = nameMap.get(referral[i]);
        
        graph[cI] = pI;
    }
    
    for (let i = 0; i < seller.length; i++) {
        let curI = nameMap.get(seller[i]);
        let curA = amount[i] * 100;
        
        while(true) {
            if (curA < 10) {
                result[curI] += curA;
                break;
            } else if (graph[curI] === -1) {
                result[curI] += curA - Math.floor(curA / 10);
                break;
            } else {
                result[curI] += curA - Math.floor(curA / 10);
                curI = graph[curI];
                curA = Math.floor(curA / 10);
            }
            
        }
    }
    
    return result;
}