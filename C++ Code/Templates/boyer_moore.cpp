// Boyer-Moore

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = -1, cnt = 0;
        for (int num : nums) {
            if (cnt == 0)    res = num;
            if (num == res)    cnt++;
            else    cnt--;
        }
        // Validation
        cnt = 0;
        for (int num : nums) {
            if (num == res)    cnt++;
        }
        return cnt > (n - 1) / 2 ? res : -1;
    }
};