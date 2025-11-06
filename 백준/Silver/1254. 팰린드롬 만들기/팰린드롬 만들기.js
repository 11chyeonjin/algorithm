const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = '';

rl.on('line', function(line) {
  input = line;
}).on('close', function() {
  const ans = solution(input);
  console.log(ans);
})

function check(str) {
  let left = 0;
  let right = str.length - 1;

  while(left < right) {
    if (str[left] === str[right] || str[right] === '*') {
      left++;
      right--;
    } else {
      return false;
    }
  }

  return true;
}

function solution(str) {
  for (let i = 0; i < str.length; i++) {
    const rst = check(str);
    
    if (rst) {
      return str.length;
    }

    str += '*';
  }
}