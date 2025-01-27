const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const str = input[0];
  const bomb = input[1];
  const result = solution(str, bomb);
  console.log(result);
  process.exit();
});

function solution(str, bomb) {
  const stack = [];
  const bombSize = bomb.length;
  
  for (const char of str) {
    stack.push(char);

    if (stack.length >= bombSize) {
      let flag = true;
      
      for (let i = 0 ; i < bombSize; i++) {
        if (stack[stack.length - bombSize + i] !== bomb[i]) {
          flag = false;
          break;
        }
      }

      if (flag) {
        stack.splice(stack.length - bombSize, bombSize);
      }
    }
  }

  if (stack.length === 0) {
    return "FRULA"
  }
  
  return stack.join('');
}