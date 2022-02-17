// 每次只動比較短的那一邊(因為會影響高的就是短邊)
class Solution {
public:
	int maxArea(vector<int>& height) {
		int area = 0;
		int head = 0;
		int tail = height.size() - 1;
		while (head != tail) {
			int width = tail - head;
			int temp;
			if (height[tail] > height[head]) {
				temp = height[head] * width;
				head += 1;
			}
			else {
				temp = height[tail] * width;
				tail -= 1;
			}

			if (temp > area) { area = temp; }
		}
		return area;
	}
};