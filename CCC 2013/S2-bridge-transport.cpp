#include <iostream>
#include <vector>

using namespace std;

int max_weight, num_cars, cur_weight, answer;
vector<int> cars;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> max_weight >> num_cars;

	cars.resize(num_cars);

	for (int i = 0; i < num_cars; ++i)
		cin >> cars[i];

	for (answer = 0; answer < num_cars; ++answer) {
		if (answer >= 4)
			cur_weight -= cars[answer - 4];
		cur_weight += cars[answer];
		if (cur_weight > max_weight) 
			break;
	}

	cout << answer << endl;
	
	return 0;
}