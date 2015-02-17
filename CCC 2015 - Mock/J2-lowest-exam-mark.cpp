#include <iostream>

using namespace std;

int P, Q, W, minGrade;

int main(){

	ios_base::sync_with_stdio(false);

	freopen("input.in", "r", stdin);

	cin >> P >> Q >> W;

	minGrade = (int) (1.0 * (Q * 100 - 50 - P * (100 - W)) / W + 0.5);
	if(minGrade < 0) minGrade = 0;

	if(minGrade > 100)
		cout << "DROP THE COURSE\n";
	else
		cout << minGrade << endl;

	return 0;
}