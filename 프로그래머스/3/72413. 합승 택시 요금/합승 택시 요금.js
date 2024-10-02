class PriorityQueue {
    /**
    *   오름차순 우선순위 큐를 구현
    *   비교를 위한 값은 [][1] 에 둔다
    */
    constructor() {
        this.heap = [];
    }
    
    swap(a, b) {
        [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
    }
    
    push(item) {
        this.heap.push(item);
        this.heapifyUp();
    }
    
    pop() {
        if (this.isEmpty()) {
            return null;
        }
        
        if (this.heap.length === 1) {
            return this.heap.pop();
        }
        
        const root = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown();
        return root;
    }
    
    isEmpty() {
        return this.heap.length === 0;
    }
    
    heapifyUp() {
        let idx = this.heap.length - 1;
        while(idx > 0) {
            let parentIdx = Math.floor((idx - 1) / 2);
            if (this.heap[parentIdx][1] < this.heap[idx][1]) {
                break;
            }
            this.swap(parentIdx, idx);
            idx = parentIdx;
        }
    }
    
    heapifyDown() {
        let idx = 0;
        while(true) {
            let leftChIdx = idx * 2 + 1;
            let rightChIdx = idx * 2 + 2;
            let smallest = idx;
            
            if (leftChIdx < this.heap.length && this.heap[leftChIdx][1] < this.heap[smallest][1]) {
                smallest = leftChIdx;
            }
            
            if (rightChIdx < this.heap.length && this.heap[rightChIdx][1] < this.heap[smallest][1]) {
                smallest = rightChIdx;
            }
            
            if (smallest === idx) {
                break;
            }
            
            this.swap(smallest, idx);
            idx = smallest;
        }
    }
}

function solution(n, s, a, b, fares) {
    // 지점의 수 n(1부터 시작), 출발지점 s, A도착지 a, B도착지 b, edge비용 fares
    // 간선은 양방향 이동이 가능(무방향그래프)
    // 최저 예상 택시요금을 구하는 문제
    // s, a, b를 기준으로 각각 다익스트라를 진행하고, 경유지 T(S,A,B 포함 모든 노드) / S~T + T~A + T~B 의 값을 비교
    
    const graph = Array.from({length: n + 1}, () => []);
    fares.forEach(([from, to, cost]) => {
        graph[from].push([to, cost]);
        graph[to].push([from, cost]);
    })
    
    function dijkstra(startNode) {
        const costs = Array(n + 1).fill(Number.MAX_SAFE_INTEGER);
        costs[startNode] = 0;
        
        const visited = Array(n + 1).fill(false);
        
        const pq = new PriorityQueue();
        pq.push([startNode, 0]); // [node, cost]
        
        while(!pq.isEmpty()) {
            const [curNode, curCost] = pq.pop();
            
            if (visited[curNode])
                continue;
            
            visited[curNode] = true;
            
            for (const [nextNode, nextCost] of graph[curNode]) {
                if (curCost + nextCost < costs[nextNode]) {
                    costs[nextNode] = curCost + nextCost;
                    pq.push([nextNode, curCost + nextCost]);
                }
            }
        }
        
        return costs;
    }
    
    const aResult = dijkstra(a);
    const bResult = dijkstra(b);
    const sResult = dijkstra(s);
    
    let answer = Number.MAX_SAFE_INTEGER;
    for (let i = 1; i <= n; i++) {
        if (aResult[i] !== Number.MAX_SAFE_INTEGER && bResult[i] !== Number.MAX_SAFE_INTEGER && sResult[i] !== Number.MAX_SAFE_INTEGER) {
            answer = Math.min(aResult[i] + bResult[i] + sResult[i], answer);
        }
    }
    
    return answer;
}