function solution(id_list, report, k) {
    // 이용자의 id가 담긴 id_list
    // 신고당한 이용자의 id 배열 report
    // 정지 기준 k
    // 어떤 유저의 동일한 유저에 대한 신고 횟수는 1회
    
    const id_map = new Map();
    id_list.forEach((id, i) => {
        id_map.set(id, i);
    });
    
    const report_cnt = Array.from({ length: id_list.length }, () => 0);
    
    const report_set = Array.from({ length: id_list.length }, () => new Set());
                                    
    report.forEach((r) => {
        const [from_id, to_id] = r.split(' ');
        const [from, to] = [id_map.get(from_id), id_map.get(to_id)];
        
        if (!report_set[from].has(to)) {
            report_set[from].add(to);
            report_cnt[to]++;
        }
    })
    
    const blacklist = [];
    
    report_cnt.forEach((r_cnt, i) => {
        if (r_cnt >= k) {
            blacklist.push(i);
        }
    })

    const answer = Array.from({ length: id_list.length }, () => 0);
    
    for (let i = 0; i < report_set.length; i++) {
        for (let j = 0; j < blacklist.length; j++) {
            if (report_set[i].has(blacklist[j])) {
                answer[i]++;
            }
        }
    }
    
    return answer;
}