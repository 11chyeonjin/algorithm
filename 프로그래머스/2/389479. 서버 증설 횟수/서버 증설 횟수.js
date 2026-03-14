function solution(players, m, k) {
    let answer = 0;
    
    const server = Array.from({ length: players.length }, () => 0);
    
    for (let i = 0; i < players.length; i++) {
        let curMaxUser = (1 + server[i]) * m - 1;
        
        let cnt = 0;
        while (curMaxUser < players[i]) {
            cnt++;
            
            for (let j = 0; j < k; j++) {
                server[i + j]++;
            }
            
            curMaxUser += m;
        }
        
        answer += cnt;
    }
    
    return answer;
}