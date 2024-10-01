class PriorityQueue {
    constructor() {
        this.heap = [];
    }
    
    swap(i, j) {
        [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
    }
    
    push(item) {
        this.heap.push(item);
        this.heapifyUp();
    }
    
    pop() {
        if (this.isEmpty())
            return null;
        if (this.heap.length === 1)
            return this.heap.pop();
        
        const root = this.heap[0];
        this.heap[0] = this.heap.pop();
        
        this.heapifyDown();
        return root;
    }
    
    isEmpty() {
        return this.heap.length === 0;
    }
    
    heapifyUp() {
        let index = this.heap.length - 1;
        
        while(index > 0) {
            let parentIdx = Math.floor((index - 1) / 2);
            
            if (this.heap[parentIdx][1] <= this.heap[index][1]) // 부모가 더 작다면 종료 (오름차순)
                break;
            
            this.swap(index, parentIdx);
            index = parentIdx;
        }
    }
    
    heapifyDown() {
        let index = 0;
        const length = this.heap.length;
        
        while(true) {
            let leftChildIdx = index * 2 + 1;
            let rightChildIdx = index * 2 + 2;
            let smallest = index;
            
            if (leftChildIdx < length && this.heap[leftChildIdx][1] < this.heap[smallest][1]) {
                smallest = leftChildIdx;
            }
            
            if (rightChildIdx < length && this.heap[rightChildIdx][1] < this.heap[smallest][1]) {
                smallest = rightChildIdx;
            }
            
            if (smallest === index)
                break;
            
            this.swap(index, smallest);
            index = smallest;
        }
    }
}

function solution(N, road, K) {
    /**
    *   N개의 edge
    *   양방향 node, 각각 다른 weight(통행 시간)
    *   1번 마을 기준으로 다익스트라 진행 후, K 이하의 비용으로 도달할 수 있는 '마을의 수'를 return
    */
    let graph = Array.from({ length : N + 1 }, () => []);
    road.forEach(([from, to, time]) => {
        graph[from].push([to, time]);
        graph[to].push([from, time]); // 무방향 그래프
    });
    
    const times = Array(N + 1).fill(Number.MAX_SAFE_INTEGER);
    times[1] = 0; // 출발지 1번 마을을 기준으로 하므로, 0으로 초기화
    const visited = Array(N + 1).fill(false);
    const pq = new PriorityQueue();
    pq.push([1, 0]); // [node, time]
    
    while(!pq.isEmpty()) {
        const [node, curTime] = pq.pop();
        
        if (visited[node])
            continue;
        
        visited[node] = true;
        
        for (const [to, time] of graph[node]) {
            const nextTime = curTime + time;
            if (nextTime < times[to]) {
                times[to] = nextTime;
                pq.push([to, nextTime]);
            }
        }
    }
    
    let result = 0;
    times.forEach((e) => {
        if (e <= K) {
            result++;
        }
    });
    
    return result;
}