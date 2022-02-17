// 會給一連串的 [乘客數, 出發地, 目的地] 和車子的容量
// 要求能不能把所有人都載到點

// 用一個 map 來紀錄每個點的活動 (上車/下車的人數)
// 然後 map 會排好，所以可以直接去 traverse 他


class seat {
public:
    // true -> up
    // false -> down
    bool up_or_down;
    int people;
    
    seat(bool a, int b):
    up_or_down(a), people(b) {}
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int on_vehicle = 0;
        
        map<int, vector<seat>> recording;
        for(auto& trip: trips) {
            recording[trip[1]].emplace_back(true, trip[0]);
            recording[trip[2]].emplace_back(false, trip[0]);
        }
        
        for(auto& it: recording) {
            for(auto item: it.second) {
                if(item.up_or_down) {
                    on_vehicle += item.people;
                }
                else {
                    on_vehicle -= item.people;
                }
            }
            if(on_vehicle > capacity || on_vehicle < 0) {return false;}
        }
        return true;
    }
};