#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(char target) {
    char vowel[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    char* end = vowel + sizeof(vowel) / sizeof(vowel[0]);
    if(find(vowel, end, target) != end) {
        return true;
    }
    return false;
}

string GetRuler(const string& kingdom) {
    // TODO: implement this method to determine the ruler name, given the kingdom.
    char endchar = kingdom[-1];
    string ruler = "";
    if(endchar == 'Y' || endchar == 'y') {
        ruler = "nobody";
    }
    else if(isVowel(endchar)) {
        ruler = "Alice";
    }
    else {
        ruler = "Bob";
    }
  
    return ruler;
}

int main() {
    int testcases;
    cin >> testcases;
    string kingdom;

    for (int t = 1; t <= testcases; ++t) {
        cin >> kingdom;
        cout << "Case #" << t << ": " << kingdom << " is ruled by "
                << GetRuler(kingdom) << ".\n";
    }
    return 0;
}
