int find(vector<int>& parent, int a) {
    if (parent[a] != a)
        parent[a] = find(parent, parent[a]);
    return parent[a];
}
    
void uni(vector<int>& parent, int a, int b) {
    int ra = find(parent, a), rb = find(parent, b);
    if (ra < rb)    parent[rb] = ra;
    else    parent[ra] = rb;
}