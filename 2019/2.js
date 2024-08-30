const { readFileSync } = require('node:fs');

const data = readFileSync('./2_input.dat', { encoding: 'utf8' })
	.trim()
	.split(',');

let arr = data.map((el) => Number(el));

const testInputs = (noun, verb) => {
	arr[1] = noun;
	arr[2] = verb;
	for (let i = 0; i < arr.length; i += 4) {
		const opcode = arr[i];
		const operandAddressA = arr[i + 1];
		const operandAddressB = arr[i + 2];
		const destAddress = arr[i + 3];
		const operandValA = arr[operandAddressA];
		const operandValB = arr[operandAddressB];
		const destVal = arr[destAddress];

		if (opcode === 99 || Number.isNaN(operandValA + operandValB + destVal)) break;

		if (opcode === 1) {
			arr[arr[i + 3]] = operandValA + operandValB;
			continue;
		}

		if (opcode === 2) {
			arr[arr[i + 3]] = operandValA * operandValB;
			continue;
		}

		console.log('Unrecognized opcode');
	}
};

const index = () => {
	for (let noun = 0; noun < 100; noun++) {
		for (let verb = 0; verb < 100; verb++) {
			testInputs(noun, verb);
			if (arr[0] === 19690720) {
				console.log(100 * noun + verb);
				return;
			}
			arr = data.map((el) => Number(el));
		}
	}
	console.log('Input not found');
};

index();
