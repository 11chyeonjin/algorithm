function solution(participant, completion) {
    const map = new Map();
    
    completion.forEach((el) => {
        if (!map.has(el)) {
            // 첫 등록이라면
            map.set(el, 1);
        } else {
            // 동명이인까지 등록이라면
            map.set(el, map.get(el) + 1);
        }
    });
    
    for (let i = 0; i < participant.length; i++) {
        if (!map.has(participant[i]))
            // 완주자 목록에 없다면
            return participant[i];
        else {
            // 완주자 목록에 있다면
            if (map.get(participant[i]) === 1) {
                // 남은 목록중 해당 이름이 유일하다면
                map.delete(participant[i]);
            } else {
                // 남은 목록중 해당 이름이 유일하지 않다면
                map.set(participant[i], map.get(participant[i]) - 1);
            }
        }
    }
    
    return null;
}