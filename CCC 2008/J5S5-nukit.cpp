// CCC 2008 J5/S5 - Nukit

// a simple idea of keep trying all possible moves,
// until one of the player cannot further form any reactions

#include <iostream>
#include <vector>

using namespace std;

// number of each particles required
// to form a reaction
vector< vector<int> > reactions {
	{2, 1, 0, 2},
	{1, 1, 1, 1},
	{0, 0, 2, 1},
	{0, 3, 0, 0},
	{1, 0, 0, 1}
};

vector<int> particles(4);

// dp[a][b][c][d] = 
// 1, means the current formation will lead the current player to winning, 
// -1, means the  it will lead the current player to losing, 
int dp[31][31][31][31]; 

int n;

bool CanMove(int type){
	for(int i = 0; i < 4; ++i)
		if(particles[i] < reactions[type][i])
			return false;
	return true;
}

bool CanWin(){

	if (dp[particles[0]][particles[1]][particles[2]][particles[3]] != 0)
		return dp[particles[0]][particles[1]][particles[2]][particles[3]] == 1;

	// keep trying all possible combination
	for (int i = 0; i < 5; ++i) {

		if (!CanMove(i))
			continue;
		
		for (int j = 0; j < 4; ++j)
			particles[j] -= reactions[i][j];

		// will the current combination lead the other play to losing?
		if (!CanWin()) {
			for(int j = 0; j < 4; ++j)
				particles[j] += reactions[i][j];
			return true;
		}

		for (int j = 0; j < 4; ++j)
			particles[j] += reactions[i][j];
	}

	if (dp[particles[0]][particles[1]][particles[2]][particles[3]] == 0)
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
		if(CanWin())
			cout << "Patrick\n";
		else
			cout << "Roland\n";
	}
	return 0;
}