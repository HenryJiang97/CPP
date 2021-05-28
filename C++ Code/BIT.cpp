// Binary Index Tree

class FenwickTree {
    vector<int> prefix;

public:
    FenwickTree(int n) {
        prefix.resize(n + 1);
    }

    void update(int i, int x) {
        i++;
        while (i < prefix.size()) {
            prefix[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i) {    // Get the prefix sum of [1 : i]
        i++;
        int sum = 0;
        while (i > 0) {
            sum += prefix[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    int lowbit(int x) {
        return x & (-x);
    }
};