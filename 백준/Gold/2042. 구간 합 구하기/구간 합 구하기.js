const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(e => BigInt(e)));
}).on('close', function() {
  const [N, M, K] = input[0].map(Number);
  const ans = solution([N, M, K], input.splice(1, N).flat(), input.splice(1));
  console.log(ans.join('\n'));
  process.exit();
})

class SegmentTree {
  constructor(arr, oper = (a, b) => a + b, defaultV = 0n) {
    this.n = arr.length;
    this.tree = Array(4 * this.n).fill(defaultV);
    this.oper = oper;
    this.defaultV = defaultV;
    this.#build(arr, 1, 0, this.n - 1);
  }

  #build(arr, node, start, end) {
    if (start === end) {
      this.tree[node] = arr[start];
      return;
    }

    const mid = Math.floor((start + end) / 2);
    this.#build(arr, node * 2, start, mid);
    this.#build(arr, node * 2 + 1, mid + 1, end);
    this.tree[node] = this.oper(this.tree[node * 2], this.tree[node * 2 + 1]);
  }

  update(index, value, node = 1, start = 0, end = this.n - 1) {
    if (index < start || index > end)
      return;
    
    if (start === end) {
      this.tree[node] = value;
      return;
    }

    const mid = Math.floor((start + end) / 2);
    this.update(index, value, node * 2, start, mid);
    this.update(index, value, node * 2 + 1, mid + 1, end);
    this.tree[node] = this.oper(this.tree[node * 2], this.tree[node * 2 + 1]);
  }

  query(l, r, node = 1, start = 0, end = this.n - 1) {
    if (l > end || start > r)
      return this.defaultV;
    
    if (l <= start && end <= r) {
      return this.tree[node];
    }

    const mid = Math.floor((start + end) / 2);
    const leftV = this.query(l, r, node * 2, start, mid);
    const rightV = this.query(l, r, node * 2 + 1, mid + 1, end);
    return this.oper(leftV, rightV);
  }
}

function solution([N, M, K], arr, commArr) {
  const st = new SegmentTree(arr);

  const answer = [];

  commArr.forEach(([_op, _first, second]) => {
    const [op, first] = [Number(_op), Number(_first)];
    if (Number(op) === 1) {
      st.update(first - 1, second);
    } else {
      answer.push(st.query(first - 1, Number(second) - 1));
    }
  })

  return answer;
}