string nextPermutation(string s) {
    int n = s.length();
    
    // 1. From right to left, find the first num which violates the ascending or equal trend
    int a = n - 2;
    while (a >= 0 && s[a] >= s[a + 1])    a--;
    if (a < 0)    return "-1";
    
    // 2. From right to left, find the first num which is larger than nums[a]
    int b = n - 1;
    while (b > a && s[b] <= s[a])    b--;
    if (b <= a)    return "-1";
    
    // 3. Swap nums[a] with nums[b]
    swap(s[a], s[b]);
    
    // 4. Reverse the part after a
    int lo = a + 1, hi = n - 1;
    while (lo < hi) {
        swap(s[lo++], s[hi--]);
    }
    
    return s;
}