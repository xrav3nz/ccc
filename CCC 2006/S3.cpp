#include <cstdio>

#define MAX_N 100
#define MAX_CORNER 32
#define OFFSET 1001

#define max(a,b) ( (a) > (b) ? (a) : (b))
#define min(a,b) ( (a) < (b) ? (a) : (b))

struct Point
{
	int x, y;
}start, end;

struct Polygon
{
	int corner;
	Point corners[MAX_CORNER];
};

int n, count;
Polygon buildings[MAX_N];

void readPoint(Point &pt){
	scanf("%d %d", &pt.x, &pt.y);
	pt.x += OFFSET;
	pt.y += OFFSET;
	return ;
}

void readBuilding(Polygon &poly){
	scanf("%d", &poly.corner);
	for(int i = 0; i < poly.corner; ++i){
		scanf("%d %d", &poly.corners[i].x, &poly.corners[i].y);
		poly.corners[i].x += OFFSET;
		poly.corners[i].y += OFFSET;
	}
	return ;
}

bool ifIntersects(Point &start1, Point &end1, Point &start2, Point &end2){
	double a1, b1, c1, a2, b2, c2, x, y;

	a1 = end1.y - start1.y;
	b1 = start1.x - end1.x;
	c1 = a1 * start1.x + b1 * start1.y;

	a2 = end2.y - start2.y;
	b2 = start2.x - end2.x;
	c2 = a2 * start2.x + b2 * start2.y;

	double det = a1 * b2 - a2 * b1;

	//lines are parallel
	if(det == 0)
		return false;

	//the point where two lines intersect
	x = (b2 * c1 - b1 * c2) / det;
	y = (a1 * c2 - a2 * c1) / det;

	if(
		min(start1.x, end1.x) > x || max(start1.x, end1.x) < x || min(start1.y, end1.y) > y || max(start1.y, end1.y) < y ||
		min(start2.x, end2.x) > x || max(start2.x, end2.x) < x || min(start2.y, end2.y) > y || max(start2.y, end2.y) < y
		)
		return false;

	return true;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	readPoint(start);
	readPoint(end);

	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		readBuilding(buildings[i]);
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0, k = 1; j < buildings[j].corner; ++j, ++k){
			if(k == buildings[j].corner) k = 0;
			if(ifIntersects(start, end, buildings[i].corners[j], buildings[i].corners[k])){
				++count;
				break;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}