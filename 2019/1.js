const { readFile } = require('node:fs/promises');

const fuelCalc = (mass) => {
	return Math.floor(Number(mass) / 3) - 2;
};

const getTotalFuel = (mass) => {
	let fuel = fuelCalc(mass);
	let totalFuel = 0;
	while (fuel > 0) {
		totalFuel += fuel;
		fuel = fuelCalc(fuel);
	}
	return totalFuel;
};

const index = async () => {
	const data = await readFile('./1-input.dat', { encoding: 'utf8' })
		.trim()
		.split('\n');

	const fuelReq1 = data.reduce((pVal, cVal) => {
		return pVal + fuelCalc(cVal);
	}, 0);

	const fuelReq2 = data.reduce((pVal, cVal) => {
		return pVal + getTotalFuel(cVal);
	}, 0);

	console.log([fuelReq1, fuelReq2]);
};

index();
