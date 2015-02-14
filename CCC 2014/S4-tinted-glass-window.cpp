#include <cstdio>
#include <set>
#include <vector>

#define MAX 1001

using std::set;
using std::vector;

int N, T, xLimit, yLimit, currentTint,
	grid[MAX * 2][MAX * 2];

long long unsigned answer;

struct Glass
{
	int x1, y1, x2, y2, tint;
} glass;

vector<int> sortedX, sortedY;
vector<Glass> glasses;
set<int> uniqueX, uniqueY;

int binarySearch(const std::vector<int>& array, int n){

	int low = 0;
	int high = array.size();
	int mid = 0;

	while(low <= high){

		//find middle index
		mid = low + (high - low) / 2;

		//if the value of the middle index is larger than n
		if(array[mid] > n){
			high = mid - 1;
		}else if(array[mid] < n){
			low = mid + 1;
		}else{
			return mid;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	// freopen("S4.in", "r", stdin);
	// freopen("S4.out", "w", stdout);

	scanf("%d %d", &N, &T);

	for(int i = 0; i < N; ++i){
		scanf("%d %d %d %d %d", &glass.x1, &glass.y1, &glass.x2, &glass.y2, &glass.tint);
		glasses.push_back(glass);

		//push the values into set, so the duplicates will be removed, and elements with be sorted
		uniqueX.insert(glass.x1);
		uniqueX.insert(glass.x2);
		uniqueY.insert(glass.y1);
		uniqueY.insert(glass.y2);
	}

	//copy the sorted & duplicate-removed set into vector
	sortedX.assign(uniqueX.begin(), uniqueX.end());
	sortedY.assign(uniqueY.begin(), uniqueY.end());

	xLimit = sortedX.size();
	yLimit = sortedY.size();

	for(vector<Glass>::const_iterator it = glasses.begin(); it != glasses.end(); ++it){
		int 
			xIndex1 = binarySearch(sortedX, it->x1),
			xIndex2 = binarySearch(sortedX, it->x2),
			yIndex1 = binarySearch(sortedY, it->y1),
			yIndex2 = binarySearch(sortedY, it->y2),
			tintFactor = it->tint;

		for(int i = yIndex1; i < yIndex2; ++i){
			grid[i][xIndex1] += tintFactor;
			grid[i][xIndex2] += -tintFactor;
		}
	}

	for(int i = 0; i < yLimit; ++i){
		currentTint = 0;
		for(int j = 0; j < xLimit; ++j){
			currentTint += grid[i][j];
			if(currentTint >= T)
				//stretch the area back to its original size, and add into area
				//since the area might be greater than 2^32, so type cast (long long)
				answer += (long long) (sortedX[j + 1] - sortedX[j]) * (sortedY[i + 1] - sortedY[i]);
		}
	}

	printf("%llu\n", answer);

	return 0;
}