const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

readline.on('line', function(line) {
  input.push(line.split(' '));
}).on('close', function() {
  const result = solution(Number(input[0][0]), Number(input[0][1]), input.slice(1).map(a => a.map(e => Number(e))))
  console.log(result.join('\n'));
  process.exit();
})

class UnionFind {
  constructor(size) {
    this.parent = Array.from({ length : size }, (_, i) => i);
  }

  find(x) {
    if (this.parent[x] === x) {
      return x;
    }
    return this.parent[x] = this.find(this.parent[x]);
  }

  union(x, y) {
    const [rootX, rootY] = [this.find(x), this.find(y)];
    if (rootX !== rootY) {
      this.parent[rootX] = rootY;
    }
  }
}


function solution(n, m, operArray) {
  const result = [];

  const uf = new UnionFind(n + 1);

  operArray.forEach(([oper, a, b]) => {
    if (oper === 0) {
      uf.union(a, b);
    } else {
      if (uf.find(a) !== uf.find(b)) {
        result.push("NO");
      } else {
        result.push("YES");
      }
    }
  })

  return result;
}