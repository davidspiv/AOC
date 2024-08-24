const { readFileSync } = require('node:fs');

const data = readFileSync('./2019/5-input.dat', { encoding: 'utf8' })
	.trim()
	.split(',');

const programArr = data.map((el) => el * 1);

const getParamA = (isImmediateMode, i) => {
	if (isImmediateMode) {
		return programArr[i + 1];
	}
	const parameterAddressA = programArr[i + 1];
	return programArr[parameterAddressA];
};

const getParamB = (isImmediateMode, i) => {
	if (isImmediateMode) {
		return programArr[i + 2];
	}
	const parameterAddressB = programArr[i + 2];
	return programArr[parameterAddressB];
};

const processOpcode = (i) => {
	const opcode = programArr[i];
	const modesArr = opcode
		.toString()
		.slice(0, opcode.toString().length - 2)
		.split('');
	const instruction = opcode.toString().slice(opcode.toString().length - 2) * 1;

	if (instruction === 99) return -1;

	switch (instruction) {
		case 3:
			return 2;
		case 4:
			return 2;
		case 1: {
			const mode = modesArr[modesArr.length - 1] * 1;
			programArr[programArr[i + 3]] = getParamA(mode, i) + getParamB(mode, i);
			return 4;
		}

		case 2: {
			const mode = modesArr[modesArr.length - 2] * 1;
			programArr[programArr[i + 3]] = getParamA(mode, i) * getParamB(mode, i);
			return 4;
		}

		default:
			console.log('Unrecognized instruction', instruction);
	}
};

const testInputs = () => {
	let nextOpcodeIndex = 0;
	for (let i = 0; i < programArr.length; i++) {
		if (i === nextOpcodeIndex) {
			console.log(programArr[i])
			const step = processOpcode(i);
			nextOpcodeIndex = i + step;
		}
	}
};

testInputs();
