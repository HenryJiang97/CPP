// Search for kth largest element in the array

class QuickSelect {
public:
    int quickSelect(vector<int>& nums, int lo, int hi, int k) {
        int pivot = nums[lo + (hi - lo) / 2];
        int i = lo, j = hi, p = lo;
        while (p <= j) {
            if (nums[p] < pivot) {
                swap(nums[p++], nums[i++]);
            } else if (nums[p] > pivot) {
                swap(nums[p], nums[j--]);
            } else {
                p++;
            }
        }
        if (hi - j >= k) {
            return quickSelect(nums, j + 1, hi, k);
        } else if (hi - (i - 1) >= k) {
            return pivot;
        } else {
            return quickSelect(nums, lo, i - 1, k - (hi - (i - 1)));
        }
    }
}