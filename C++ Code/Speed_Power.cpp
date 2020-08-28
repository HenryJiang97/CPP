int mod = 1e9 + 7;

// Recurrsive
int qpow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 1) {
        return qpow(a, n - 1) * a % mod;
    }
    else {
        int temp = qpow(a, n / 2) % mod;
        return temp * temp % mod;
    }
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