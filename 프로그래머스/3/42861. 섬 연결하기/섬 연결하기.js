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
        while (index > 0) {
            let parentIdx = Math.floor((index - 1) / 2);
            if (this.heap[parentIdx][1] <= this.heap[index][1])
                break;
            this.swap(parentIdx, index);
            index = parentIdx;
        }
    }
    
    heapifyDown() {
        let index = 0;
        const length = this.heap.length;
        while(true) {
            let leftChIdx = index * 2 + 1;
            let rightChIdx = index * 2 + 2;
            let smallest = index;
            
            if (leftChIdx < length && this.heap[leftChIdx][1] < this.heap[smallest][1]) {
                smallest = leftChIdx;
            }
            
            if (rightChIdx < length && this.heap[rightChIdx][1] < this.heap[smallest][1]) {
                smallest = rightChIdx;
            }
            
            if (index === smallest)
                break;
            
            this.swap(smallest, index);
            index = smallest;
        }
    }
}

function solution(n, costs) {
    const graph = Array.from({length : n}, () => []);
    costs.forEach(([from, to, cost]) => {
        graph[from].push([to, cost]);
        graph[to].push([from, cost]);
    })
    
    const visited = Array(n).fill(false);
    
    const pq = new PriorityQueue();
    pq.push([0, 0]); // node, cost
    
    let totalcost = 0;
    
    while(!pq.isEmpty()) {
        let [curNode, curCost] = pq.pop();
        
        if (visited[curNode]) continue;
        
        visited[curNode] = true;
        totalcost += curCost;
        
        for (const [to, cost] of graph[curNode]) {
            if (!visited[to]) {
                pq.push([to, cost]);
            }
        }
    }
    
    return totalcost;
}