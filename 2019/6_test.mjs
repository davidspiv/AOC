import { readFileSync } from 'node:fs';

// const data = readFileSync('./2019/6-input.dat', { encoding: 'utf8' }).split(
// 	'\n',
// );

const data = `COM)B
B)C
C)D
D)E
E)F
B)G
G)H
D)I
E)J
J)K
K)L`.split('\n');

const global = {};

const relationships = data.map((rel) => {
	return rel.split(')');
});

let currentNode = relationships.findIndex((el) => el[0] === 'COM');

while (relationships.length) {

}

console.log(global);
