/*
實作一個 class 可以取得一個 array 中出現某 frequency 次的數字
*/

class FrequencyTracker {
private:
    unordered_map<int, int> freq_number;
    unordered_map<int, int> num_freq;
public:
    
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        freq_number[num_freq[number]]--;
        num_freq[number]++;
        freq_number[num_freq[number]]++;
    }
    
    void deleteOne(int number) {
        if (num_freq[number] > 0) {
            num_freq[number]--;
            freq_number[num_freq[number] + 1]--;
            freq_number[num_freq[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        if (freq_number[frequency] > 0) {
            return true;
        }
        
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */