#include <bits/stdc++.h>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    
    int bags, kids;
    for(int i = 1; i <= testcase; i++) {
        cin >> bags >> kids;
        int sum = 0;
        int candy;
        for(int j = 0; j < bags; j++) {
            cin >> candy;
            sum += candy;
        }
        int remain = sum % kids;
        cout << "Case #" << i << ": " << remain << endl;
    }
    return 0;
}