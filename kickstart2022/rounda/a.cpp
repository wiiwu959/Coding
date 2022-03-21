#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase = 0;
    cin >> testcase;

    for (int i = 1; i <= testcase; i++) {
        string correct, typing;
        cin >> correct >> typing;

        int correct_head = 0;
        int typing_head = 0;
        int fix_time = 0;

        while (correct_head < correct.length() && typing_head < typing.length()) {
            if (correct[correct_head] == typing[typing_head]) {
                correct_head++;
                typing_head++;
            } else {
                typing_head++;
                fix_time++;
            }
        }

        if (correct_head < correct.length()) {
            fix_time = -1;
        }

        if (typing_head < typing.length() && correct[correct.length() - 1] == typing[typing_head - 1]) {
            fix_time += typing.length() - typing_head;
        }

        if (fix_time != -1) {
            cout << "Case #" << i << ": " << fix_time << endl;
        } else {
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
        }


    }
}