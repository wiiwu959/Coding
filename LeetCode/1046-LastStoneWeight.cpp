/*
兩兩石頭相撞，撞完以後會留下兩個石頭重量差的小石頭 (abs(A - B))
要回傳最後留下的石頭重量
*/

// 用 priority queue
// 每次 pop O(log n) -> O(nlogn)
class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int& i: stones) {
            pq.push(i);
        }

        while (pq.size() > 2) {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            int bomb = first - second;
            if (bomb > 0) {
                pq.push(bomb);
            }
        }

        if (pq.size() == 1) {
            return pq.top();
        }

        int first = pq.top();
        pq.pop();
        return first - pq.top();

    }
};


// 若用最笨的方法，每次撞完都 sort 他的話
// sort 是 O(nlogn)，所以複雜度會是 O(n * nlogn) 超爛
class Solution {
public:
    static bool compare_reverse(int a, int b) {
        return a > b;
    }

    int lastStoneWeight(vector<int>& stones) {

        sort(stones.begin(), stones.end(), compare_reverse);
        while (stones.size() > 2) {
            int max_one = stones[0];
            int max_two = stones[1];

            int bump = max_one - max_two;
            stones.erase(stones.begin(), stones.begin() + 2);
            if (bump > 0) {
                stones.push_back(bump);
            }
            sort(stones.begin(), stones.end(), compare_reverse);
        }

        if (stones.size() == 1) {
            return stones[0];
        }

        return stones[0] - stones[1];

    }
};