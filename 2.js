const { readFileSync } = require('node:fs');

const data = readFileSync('./1-input.dat', { encoding: 'utf8' })
	.trim()
	.split('\n');

const index = () => {
	for (let i = 0; i < data1.length + 1; i += 4) {
		const opcode = data1[i];
		const operand1 = data1[i + 1];
		const operand2 = data1[i + 2];
		const address = data1[i + 3];
		console.log(opcode, operand1, operand2, address);
	}
};

const data1 = [1, 2, 3, 4, 5, 6, 7, 8, 9];
index();
