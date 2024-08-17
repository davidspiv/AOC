let count = 0;

const verified = (pass) => {
	const unique = {};
	for (let i = 0; i < pass.length; i++) {
		const el = pass[i] * 1;

		if (i) {
			if (el < pass[i - 1] * 1) {
				return false;
			}
		}

		if (!unique[el]) unique[el] = 0;
		unique[el]++;
	}

	for (const key in unique) {
		if (unique[key] === 2) return true;
	}

	return false;
};

for (let i = 124075; i < 580770; i++) {
	const password = i;
	const digits = password.toString().split('');
	if (verified(digits)) count++;
}

console.log(count);
