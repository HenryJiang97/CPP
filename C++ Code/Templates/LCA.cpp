int layer[10001];
int parent[10001];
int ancestor[10001][18];


void buildAncestor() {
    for (int i = 0; i < n; i++) {
        ancestor[i][0] = parent[i];
    }
    ancestor[0][0] = 0;
    int m = (ceil)(log(n) / log(2));
    for (int j = 1; j <= m; j++) {
        for (int i = 0; i < n; i++) {
            ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
        }
    }
}


int getLCA(int a, int b) {
    if (layer[a] > layer[b]) {
        a = getKthAncestor(a, layer[a] - layer[b]);
    } else if (layer[a] < layer[b]) {
        b = getKthAncestor(b, layer[b] - layer[a]);
    }
    
    int lo = 0, hi = layer[a];
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (getKthAncestor(a, mid) == getKthAncestor(b, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return getKthAncestor(a, hi);
}

int getKthAncestor(int a, int k) {
    int cur = a;
    for (int j = 0; j < 18; j++) {
        if ((k >> j) & 1) {
            cur = ancestor[cur][j];
        }
    }
    return cur;
}