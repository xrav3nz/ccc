#include <cstdio>
#include <algorithm>

int t, c, cs[100], ans;

int main(){

	freopen("input.in", "r", stdin);

	scanf("%d %d", &t, &c);

	for(int *i = cs; i < cs + c; ++i){
		scanf("%d", i);
	}

	std::sort(cs, cs + c);

	for(int i = 0; i < c && t >= 0; ++i){
		t -= cs[i];
		if(t >= 0) ++ans;
	}

	printf("%d\n", ans);

	return 0;
}