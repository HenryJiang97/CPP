class quicksort {
public:
    void static qsort(vector<int>& arr, int lo, int hi) {
        if (lo >= hi)    return;
        int mid = partition(arr, lo, hi);

        qsort(arr, lo, mid - 1);
        qsort(arr, mid + 1, hi);
    }

private:
    int static partition(vector<int>& arr, int lo, int hi) {
        int pivot = arr[lo];
        int i = lo + 1, j = hi;

        while (true) {
            while (j >= lo + 1 && arr[j] >= pivot)    j--;
            while (i <= hi && arr[i] <= pivot)    i++;
            if (i >= j)    break;
            // Exchange arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }

        // Exchange pivot with arr[j];
        swap(arr[lo], arr[j]);
        
        return j;
    }
};


int main() {
    quicksort* qs = new quicksort();

    vector<int> arr{6, 2, 7, 3, 8, 9};
    int n = arr.size();

    // Quick sort
    qs->qsort(arr, 0, n - 1);

    // Print result
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
