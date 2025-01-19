const fs = require('fs');
const path = require('path');

const input = fs.readFileSync(path.join(__dirname, 'input'), 'utf8').split('\n').map(l => l.trim()).filter(Boolean).map(n => parseInt(n));

let increaseCount = 0;

for (let i = 1; i < input.length; i++) {
  if (input[i] > input[i - 1])
    increaseCount++;
}

console.log(increaseCount);
