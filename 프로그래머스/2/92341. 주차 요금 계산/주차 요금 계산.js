function solution(fees, records) {
    const [bt, bf, pt, pf] = fees;
    
    const rst = new Map();
    const parking = new Map();
    
    for (let r of records) {
        const [timeStr, car, oper] = r.split(' ');
        const [hh, mm] = timeStr.split(':').map(Number);
        const time = hh * 60 + mm;
        
        if (oper === "IN") {
            parking.set(car, time);
        } else {
            const tmpTime = time - parking.get(car);
            parking.delete(car);
            if (rst.has(car)) {
                rst.set(car, rst.get(car) + tmpTime);
            } else {
                rst.set(car, tmpTime);
            }
        }
    }
    
    const maxTime = 23 * 60 + 59;
    
    for (const [car, parkingTime] of parking) {
        const tmpTime = maxTime - parkingTime;
        if (rst.has(car)) {
            rst.set(car, rst.get(car) + tmpTime);
        } else {
            rst.set(car, tmpTime);
        }
    }
    
    const answer = [];
    for (const [car, time] of rst) {
        if (time <= bt) {
            answer.push([car, bf]);
        } else {
            answer.push([car, bf + Math.ceil((time - bt) / pt) * pf]);
        }
    }
    
    answer.sort((a, b) => {
        return a[0] - b[0];
    });
    
    return answer.map((r) => r[1]);
}