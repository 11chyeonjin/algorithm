function toNum(str) {
    return Number(str.slice(0, 2)) * 60 * 60 + Number(str.slice(3, 5)) * 60 + Number(str.slice(6));
}

function toDate(num) {
    let hour = String(Math.floor(num / 3600));
    num %= 3600;
    let min = String(Math.floor(num / 60));
    let sec = String(Math.floor(num %= 60));
    
    function format (str) {
        if (str.length === 1) {
            return '0' + str;
        }
        return str;
    }
    
    return `${format(hour)}:${format(min)}:${format(sec)}`;
}

function solution(play_time, adv_time, logs) {
    play_time = toNum(play_time);
    adv_time = toNum(adv_time);
    
    const arr = Array.from({ length: play_time + 1 }, () => 0);

    for (const t of logs) {
        const start = toNum(t.slice(0, 8));
        const end = toNum(t.slice(9));
        arr[start]++;
        arr[end]--;
    }
    
    for (let i = 1; i < arr.length; i++) {
        arr[i] += arr[i - 1];
    }
    
    for (let i = 1; i < arr.length; i++) {
        arr[i] += arr[i - 1];
    }
    
    let [maxV, answerTime] = [0, -1];

    const tmp_count = arr[adv_time - 1] - arr[0];
    if (maxV < tmp_count) {
        maxV = tmp_count;
        answerTime = 0;
    }
    
    for (let i = 1; i <= play_time - adv_time; i++) {
        const adv_answer_count = arr[i + adv_time - 1] - arr[i - 1];
        
        if (maxV < adv_answer_count) {
            maxV = adv_answer_count;
            answerTime = i;
        }
    }
         
    return toDate(answerTime);
}