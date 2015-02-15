// CCC 2009 J4 - Signage

// My code is so ugly for this question :/

// First of all, I find the max number of words can be put on
// the current line. Calculate the space between each of them,
// if the spaces cannot be made equal, I insert the extra spaces
// one by one into the space between first words.

#include <iostream>
#include <string>

using namespace std;

string message[6] = {
	"WELCOME",
	"TO",
	"CCC",
	"GOOD",
	"LUCK",
	"TODAY"
};

int width, message_length, blank_length, blank_unit, blank_mod;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> width;

	for(int i = 0, total = 0, start = 0; i < 6; ++i){
		total += message[i].size();
		if(i < 5 && total + message[i + 1].size() + i - start < width)
			continue;
		message_length = 0;
		for(int j = start; j <= i; ++j){
			message_length += message[j].size();
		}
		blank_length = width - message_length;

		if(i - start == 0){
			cout << message[i] << string(blank_length, '.');
		}else{
			blank_unit = blank_length / (i - start);
			blank_mod = blank_length % (i - start);
			for(int j = start; j <= i; ++j){
				cout << message[j];
				if(j != i)
					 cout << string(blank_unit, '.');
				if(blank_mod > 0)
					cout << '.';
				--blank_mod;
			}
		}
		start = i + 1;
		total = 0;
		cout << endl;
	}
	cout << endl;
	
	return 0;
}