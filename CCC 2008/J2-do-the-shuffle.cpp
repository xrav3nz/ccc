// CCC 2008 J2 - Do the Shuffle

// simple string manipulation, and for loop (make the process easier)

#include <iostream>
#include <string>

using namespace std;

int button, num_times;
string playlist = "ABCDE";

void PressButton(){
	if (button == 1) {
		char first_song = playlist[0];
		// move song 2 ~ song 5 one place forward
		for (int i = 0; i < 4; ++i)				
			playlist[i] = playlist[i + 1];
		playlist[4] = first_song;
	} else if (button == 2) {
		char last_song = playlist[4];
		// move song 1 ~ song 4 one place backward
		for (int i = 4; i > 0; --i)
			playlist[i] = playlist[i - 1];
		playlist[0] = last_song;
	} else if (button == 3) {
		char first_song = playlist[0];
		playlist[0] = playlist[1];
		playlist[1] = first_song;
	}
	return ;
}

int main (int argc, char const *argv[]) {

	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> button >> num_times){
		if ((button == 4) && (num_times == 1))
			break;
		while (num_times--)
			PressButton();
	}

	for (int i = 0; i < 5; ++i)
		printf("%c%c", playlist[i], " \n"[i == 4]);

	return 0;
}