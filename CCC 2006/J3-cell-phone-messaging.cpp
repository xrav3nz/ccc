#include <iostream>
#include <string>

using namespace std;

int a[26] = {
	1, 2, 3,
	1, 2, 3,
	1, 2, 3,
	1, 2, 3,
	1, 2, 3,
	1, 2, 3, 4,
	1, 2, 3,
	1, 2, 3, 4
}, b[26] = {
	2, 2, 2,
	3, 3, 3,
	4, 4, 4,
	5, 5, 5,
	6, 6, 6,
	7, 7, 7, 7,
	8, 8, 8,
	9, 9, 9, 9
},total;

string input;

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);

	while(cin >> input && input != "halt"){
		total = 0;
		for(int i = 0; input[i]; ++i){
			total += a[input[i] - 'a'];
			if(i && b[input[i] - 'a'] == b[input[i - 1] - 'a'])
				total += 2;
		}
		cout << total << endl;
	}
	
	return 0;
}