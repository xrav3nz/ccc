#include <cstdio>

struct Friend
{
	int id, removed;
};

int main(){

	//freopen("s1.in", "r", stdin);

	int k, m;
	Friend friends[110];

	scanf("%d %d", &k, &m);
	
	for(int i = 0; i < k; ++i){
		friends[i].id = i + 1;
		friends[i].removed = 0;
	}

	while(m--){
		int r;
		scanf("%d", &r);
		for(int i = 0, j = 0; i < k; ++i){
			if(!friends[i].removed){
				++j;
			}
			if(j == r){
				j = 0;
				friends[i].removed = 1;
			}
		}
	}

	for(int i = 0; i < k; ++i){
		if(!friends[i].removed)
			printf("%d\n", friends[i].id);
	}


	return 0;
}