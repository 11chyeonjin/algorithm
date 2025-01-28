const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const N = +input[0];
  const bookArr = input.slice(1);
  const result = solution(bookArr);
  console.log(result);
  process.exit();
});

function solution(bookArr) {
  const map = new Map();
  
  bookArr.forEach((book) => {
    if (map.has(book)) {
      map.set(book, map.get(book) + 1);
    } else {
      map.set(book, 1);
    }
  });

  const mapArr = [...map];
  mapArr.sort((a, b) => {
    if (a[1] === b[1]) {
      return a[0].localeCompare(b[0]);
    } else {
      return b[1] - a[1];
    }
  })

  return mapArr[0][0];
}