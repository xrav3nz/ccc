// CCC 2009 J3 - Good Times

// be aware of how time "works", then this becomes a simple calculation problem

// If the "minute" is greater than 60, 
// add 1 to the "hour", and subtract 60 from "minute"

// If the "minute" is less than 0,
// minus 1 from the "hour", and add 100 to "minute"
// (because I considered 1 hour as 100 minutes in my calculation,
// it simplifies the process)

// If the "hour" is less than 0, add 24 to it

// If the "hour" is greater than 24, subtract 24 from it

#include <iostream>
#include <string>

using namespace std;

string places[7] = {
	"Ottawa",
	"Victoria",
	"Edmonton",
	"Winnipeg",
	"Toronto",
	"Halifax",
	"St. John's"
};

int difference[7] = {
	0,
	-300,
	-200,
	-100,
	0,
	100,
	130
};

int n;

int newTime(int i){
	int nTime = n + difference[i];
	int 
		hour = nTime / 100,
		min = nTime % 100;

	if(min >= 60){
		++hour;
		min -= 60;
	}else if(min < 0){
		--hour;
		min += 100;
	}

	if(hour < 0)
		hour += 24;
	else if(hour >= 24)
		hour -= 24;

	return hour * 100 + min;
}

int main(){
	
	ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> n;

	for(int i = 0; i < 7; ++i){
		cout << newTime(i) << " in " << places[i] << endl;
	}

	return 0;
}