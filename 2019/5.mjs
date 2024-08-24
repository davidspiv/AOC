import { readFileSync } from 'node:fs';

const data = readFileSync('./2019/5-input.dat', { encoding: 'utf8' })
	.trim()
	.split(',');

const programArr = data.map((val) => val * 1);

// const programArr = [3, 0, 4, 0, 99];

const input = 1;

const getParamA = (i, isImmediateMode) => {
	if (isImmediateMode) {
		return programArr[i + 1];
	}
	const parameterAddressA = programArr[i + 1];
	return programArr[parameterAddressA];
};

const getParamB = (i, isImmediateMode) => {
	if (isImmediateMode) {
		return programArr[i + 2];
	}
	const parameterAddressB = programArr[i + 2];
	return programArr[parameterAddressB];
};

const processOpcode = (i) => {
	const opcode = programArr[i].toString().slice(-2) * 1;

	const modesArr = programArr[i]
		.toString()
		.slice(0, -2)
		.split('')
		.reverse()
		.map((val) => val * 1);

	const paramA = getParamA(i, modesArr[0]);
	const paramB = getParamB(i, modesArr[1]);

	switch (opcode) {
		case 99:
			return -1;

		case 3:
			programArr[programArr[i + 1]] = input;
			return 2;

		case 4:
			console.log(paramA);
			return 2;

		case 1: {
			programArr[programArr[i + 3]] = paramA + paramB;
			return 4;
		}

		case 2: {
			programArr[programArr[i + 3]] = paramA * paramB;
			return 4;
		}

		default:
			console.log('Unrecognized opcode', opcode);
			return -1;
	}
};

const testInputs = () => {
	let nextOpcodeIndex = 0;
	for (let i = 0; i < programArr.length; i++) {
		if (i !== nextOpcodeIndex) continue;
		const step = processOpcode(i);
		if (step < 0) return;
		nextOpcodeIndex = i + step;
	}
};

testInputs();
