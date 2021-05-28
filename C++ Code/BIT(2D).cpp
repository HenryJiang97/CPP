// 2D Binary Index Tree

struct FenwickTree {
    vector<vector<int>> prefix;
    
    FenwickTree(int m, int n) {
        prefix = vector<vector<int>>(m + 1, vector<int>(n + 1));
    }
    
    void update(int i, int j, int x) {
        for (int ii = i + 1; ii < prefix.size(); ii += lowbit(ii)) {
            for (int jj = j + 1; jj < prefix[0].size(); jj += lowbit(jj)) {
                prefix[ii][jj] += x;
            }
        }
    }
    
    int query(int i, int j) {
        int sum = 0;
        for (int ii = i + 1; ii > 0; ii -= lowbit(ii)) {
            for (int jj = j + 1; jj > 0; jj -= lowbit(jj)) {
                sum += prefix[ii][jj];
            }
        }
        return sum;
    }
    
private:
    int lowbit(int x) {
        return x & (-x);
    }
};