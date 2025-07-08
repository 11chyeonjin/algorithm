const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const rst = solution(input.slice(1));
  console.log(rst.join('\n'));
  process.exit();
})

function solution(arr) {
  const rst = [];
  arr.forEach((e, i) => {
    const str = `${i + 1}. `
    rst.push(str + e);
  })

  return rst;
}
