const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  const p = input[0];
  const d = input[1];
  if (p.length < d.length) {
    console.log("no");
  } else {
    console.log("go");
  }
  process.exit();
});
