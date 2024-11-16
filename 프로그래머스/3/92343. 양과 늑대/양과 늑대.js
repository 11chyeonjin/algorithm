function solution(info, edges) {
    let rst = 0;
    
    function dfs(curNode, curSheep, curWolf, canVisit) {
        // 방문에 대한 양, 늑대 계산
        if (info[curNode] === 1) {
            // 늑대
            curWolf++;
        } else {
            curSheep++;
        }
        
        // 모은 양 마릿수 확인
        if (curWolf >= curSheep) {
            return;
        } else {
            rst = Math.max(rst, curSheep);
        }
        
        const newSet = new Set(canVisit);
        newSet.delete(curNode);
        
        // 이동 가능한 노드 목록에 추가
        for (let i = 0; i < graph[curNode].length; i++) {
            newSet.add(graph[curNode][i]);
        }
        
        // 재귀함수 실행
        for (const el of newSet) {
            dfs(el, curSheep, curWolf, newSet);
        }
    }
    
    const graph = Array.from({length: info.length}, () => []);
    edges.forEach((el) => {
        graph[el[0]].push(el[1]);
    })
    
    dfs(0, 0, 0, new Set());
    
    return rst;
}