// 要實作一個 class 每次 add 都會回當前第 k 大的值
// 一開始是想用一個 vector + bubble sort 去維護
// 但有個叫做 priority_queue 的東西會一直保持 sorted，所以就用用看了

class KthLargest {
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto& num: nums)
            q.push(num);
            if(q.size() > k)
                q.pop();
    }
    
    
    int add(int val) {
        q.push(val);
        if(q.size() > kth)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */