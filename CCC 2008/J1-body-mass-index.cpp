// CCC 2008 J1 - Body Mass Index
// 
// basic math, and ifs
// 
// evaluate BMI using the given formula
// then use if to determine which category if falls into


#include <iostream>

using namespace std;

double weight, height, bmi;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> weight >> height;

	bmi = (weight) / (height * height);

	if (bmi > 25)
		printf("Overweight\n");
	else if (bmi < 18.5)
		printf("Underweight\n");
	else
		printf("Normal weight\n");

	return 0;
}