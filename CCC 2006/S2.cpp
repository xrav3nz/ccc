#include <iostream>
#include <map>

#define MAX 81

using namespace std;

map<char, char> decode;

char input[MAX], plain[MAX], cipher[MAX];

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	// cin >> plain >> cipher >> input;

	cin.getline(plain, MAX);
	cin.getline(cipher, MAX);
	cin.getline(input, MAX);

	for(int i = 0; plain[i]; ++i){
		decode[cipher[i]] = plain[i];
	}

	for(int i = 0; input[i]; ++i){
		if(decode[input[i]])
			cout << decode[input[i]];
		else
			cout << '.';
	}
	cout << endl;
	return 0;
}