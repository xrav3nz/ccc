#include <iostream>
#include <string>

using namespace std;

#define MAX_N 1000
#define VERTI 1
#define HORIZ 2
#define RDIAG 3
#define LDIGA 4

string box[MAX_N];
int n, answer;

bool areSymmetrical(char a, char b, int dir){
	if(a == '.' && b == '.')
		return true;
	if(a == 'O' && b == 'O')
		return true;
	if(a == '(' && b == '(' && dir == HORIZ)
		return true;
	if(a == ')' && b == ')' && dir == HORIZ)
		return true;
	if(a == '(' && b == ')' && dir == VERTI)
		return true;
	if(a == ')' && b == '(' && dir == VERTI)
		return true;
	if(a == '\\' && b == '\\' && (dir == RDIAG || dir == LDIGA))
		return true;
	if(a == '/' && b == '/' && (dir == RDIAG || dir == LDIGA))
		return true;
	if(a == '\\' && b == '/' && (dir == VERTI || dir == HORIZ))
		return true;
	if(a == '/' && b == '\\' && (dir == VERTI || dir == HORIZ))
		return true;

	return false;
}

bool isSymmetrical(int dir){
	if(dir == VERTI){
		int c1, c2;
		if(n % 2 == 1)
			c1 = c2 = n / 2;
		else
			c1 = n / 2, c2 = c1 - 1;
		for(int row = 0; row < n; ++row){
			for(int col1 = c1, col2 = c2; col1 >= 0 && col2 < n; --col1, ++col2){
				//for testing
				// printf("%d %d -> %d %d\n", row, col1, row, col2);
				if(!areSymmetrical(box[row][col1], box[row][col2], dir))
					return false;
			}
		}
	}else if(dir == HORIZ){
		int r1, r2;
		if(n % 2 == 1)
			r1 = r2 = n / 2;
		else
			r1 = n / 2, r2 = r1 - 1;
		for(int col = 0; col < n; ++col){
			for(int row1 = r1, row2 = r2; row1 >= 0 && row2 < n; --row1, ++row2){
				// printf("%d %d -> %d %d\n", row1, col, row2, col);
				if(!areSymmetrical(box[row1][col], box[row2][col], dir))
					return false;
			}
		}
	}else if(dir == RDIAG){
		int col2, row2;
		for(int row1 = 0; row1 < n; ++row1){
			for(int col1 = 0; col1 < n; ++col1){
				col2 = n - 1 - row1;
				row2 = n - 1 - col1;
				// for testing
				// printf("%d %d -> %d %d\n", row1, col1, row2, col2);
				if(!areSymmetrical(box[row1][col1], box[row2][col2], dir))
					return false;
			}
		}
	}else if(dir == LDIGA){
		int col2, row2;
		for(int row1 = 0; row1 < n; ++row1){
			for(int col1 = n - 1; col1 >= 0; --col1){
				col2 = row1;
				row2 = col1;
				if(!areSymmetrical(box[row1][col1], box[row2][col2], dir))
					return false;
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{

	freopen("input.in", "r", stdin);

	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> box[i];

	for(int i = 1; i <= 4; ++i)
		if(isSymmetrical(i))
			++answer;

	cout << answer << endl;
	return 0;
}