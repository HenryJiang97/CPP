class SegTree {
public:
    int start, end;
    SegTree* left;
    SegTree* right;
    bool status;
    SegTree(int a, int b, bool s) : start(a), end(b), status(s), left(NULL), right(NULL) {}
        
    void setStatus(int a, int b, bool s) {
        if (a <= start && b >= end) {    // Interval [start, end] is included, set it to new status and remove children 
            remove(left);    remove(right);
            status = s;
            return;
        }
        if (b <= start || a >= end)    return;    // Out of the range, not the responsibility of current node
            
        int mid = start + (end - start) / 2;
        if (left == NULL) {    // Reach the leaf node, create new children
            left = new SegTree(start, mid, status);
            right = new SegTree(mid, end, status);
        }
            
        // Recurrsion
        left->setStatus(a, b, s);
        right->setStatus(a, b, s);
        status = left->status && right->status;
    }
        
    bool getStatus(int a, int b) {
        if (a <= start && b >= end)    return status;    // Current range of [start, end] is included in [a, b]
        if (b <= start || a >= end)    return true;    // Out of the range, not the responsibility of [start, end]
        if (left == NULL)    return status;    // Reach the leaf node of the tree
          
        // Recurrsion
        return left->getStatus(a, b) && right->getStatus(a, b);
    }
        
private:
    void remove(SegTree*& root) {
        if (root == NULL)    return;
        remove(root->left);    remove(root->right);
        delete root;
        root = NULL;
    }
};