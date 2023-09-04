/*
計算在一個 nxn 的棋盤上，從 row, column 走了 k 步後還在棋盤上的機率
*/

// 一開始我用 DFS 去做，感覺應該是對的但是會 TLE
// 所以需要用一個 map 去記錄一下做過的 row, col, k
class Solution {
public:
    // key: {{row, column}, step}
    // value: probability
    map<pair<pair<int, int>, int>, double> record;
    double knightProbability(int n, int k, int row, int column) {
        return running(1, n, k, row, column);
    }

    double running(double prob, int n, int k, int row, int column) {
        if (row >= n|| row < 0 || column >= n || column < 0) {
            return 0.0;
        }
        
        if (k == 0) {
            return prob;
        }

        if (record.find({{row, column}, k}) != record.end()) {
            return record[{{row, column}, k}];
        }
        
        double total = 0;
        prob /= 8;
        total += running(prob, n, k - 1, row + 1, column + 2);
        total += running(prob, n, k - 1, row + 2, column + 1);
        total += running(prob, n, k - 1, row + 2, column - 1);
        total += running(prob, n, k - 1, row + 1, column - 2);
        total += running(prob, n, k - 1, row - 1, column - 2);
        total += running(prob, n, k - 1, row - 2, column - 1);
        total += running(prob, n, k - 1, row - 2, column + 1);
        total += running(prob, n, k - 1, row - 1, column + 2);
        
        record[{{row, column}, k}] = total;
        
        return total;
    }

};