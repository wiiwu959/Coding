// 這題要想到 priority_queue 之後就會順利很多
// 用 prioroty_queue 來隨時記錄大於某數以上的數字的數量就很容易了

#include <bits/stdc++.h>
using namespace std;

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
    vector<int> h_index;
    // TODO: Calculate and return h-index score for each paper.
    priority_queue<int, vector<int>, greater<int>> recording;
    int h = 0;
    for (auto& cite: citations_per_paper) {
        if (cite > h) {
            recording.push(cite);
            while (recording.size() > h && recording.top() > h) {
                h++;
            }
        }

        h_index.push_back(h);
        
        while (!recording.empty() && recording.top() <= h) {
            recording.pop();
        }
    }
    return h_index;
}

int main() {
    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        // Get number of papers for this test case
        int paper_count;
        cin >> paper_count;
        // Get number of citations for each paper
        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++) {
            cin >> citations[i];
        }
        vector<int> answer = GetHIndexScore(citations);
        cout << "Case #" << test_case << ": ";
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Input: 
2
3
5 1 2
6
1 3 3 2 2 15

Output:
Case #1: 1 1 2
Case #2: 1 1 2 2 2 3
*/