int mod = 1e9 + 7;

// Recurrsive
long long qpow(long long x, long long n) {
    if (n == 0)    return 1;
    
    long long res = 0;
    if (n % 2 == 0) {
        long long temp = qpow(x, n / 2);
        res = (temp * temp) % mod;
    } else {
        long long temp = qpow(x, n / 2);
        res = (temp * temp * x) % mod;
    }
    
    return res;
}


// Iterative
int qpow(int a, int n){
    int ans = 1;
    while(n) {
        if (n & 1)    ans *= a;
        a *= a;
        n = n >> 1;
    }
    return ans;
}