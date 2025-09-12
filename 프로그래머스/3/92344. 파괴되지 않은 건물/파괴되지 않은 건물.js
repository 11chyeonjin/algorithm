function solution(board, skill) {
    const [N, M] = [board.length, board[0].length];
    const arr = Array.from({ length: N }, () => Array.from({ length: M }, () => 0));
    
    skill.forEach(([type, r1, c1, r2, c2, degree]) => {
        if (type === 1) {
            degree = -degree;
        }
        
        arr[r1][c1] += degree;
        
        if (r2 + 1 < N) {
            arr[r2 + 1][c1] -= degree;
        }
        
        if (c2 + 1 < M) {
            arr[r1][c2 + 1] -= degree;
        }
        
        if (r2 + 1 < N && c2 + 1 < M) {
            arr[r2 + 1][c2 + 1] += degree;
        }
    });

    for (let i = 0; i < N; i++) {
        for (let j = 1; j < M; j++) {
            arr[i][j] += arr[i][j - 1];
        }
    }

    for (let j = 0; j < M; j++) {
        for (let i = 1; i < N; i++) {
            arr[i][j] += arr[i - 1][j];
        }
    }

    let answer = 0;
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            board[i][j] += arr[i][j];
            if (board[i][j] > 0) {
                answer++;
            }
        }
    }

    return answer;
}