// import { readFileSync } from 'node:fs';

// const data = readFileSync('./2015/7.dat', { encoding: 'utf8' });

const data = `
123 -> x
456 -> y
x AND y -> d
x OR y -> e
x LSHIFT 2 -> f
y RSHIFT 2 -> g
NOT x -> h
NOT y -> i
`;

const global = {};

const programArr = data
	.trim()
	.split('\n')
	.map((instruction) => instruction.trim().split(' -> '));

for (const [signal, wire] of programArr) {
	if (signal.indexOf('AND') !== -1) {
		const [operandA, _operator, operandB] = signal;

		console.log(operandA, Number.isNaN(operandA));

		if (Number.isNaN(operandA) || Number.isNaN(operandB)) {
			console.log('test');
			continue;
		}
		global[wire] = operandA & operandB;
	}
}

console.log(global);
