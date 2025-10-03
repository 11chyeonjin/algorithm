function solution(lines) {
    function toNum(str) {
        const [, endStr, timeStr] = str.split(' ');
        const [hh, mm, ss] = endStr.split(':');
        
        let end = Number(hh) * (60 ** 2) + Number(mm) * 60 + Number(ss);
        
        let time = Number(timeStr.slice(0, -1));
        
        time = (time - 0.001).toFixed(3);
        
        return [Number((end - time).toFixed(3)), end];
    }
    
    const startArr = [];
    const endArr = [];
    
    lines.forEach((l) => {
        const [start, end] = toNum(l);
        startArr.push(start);
        endArr.push(end);
    });
    
    endArr.sort((a, b) => a - b);
    
    let ei = 0;
    
    let curTask = 0;
    let curTime = 0;
    
    let maxTask = 0;
    
    for (let si = 0; si < startArr.length; si++) {
        const curTime = startArr[si];
        curTask++;

        while (ei < endArr.length && endArr[ei] < curTime) {
            curTask--;
            ei++;
        }

        let tmpTask = curTask;
        for (let sj = si + 1; sj < startArr.length; sj++) {
            if (startArr[sj] < curTime + 1) {
                tmpTask++;
            } else {
                break;
            }
        }
        maxTask = Math.max(maxTask, tmpTask);

        let endTime = endArr[ei];
        tmpTask = 0;
        for (let sj = 0; sj < startArr.length; sj++) {
            if (startArr[sj] < endTime + 1 && endArr[sj] >= endTime) {
                tmpTask++;
            }
        }
        maxTask = Math.max(maxTask, tmpTask);
    }
    
    return maxTask;
}