struct SegmentTree {
    SegmentTree* left;
    SegmentTree* right;
    int sum;
    int start;
    int end;
    SegmentTree(int s, int e) : sum(0), start(s), end(e), left(NULL), right(NULL) {}

public:
    void setStatus(int i, int j, int s) {
        if (i <= start && j >= end && left == NULL) {    // If the interval is included in [start, end]
            sum += s;
            return;
        }
        if (i > end || j < start)    return;    // The interval is outside [start, end]
        
        int mid = start + (end - start) / 2;
        if (left == NULL) {    // Create new left node
            left = new SegmentTree(left, mid);
            right = new SegmentTree(mid, right); 
        }
        
        left->setStatus(i, j, s);
        right->setStatus(i, j, s);
    }
};


SegmentTree* buildTree(vector<int>& nums, int lo, int hi) {
    if (lo > hi)    return NULL;
    SegmentTree* node = new SegmentTree(lo, hi);
    if (lo == hi) {
        node->sum = nums[lo];
        return node;
    }
    node->left = buildTree(nums, lo, lo + (hi - lo) / 2);
    node->right = buildTree(nums, lo + (hi - lo) / 2 + 1, hi);
    node->sum = node->left->sum + node->right->sum;
    return node;
}


void updateTree(SegmentTree* node, int i, int val) {
    if (i == node->start && node->start == node->end) {
        node->sum = val;
        return;
    }
    int mid = node->start + (node->end - node->start) / 2;
    if (i <= mid)    updateTree(node->left, i, val);
    else    updateTree(node->right, i, val);
    node->sum = node->left->sum + node->right->sum;
}


int query(SegmentTree* node, int lo, int hi) {
    if (node->start == lo && node->end == hi)
        return node->sum;
    int mid = node->start + (node->end - node->start) / 2;
    if (hi <= mid)    return query(node->left, lo, hi);
    else if (lo > mid)    return query(node->right, lo, hi);
    else    return query(node->left, lo, mid) + query(node->right, mid + 1, hi);
}