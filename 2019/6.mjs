import { readFileSync } from 'node:fs';

const data = readFileSync('./2019/6_input.dat', { encoding: 'utf8' }).split(
	'\n',
);

// const data = `COM)B
// B)C
// C)D
// D)E
// E)F
// B)G
// G)H
// D)I
// E)J
// J)K
// K)L`.split('\n');

const global = {};

const relationships = data.map((rel) => {
	return rel.split(')');
});

const parents = relationships.map((relationship) => relationship[0]);
const children = relationships.map((relationship) => relationship[1]);

let counter = 0;

const updateCount = (node) => {
	if (global[node]) {
		counter += global[node];

		console.log('test')
		return;
	}
	const targetIndex = children.indexOf(node);
	const target = parents[targetIndex];
	counter++;

	if (target === 'COM') return;
	updateCount(target);
};

for (const child of children) {
	updateCount(child);
	global[child] = counter;
	counter = 0;
}


console.log('Global object: ', global);
