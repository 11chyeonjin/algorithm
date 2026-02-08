function solution(k, dungeons) {
    const dl = dungeons.length;
    const arrArr = [];
    const arr = [];
    const visited = Array.from({ length: dl + 1 }, () => false);
    
    function dfs(depth) {
        if (depth === dl) {
            arrArr.push(arr.slice());
            return;
        }
        
        for (let i = 1; i <= dl; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[depth] = i;
                dfs(depth + 1);
                visited[i] = false;
            }
        }
    }
    
    dfs(0);
    
    let ans = 0;
    
    for (const curArr of arrArr) {
        let curK = k;
        let curAns = 0;
        
        for (const cur of curArr) {
            const [need, use] = dungeons[cur - 1];
            
            if (curK < need) {
                break;
            }
            
            curK -= use;
            curAns++;
        }
        
        ans = Math.max(ans, curAns);
    }
    
    return ans;
}