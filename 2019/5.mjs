import { readFileSync } from 'node:fs';

const data = readFileSync('./2019/5_input.dat', { encoding: 'utf8' })
	.trim()
	.split(',');

const programArr = data.map((val) => val * 1);

const input = 5;

const getParamA = (i, isImmediateMode) => {
	const el = programArr[i + 1];
	if (isImmediateMode) {
		return el;
	}
	return programArr[el];
};

const getParamB = (i, isImmediateMode) => {
	const el = programArr[i + 2];
	if (isImmediateMode) {
		return el;
	}
	return programArr[el];
};

const processOpcode = (index) => {
	const opcode = programArr[index].toString().slice(-2) * 1;

	const modesArr = programArr[index]
		.toString()
		.slice(0, -2)
		.split('')
		.reverse()
		.map((val) => val * 1);

	const paramA = getParamA(index, modesArr[0]);
	const paramB = getParamB(index, modesArr[1]);
	const paramC = programArr[index + 3];

	switch (opcode) {
		case 1: {
			programArr[paramC] = paramA + paramB;
			return index + 4;
		}

		case 2: {
			programArr[paramC] = paramA * paramB;
			return index + 4;
		}

		case 3:
			programArr[programArr[index + 1]] = input;
			return index + 2;

		case 4:
			console.log(paramA);
			return index + 2;

		case 5: {
			if (paramA) {
				return paramB;
			}
			return index + 3;
		}

		case 6: {
			if (!paramA) {
				return paramB;
			}
			return index + 3;
		}

		case 7: {
			if (paramA < paramB) {
				programArr[paramC] = 1;
			} else {
				programArr[paramC] = 0;
			}
			return index + 4;
		}

		case 8: {
			if (paramA === paramB) {
				programArr[paramC] = 1;
			} else {
				programArr[paramC] = 0;
			}
			return index + 4;
		}

		case 99:
			return -1;

		default:
			console.log('Unrecognized opcode', opcode);
			return -1;
	}
};

const testInputs = () => {
	let opcodeIndex = 0;
	while (opcodeIndex !== undefined && opcodeIndex >= 0) {
		// console.log(programArr[opcodeIndex], programArr);
		opcodeIndex = processOpcode(opcodeIndex);
	}
};

testInputs();
