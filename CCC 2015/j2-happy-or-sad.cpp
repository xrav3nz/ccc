#include <iostream>
#include <string>

using namespace std;

string input;
const string 
    HAPPY_EMOTICON(":-)"),
    SAD_EMOTICON(":-(");
size_t happy, sad;

int CountEmoticons(const string& reference,
                   const string& substring) {

  const size_t step = substring.size();

  size_t count(0);
  size_t pos(0) ;

  while( (pos=reference.find(substring, pos)) !=std::string::npos) {
    pos +=step;
    ++count ;
  }

  return count;

}

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    getline(cin, input);
    happy = CountEmoticons(input, HAPPY_EMOTICON);
    sad = CountEmoticons(input, SAD_EMOTICON);

    if (!happy && !sad) {
        cout << "none";
    } else if (happy > sad) {
        cout << "happy";
    } else if (happy < sad) {
        cout << "sad";
    } else {
        cout << "unsure";
    }
    cout << "\n";
    
    return 0;
}