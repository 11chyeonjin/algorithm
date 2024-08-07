function solution(park, routes) {
    // 공원 문자열 배열 park, 명령 문자열 배열 routes
    const dirObject = {
        E: [0, 1],
        W: [0, -1],
        S: [1, 0],
        N: [-1, 0],
    };
    
    let lobo;
    
    let N = park[0].length;
    let M = park.length;
    
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (park[i][j] == "S") {
                lobo = [i, j];
                break;
            }
        }
    }
    
    for (let i = 0; i < routes.length; i++) {
        // 모든 명령을 차례로 수행

        const [curDir, curDis] = routes[i].split(" ");
        let curLobo = lobo;
        
        let flag = true;
        for (let j = 0; j < parseInt(curDis); j++) {
            flag = true;
            let nextLobo = [curLobo[0] + dirObject[curDir][0], curLobo[1] + dirObject[curDir][1]];
            if (0 <= nextLobo[0] && nextLobo[0] < M && 0 <= nextLobo[1] && nextLobo[1] < N) {
                if (park[nextLobo[0]][nextLobo[1]] != "X") {
                    curLobo = nextLobo;
                } else {
                    flag = false;
                    break;
                }
            } else {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            console.log(i, curLobo);
            lobo = curLobo;
        }
    }
    
    return lobo;
}