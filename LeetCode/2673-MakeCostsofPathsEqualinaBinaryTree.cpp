/* 
需要讓一個 Binary Tree 的每個 node 的左右兩條 Path 的 cost 相同
算出需要最少替各個 node 加多少總值

可以用 DFS 每次只處理當前的 node 的左右
更深下去的 node 就直接讓下次的 function 處理
*/

class Solution {
public:

    int ans = 0;
    
    int getPath(int n, vector<int>& cost, int node) {
        if (node * 2 > n) {
            return cost[node - 1];
        }

        int left = getPath(n, cost, node * 2);
        int right = getPath(n, cost, node * 2 + 1);

        ans += abs(left - right);
        return cost[node - 1] + max(left, right);

    }
    
    int minIncrements(int n, vector<int>& cost) {
        getPath(n, cost, 1);
        return ans;
    }

    
};