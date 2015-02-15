// CCC 2008 J3 - GPX Text Entry

// if we were to assign a line number (row) and 
// position number (col) to each character on the grid, 
// it becomes:

// 		+---+---+---+-------+---+---+-------+
// 		|   | 0 | 1 |   2   | 3 | 4 |   5   |
// 		+---+---+---+-------+---+---+-------+
// 		| 0 | A | B |   C   | D | E |   F   |
// 		| 1 | G | H |   I   | J | K |   L   |
// 		| 2 | M | N |   O   | P | Q |   R   |
// 		| 3 | S | T |   U   | V | W |   X   |
// 		| 4 | Y | Z | space | - | . | enter |
// 		+---+---+---+-------+---+---+-------+

// so the number of moves performed from line a, position b
// to line i, position j is:
// 				|i - a| + |j - b|

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string input;
int total_moves, last_line, last_pos, line, pos;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	// reading the entire line, since there are spaces
	getline(cin, input);

	for (int i = 0; input[i]; ++i) {
		last_pos = pos;
		last_line = line;

		// manually assign the position to space, dash, and dot
		if (input[i] == ' ') {
			line = 4;
			pos = 2;
		} else if (input[i] == '-') {
			line = 4;
			pos = 3;
		} else if (input[i] == '.') {
			line = 4;
			pos = 4;
		} else {
			// make use of ascii number
			line = (input[i] - 'A') / 6;
			pos = (input[i] - 'A') % 6;
		}
		total_moves += abs(line - last_line) + abs(pos - last_pos);
	}

	// final move to the "enter" key
	total_moves += abs(line - 4) + abs(pos - 5);

	cout << total_moves << endl;

	return 0;
}