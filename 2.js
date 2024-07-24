const { readFileSync } = require('node:fs');

const data = readFileSync('./1-input.dat', { encoding: 'utf8' })
	.trim()
	.split('\n');

const index = () => {
	for (let i = 0; i < Math.floor(data1.length / 4) + 1; i++) {
		const opcode = data1[i * 4];
		const operand1 = data1[i * 4 + 1];
		const operand2 = data1[i * 4 + 2];
		const address = data1[i * 4 + 3];
		console.log(opcode, operand1, operand2, address);
	}
};

const data1 = [1, 2, 3, 4, 5, 6, 7, 8, 9];
index();
