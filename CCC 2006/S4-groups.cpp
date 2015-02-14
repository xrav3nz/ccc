#include <cstdio>
#include <cstring>

#define MAX_N 100

int table[MAX_N + 1][MAX_N + 1], n, identity;

bool hasAssociativity(){
	for(int x = 1; x <= n; ++x){
		for(int y = 1; y <= n; ++y){
			for(int z = 1; z <= n; ++z){
				if(x == y || y == z || x == z)
					continue;
				if(table[ table[x][y] ][z] != table[x][ table[y][z] ]){
					// printf("%d %d %d\n", x, y, z);
					// printf("%d %d\n", table[ table[x][y]  ][z], table[x][ table[y][z] ]);
					return false;
				}
			}
		}
	}
	return true;
}

bool hasIdentity(){
	for(int i = 1; i <= n; ++i){
		identity = i;
		for(int j = 1; j <= n; ++j){
			if(table[i][j] != j)
				identity = 0;
		}
		if(!identity)
			continue;
		for(int k = 1; k <= n; ++k){
			if(table[identity][k] != k)
				identity = 0;
		}
		if(identity)
			return true;
	}
	return false;
}

bool hasInverse(){
	bool inverse;
	for(int i = 1; i <= n; ++i){
		inverse = false;
		for(int j = 1; j <= n; ++j){
			if(table[i][j] == identity && table[j][i] == identity){
				inverse = true;
				break;
			}
		}
		if(!inverse)
			return false;
	}
	return true;
}

bool isGroup(){
	if(!hasIdentity()){
		// printf("hasIdentity\n");
		return false;
	}
	if(!hasInverse()){
		// printf("hasInverse\n");
		return false;		
	}
	if(!hasAssociativity()){
		// printf("hasAssociativity\n");
		return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	while(scanf("%d", &n) != EOF && n){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				scanf("%d", &table[i][j]);
			}
		}
		if(isGroup())
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}