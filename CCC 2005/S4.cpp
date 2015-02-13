#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <climits>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

map<string, int> names;
vector<string> nameList;
string name;

int L, N, max, temp;

int main(int argc, char const *argv[])
{

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cin >> L;

	while(L--){
		cin >> N;

		max = INT_MIN;
		names.clear();
		nameList.clear();
		temp = 0;

		for(int i = 0; i < N; ++i){
			cin >> name;
			nameList.push_back(name);
		}

		names[nameList[N - 1]] = 1;

		for(int i = 0; i < N; ++i){
			if(names[nameList[i]] == 1){
				--temp;
			}else{
				names[nameList[i]] = 1;
				++temp;
				if(temp > max) max = temp;
			}
		}

		cout << (N - max * 2) * 10 << endl;
	}
	return 0;
}