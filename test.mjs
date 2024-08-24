import readline from 'node:readline';

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let result = 1;
rl.setPrompt('Enter Number: ');
rl.prompt();
rl.on('line', (input) => {
	result = input;
	rl.close();
});
