#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase = 0;
    cin >> testcase;

    for (int i = 1; i <= testcase; i++) {
        unsigned long long from, to;
        cin >> from >> to;

        int count = 0;

        for (unsigned long long k = from; k <= to; k++) {
            unsigned long long sum = 0;
            unsigned long long product = 1;
            unsigned long long target = k;
            do {
                int check = target % 10;
                
                sum += check;
                product *= check;
                if (check == 0) {
                    break;
                }
            } while (target /= 10);
            
            if (product == 0 || product % sum == 0) {
                count ++;
            }
        }

        cout << "Case #" << i << ": " << count << endl;
    }
}