#include <cstdio>
#include <cmath>

class Vector
{
    public:
    	double x, y;
    	Vector(double _x = 0, double _y = 0){
    		x = _x;
    		y = _y;
    	}
    	Vector add(Vector a){
    		return Vector(x + a.x, y + a.y);
    	}
    	Vector subtract(Vector a){
    		return Vector(x - a.x, y - a.y);
    	}
    	Vector multiply(double a){
    		return Vector(a * x, a * y);
    	}
    	double magnitude(){
    		return sqrt(x * x + y * y);
    	}
    	double dot(Vector a){
    		return x * a.x + y * a.y;
    	}
    	Vector projection (Vector a){
    		return a.multiply(dot(a) / (a.magnitude() * a.magnitude()));
    	}
};

int n, corners, count;
bool outside, collison;
Vector start, end, c, w, l, csj;

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%lf %lf", &start.x, &start.y);

	scanf("%lf %lf", &end.x, &end.y);

	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		outside = true;
		collison = false;
		scanf("%d", &corners);
		l.x = 0;
		l.y = 0;
		for(int j = 0; j < corners; ++j){
			scanf("%lf %lf", &c.x, &c.y);
			csj = c.subtract(end);
			w = csj.subtract(csj.projection(start.subtract(end)));

			if(start.subtract(end).dot(csj) > 0 && end.subtract(start).dot(c.subtract(start)) > 0)
				outside = false;

			if(w.magnitude() < 0.001 || w.dot(l) < 0)
				collison = true;

			l = w;
		}
		if(!outside && collison)
			++count;
	}

	printf("%d\n", count);
	return 0;
}