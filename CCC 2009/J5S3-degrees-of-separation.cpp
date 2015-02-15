// CCC 2009 J5/S3 - Degree of Separation

// I implement the graph in adjacent matrix

// Three main functions:

// #1 FriendsOf(x)
// simply finding how many friends x has, iterate through the matrix and count

// #2 FriendsOfFriendsOf(x)
// slightly complicated, mark x and x's friends as visited,
// then iterate through x's friends' friends, count those who have not been marked visited

// #3 DegreeOfSep(x, y)
// I implement a breadth first search, looking for the shortest path from x to y

#include <iostream>
#include <cstring>
#include <queue>

#define MAX 50

using namespace std;

int friends[50][50], x, y, visited[50];

int data[22][2] = {
	2, 6,
	6, 1,
	6, 3,
	6, 4,
	6, 5,
	6, 7,
	3, 4,
	3, 15,
	3, 5,
	4, 5,
	15, 13,
	13, 14,
	13, 12,
	12, 9,
	12, 11,
	11, 10,
	10, 9,
	8, 9,
	7, 8,
	16, 18,
	18, 17,
	17, 16
};

char command[2];

int FriendsOf(){
	int total = 0;
	for(int i = 0; i < 50; ++i)
		if(friends[x][i])
			++total;
	return total;
}

int FriendsOfFriendsOf(){
	int total = 0;

	memset(visited, 0, sizeof(visited));

	visited[x] = 1;

	for(int i = 0; i < 50; ++i)
		if(friends[x][i])
			visited[i] = 1;


	for(int i = 0; i < 50; ++i)
		if(friends[x][i])
			for(int j = 0; j < 50; ++j)
				if(friends[i][j] && !visited[j]){
					++total;
					visited[j] = 1;
				}


	return total;
}

int DegreeOfSep(){
	queue<int> friendsOfX;

	memset(visited, 0, sizeof(visited));

	for(int i = 0; i < 50; ++i)
		if(friends[x][i]){
			visited[i] = 1;
			friendsOfX.push(i);
		}

	while(!friendsOfX.empty()){
		int temp = friendsOfX.front();
		friendsOfX.pop();

		if(temp == y)
			return visited[temp];

		for(int i = 0; i < 50; ++i)
			if(friends[temp][i] && !visited[i]){
				visited[i] = visited[temp] + 1;
				friendsOfX.push(i);
			}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	freopen("input.in", "r", stdin);

	for(int i = 0; i < 22; ++i)
		friends[data[i][0]][data[i][1]] = friends[data[i][1]][data[i][0]] = 1;

	while(scanf("%s", command) != EOF && command[0] != 'q'){
		if(command[0] == 'i'){
			scanf("%d %d", &x, &y);
			friends[x][y] = friends[y][x] = 1;
		}else if(command[0] == 'd'){
			scanf("%d %d", &x, &y);
			friends[x][y] = friends[y][x] = 0;
		}else if(command[0] == 'n'){
			scanf("%d", &x);
			cout << FriendsOf() << "\n";
		}else if(command[0] == 'f'){
			scanf("%d", &x);
			cout << FriendsOfFriendsOf() << "\n";
		}else if(command[0] == 's'){
			scanf("%d %d", &x, &y);
			int output = DegreeOfSep();
			if(output)
				cout << output << endl;
			else
				cout << "Not connected\n";
		}
	}

	return 0;
}