#include <iostream>
#include <string>

int charCount[26];
std::string a, b;

bool isAnagram(){
	for(int i = 0; b[i]; ++i){
		if(b[i] == ' ')
			continue;
		if(charCount[b[i] - 'A'] == 0)
			return false;
		--charCount[b[i] - 'A'];
	}
	return true;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	std::getline(std::cin, a);
	std::getline(std::cin, b);
	for(int i = 0; a[i]; ++i){
		if(a[i] != ' ')
			++charCount[a[i] - 'A'];
	}
	if(isAnagram())
		std::cout << "Is an anagram.";
	else
		std::cout << "Is not an anagram.";
	return 0;
}