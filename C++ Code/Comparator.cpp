bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}


struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};


sort(v.begin(), v.end(), [](T& a, T& b) {return a > b});