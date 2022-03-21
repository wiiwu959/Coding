#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase = 0;
    cin >> testcase;

    for (int i = 1; i <= testcase; i++) {
        string number;
        cin >> number;

        int total = 0;
        for (int loc = 0; loc < number.length(); loc++) {
            total += number[loc] - '0';
        }

        int insert = 9 - (total % 9);
        insert = (insert == 9) ? 0 : insert;

        bool flag = true;
        cout << "Case #" << i << ": ";
        int loc = 0;
        if (insert == 0) {
            cout << number[loc];
            loc++;
        }
        while (loc < number.length()) {
            if (insert < number[loc] - '0' && flag) {
                cout << insert;
                flag = false;
            }
            cout << number[loc];
            loc++;
        }

        if (flag) {
            cout << insert;
        }

        cout << endl;
        
    }
}