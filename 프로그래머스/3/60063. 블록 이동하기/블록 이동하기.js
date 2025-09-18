function solution(board) {
    // [1][1] 부터 시작, 빈칸 0, 벽 1
    // 이동과 회전에는 1 초가 걸림
    
    // 최단시간 bfs -> 3시 29분
    
    const [y_size, x_size] = [board.length, board[0].length];
    
    const dydx = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    
    const q = [[[0, 0], [0, 1], 'h']];
    let qi = 0;
    
    const h_visited = Array.from({ length: y_size }, () => Array.from({ length: x_size - 1 }, () => 0)); // + 1
    const v_visited = Array.from({ length: y_size - 1 }, () => Array.from({ length: x_size }, () => 0)); // + 1 
    // 시간값 저장과 visited 두 가지 용도로 사용하기 위함. answer 값에 사용할 경우 -1 필요
    
    h_visited[0][0] = 1;
                                 
    while(qi < q.length) {
        const [cur_first, cur_second, cur_stat] = q[qi++];
        const [mid_y, mid_x] = [Math.floor((cur_first[0] + cur_second[0]) / 2), Math.floor((cur_first[1] + cur_second[1]) / 2)];
        let curTime;
        if (cur_stat === 'h') {
            curTime = h_visited[mid_y][mid_x];
        }
        if (cur_stat === 'v') {
            curTime = v_visited[mid_y][mid_x];
        }
        
        if ((cur_first[0] === y_size - 1 && cur_first[1] === x_size - 1) || (cur_second[0] === y_size - 1 && cur_second[1] === x_size - 1)) {
            return curTime - 1;
        }
        
        // 이동
        for (let i = 0; i < 4; i++) {
            const next_first = [cur_first[0] + dydx[i][0], cur_first[1] + dydx[i][1]];
            const next_second = [cur_second[0] + dydx[i][0], cur_second[1] + dydx[i][1]];
            
            if (0 <= next_first[0] && next_first[0] < y_size && 0 <= next_first[1] && next_first[1] < x_size) {
                if (0 <= next_second[0] && next_second[0] < y_size && 0 <= next_second[1] && next_second[1] < x_size) {
                    if (!board[next_first[0]][next_first[1]] && !board[next_second[0]][next_second[1]]) {
                        const [next_mid_y, next_mid_x] = [Math.floor((next_first[0] + next_second[0]) / 2), Math.floor((next_first[1] + next_second[1]) / 2)];
                        
                        if (cur_stat === 'h' && !h_visited[next_mid_y][next_mid_x]) {
                            q.push([next_first, next_second, 'h']);
                            h_visited[next_mid_y][next_mid_x] = curTime + 1;
                        }
                        
                        if (cur_stat === 'v' && !v_visited[next_mid_y][next_mid_x]) {
                            q.push([next_first, next_second, 'v']);
                            v_visited[next_mid_y][next_mid_x] = curTime + 1;
                        }
                    }
                }
            }
            
            if (cur_stat === 'h') {
                for (let i = 0; i < 2; i++) {
                    const next_first = [cur_first[0] + dydx[i][0], cur_first[1] + dydx[i][1]];
                    const next_second = [cur_second[0] + dydx[i][0], cur_second[1] + dydx[i][1]];
                    
                    if (0 <= next_first[0] && next_first[0] < y_size && 0 <= next_first[1] && next_first[1] < x_size) {
                        if (0 <= next_second[0] && next_second[0] < y_size && 0 <= next_second[1] && next_second[1] < x_size) {
                            if (!board[next_first[0]][next_first[1]] && !board[next_second[0]][next_second[1]]) {
                                const [f_mid_y, f_mid_x] = [Math.floor((next_first[0] + cur_first[0]) / 2), Math.floor((next_first[1] + cur_first[1]) / 2)];
                                if (!v_visited[f_mid_y][f_mid_x]) {
                                    q.push([next_first, cur_first, 'v']);
                                    v_visited[f_mid_y][f_mid_x] = curTime + 1;
                                }
                                
                                const [s_mid_y, s_mid_x] = [Math.floor((next_second[0] + cur_second[0]) / 2), Math.floor((next_second[1] + cur_second[1]) / 2)];
                                if (!v_visited[s_mid_y][s_mid_x]) {
                                    q.push([next_second, cur_second, 'v']);
                                    v_visited[s_mid_y][s_mid_x] = curTime + 1;
                                }
                            }
                        }
                    }
                }
            }  
            
            if (cur_stat === 'v') {
                for (let i = 2; i < 4; i++) {
                    const next_first = [cur_first[0] + dydx[i][0], cur_first[1] + dydx[i][1]];
                    const next_second = [cur_second[0] + dydx[i][0], cur_second[1] + dydx[i][1]];
                    
                    if (0 <= next_first[0] && next_first[0] < y_size && 0 <= next_first[1] && next_first[1] < x_size) {
                        if (0 <= next_second[0] && next_second[0] < y_size && 0 <= next_second[1] && next_second[1] < x_size) {
                            if (!board[next_first[0]][next_first[1]] && !board[next_second[0]][next_second[1]]) {
                                const [f_mid_y, f_mid_x] = [Math.floor((next_first[0] + cur_first[0]) / 2), Math.floor((next_first[1] + cur_first[1]) / 2)];
                                if (!h_visited[f_mid_y][f_mid_x]) {
                                    q.push([next_first, cur_first, 'h']);
                                    h_visited[f_mid_y][f_mid_x] = curTime + 1;
                                }
                                
                                const [s_mid_y, s_mid_x] = [Math.floor((next_second[0] + cur_second[0]) / 2), Math.floor((next_second[1] + cur_second[1]) / 2)];
                                if (!h_visited[s_mid_y][s_mid_x]) {
                                    q.push([next_second, cur_second, 'h']);
                                    h_visited[s_mid_y][s_mid_x] = curTime + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}