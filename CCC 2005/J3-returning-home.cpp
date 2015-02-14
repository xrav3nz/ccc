#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> instructions;
string instruction, dir, place;

int main(){

	ios_base::sync_with_stdio(false);

	freopen("input.in", "r", stdin);

	while(cin >> instruction){
		instructions.push_back(instruction);
	}

	for(int i = instructions.size() - 2; i >= 0; i -= 2){
		dir = ((instructions[i] == "L" )? "RIGHT" : "LEFT");
		place = (i != 0) ? (instructions[i - 1] + " street") : "your HOME";
		printf("Turn %s %s %s.\n", dir.c_str(), ((i != 0) ? "onto" : "into"), place.c_str());
	}

	return 0;
}