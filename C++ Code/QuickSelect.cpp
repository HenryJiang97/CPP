// Search for kth smallest element in the array

class QuickSelect {
public:
    int quickSelect(vector<int>& nums, int lo, int hi, int k) {
        if (lo == hi)    return nums[lo];
        
        // Randomly pick one element as a pivot
        int pivot = lo + rand() % (hi - lo + 1);
        int j = partition(nums, lo, hi, pivot);
        
        if (k == j) {
            return nums[j];
        } else if (k < j) {
            return quickSelect(nums, lo, j - 1, k);
        } else {
            return quickSelect(nums, j + 1, hi, k);
        }
    }
    
    // Partition (same as the one in quicksort)
    int partition(vector<int>& nums, int lo, int hi, int pivot) {
        int val = nums[pivot];
        swap(nums[lo], nums[pivot]); 
        
        int i = lo + 1, j = hi;
        while (true) {
            while (j >= lo + 1 && nums[j] >= val)    j--;
            while (i <= hi && nums[i] <= val)    i++;
            if (i >= j)    break;
            swap(nums[i], nums[j]);
        }

        swap(nums[lo], nums[j]);
        
        return j;
    }
}