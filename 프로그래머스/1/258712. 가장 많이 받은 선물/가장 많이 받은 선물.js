function solution(friends, gifts) {    
    const giftIdx = new Map();
    for (const n of friends) {
        giftIdx.set(n, 0);
    }
    
    const giftMap = new Map();
    for (const n of friends) {
        giftMap.set(n, new Map());
    }
    
    for (const g of gifts) {
        const [from, to] = g.split(' ');
        
        giftIdx.set(from, giftIdx.get(from) + 1);
        giftIdx.set(to, giftIdx.get(to) - 1);
        
        const gfMap = giftMap.get(from);
        
        if (gfMap.has(to)) {
            gfMap.set(to, gfMap.get(to) + 1);
        } else {
            gfMap.set(to, 1);
        }
    }
    
    const rstMap = new Map();
    for (const n of friends) {
        rstMap.set(n, 0);
    }
    
    for (let i = 0; i < friends.length; i++) {
        for (let j = i + 1; j < friends.length; j++) {
            const a = friends[i];
            const b = friends[j];
            
            const aTob = giftMap.get(a).get(b) ?? 0;
            const bToa = giftMap.get(b).get(a) ?? 0;
            
            if (aTob === bToa) {
                const aIdx = giftIdx.get(a);
                const bIdx = giftIdx.get(b);
                
                if (aIdx > bIdx) {
                    rstMap.set(a, rstMap.get(a) + 1);
                } else if (bIdx > aIdx) {
                    rstMap.set(b, rstMap.get(b) + 1);
                }
            } else if (aTob > bToa) {
                rstMap.set(a, rstMap.get(a) + 1);
            } else {
                rstMap.set(b, rstMap.get(b) + 1);
            }
        }
    }
    
    let result = 0;
    for (const [_, v] of rstMap) {
        result = Math.max(result, v);
    }
     
    return result;
}