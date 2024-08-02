const { readFileSync } = require('node:fs');

const createStepArr = (wire) => {
	const cord = { y: 0, x: 0, dist: 0 };
	const outputArr = [];

	for (let i = 0; i < wire.length; i++) {
		const code = wire[i];
		const direction = code[0];
		const distance = Number(code.slice(1));
		const step = direction === 'D' || direction === 'L' ? -1 : 1;

		for (let j = 0; j < distance; j++) {
			if (direction === 'U' || direction === 'D') {
				cord.y += step;
			} else if (direction === 'R' || direction === 'L') {
				cord.x += step;
			} else {
				console.log('error with direction');
			}
			outputArr.push({ ...cord });
		}
	}

	return outputArr;
};

const index = () => {
	const matches = [];

	const data = readFileSync('./2019/3-input.dat', { encoding: 'utf8' });

	const wires = data.split('\n');
	const wireA = wires[0].split(',');
	const wireB = wires[1].split(',');

	const wireAArr = createStepArr(wireA);
	const wireBArr = createStepArr(wireB);

	const verify = (cord) => {
		for (let i = 0; i < wireBArr.length; i++) {
			const isMatch = wireBArr[i].x === cord.x && wireBArr[i].y === cord.y;
			if (isMatch) return i;
		}
		return 0;
	};

	for (let i = 0; i < wireAArr.length; i++) {
		const cord = wireAArr[i];
		const isMatch = verify(cord);
		if (isMatch) {
			// const manhattanDistance = Math.abs(cord.x) + Math.abs(cord.y);
			const wireLength = i + isMatch + 2;
			matches.push(wireLength);
		}
	}

	const closestMatch = matches.reduce((pVal, cVal) => {
		return pVal < cVal ? pVal : cVal;
	});
	console.log(closestMatch);
};

index();
