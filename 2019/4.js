let count = 0;

const verified = (pass) => {
	const unique = new Set();
	let duplicateBool = false;
	for (let i = 0; i < pass.length; i++) {
		if (i) {
			if (Number.parseInt(pass[i]) < Number.parseInt(pass[i - 1])) {
				return false;
			}
		}
		if (unique.has(Number.parseInt(pass[i]))) {
			duplicateBool = true;
		}
		unique.add(Number.parseInt(pass[i]));
	}
	if (!duplicateBool) return false;
	return true;
};

for (let i = 124075; i < 580770; i++) {
	const password = i;
	const digits = password.toString().split('');
	if (verified(digits)) count++;
}

console.log(count);
