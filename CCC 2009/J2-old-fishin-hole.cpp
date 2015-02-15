// CCC 2009 J2 - Old Fishin' Hole

// nested loop

// given the limit and points for each type of fish,
// the max number of fish_i is:
// 			limit / fish_i_points

// loop through the number of each fish we can have,
// output the ones that have the total points less than 
// or equal to the limit

#include <iostream>

using namespace std;

int trout_point, pike_point, pickerel_point, limit, total, answer;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> trout_point >> pike_point >> pickerel_point >> limit;

	for (int pickerel_num = 0; pickerel_num <= limit / pickerel_point; ++pickerel_num) 
		for (int pike_num = 0; pike_num <= limit / pike_point; ++pike_num) 
			for (int trout_num = 0; trout_num <= limit / trout_point; ++trout_num) {
				if (trout_num == 0 && pike_num == 0 && pickerel_num == 0)
					continue;
				if(trout_point * trout_num + pickerel_point * pickerel_num + pike_point * pike_num <= limit){
					++answer;
					printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n", trout_num, pike_num, pickerel_num);
				}
			}

	printf("Number of ways to catch fish: %d\n", answer);
	
	return 0;
}