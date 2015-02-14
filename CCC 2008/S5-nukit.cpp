#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > reactions {
	{2, 1, 0, 2},
	{1, 1, 1, 1},
	{0, 0, 2, 1},
	{0, 3, 0, 0},
	{1, 0, 0, 1}
};

vector<int> particles(4);

int dp[31][31][31][31]; // 1 means the combo will lead the current play to winning, and -1 vice versa

int n;

bool canMove(int type){
	for(int i = 0; i < 4; ++i)
		if(particles[i] < reactions[type][i])
			return false;
	return true;
}

bool DFS(){

	if(dp[particles[0]][particles[1]][particles[2]][particles[3]] != 0)
		return dp[particles[0]][particles[1]][particles[2]][particles[3]] == 1;

	for(int i = 0; i < 5; ++i){
		if(!canMove(i))
			continue;
		for(int j = 0; j < 4; ++j)
			particles[j] -= reactions[i][j];
		if(!DFS()){
			for(int j = 0; j < 4; ++j)
				particles[j] += reactions[i][j];
			return true;
		}
		for(int j = 0; j < 4; ++j)
			particles[j] += reactions[i][j];
	}

	if(dp[particles[0]][particles[1]][particles[2]][particles[3]] == 0)
		dp[particles[0]][particles[1]][particles[2]][particles[3]] = -1;
	return false;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	freopen("input.in", "r", stdin);

	cin >> n;

	while(n--){
		for(int i = 0; i < 4; ++i)
			cin >> particles[i];
		if(DFS())
			cout << "Patrick\n";
		else
			cout << "Roland\n";
	}
	return 0;
}