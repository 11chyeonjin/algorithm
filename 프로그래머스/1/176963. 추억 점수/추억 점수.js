function solution(name, yearning, photo) {
    const map = new Map();
    
    for (let i = 0; i < name.length; i++) {
        map.set(name[i], yearning[i]);
    }
    
    const answer = [];
    
    photo.forEach((row) => {
        let rst = 0;
        row.forEach(p => {
            if (map.has(p)) {
                rst += map.get(p);
            }
        })
        answer.push(rst);
    })
    
    return answer;
}