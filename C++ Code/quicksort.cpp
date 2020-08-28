using namespace std;

class quicksort {
public:
    void static qsort(int* arr, int lo, int hi) {
        if (lo >= hi)    return;
        int mid = partition(arr, lo, hi);

        qsort(arr, lo, mid - 1);
        qsort(arr, mid + 1, hi);
    }

private:
    int static partition(int* arr, int lo, int hi) {
        int pivot = arr[lo];
        int i = lo + 1, j = hi;

        while (true) {
            while (j >= lo + 1 && arr[j] >= pivot)    j--;
            while (i <= hi && arr[i] <= pivot)    i++;
            if (i >= j)    break;
            // Exchange arr[i] and arr[j]
            int temp = arr[j];    arr[j] = arr[i];    arr[i] = temp;
        }

        // Exchange pivot with arr[j];
        arr[lo] = arr[j];    arr[j] = pivot;
        return j;
    }
};


int main() {
    quicksort* qs = new quicksort();

    int arr[] = {6, 2, 7, 3, 8, 9};
    int n = sizeof(arr) / sizeof(*arr);

    // Quick sort
    qs->qsort(arr, 0, n - 1);

    // Print result
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
