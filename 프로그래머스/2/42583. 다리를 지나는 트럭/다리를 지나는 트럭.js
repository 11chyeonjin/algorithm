function solution(bridge_length, weight, truck_weights) {
    let time = 0;
    const stack = Array.from({ length: bridge_length }, () => 0);
    
    let curW = 0;
    let nTruckI = 0;
    
    while(nTruckI < truck_weights.length || curW > 0) {
        time++;
        
        const curTruckW = stack.shift();
        curW -= curTruckW;
        
        if (nTruckI < truck_weights.length) {
            const nTruckW = truck_weights[nTruckI];

            if (curW + nTruckW <= weight) {
                stack.push(nTruckW);
                curW += nTruckW;
                nTruckI++;
            } else {
                stack.push(0);
            }
        } else {
            stack.push(0);
        }
    }
    
    return time;
}