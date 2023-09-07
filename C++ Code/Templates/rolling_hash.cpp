typedef long long ll;
const ll mod = 100000000000007;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<int> set;
        ll headexp = 1
        for (int l = 1; l <= n / 2; l++) {
            headexp *= 26;
            headexp %= mod;
            ll hash1 = initHash(text, 0, l - 1);
            ll hash2 = initHash(text, l, 2 * l - 1);
            if (hash1 == hash2)    set.insert(hash1);
            for (int i = 1; i + 2 * l - 1 < n; i++) {
                hash1 = rehash(text, headexp, hash1, i - 1, i + l - 1);
                hash2 = rehash(text, headexp, hash2, i + l - 1, i + 2 * l - 1);
                if (hash1 == hash2)    set.insert(hash1);
            }
        }
        return set.size();
    }
    
private:
    ll initHash(string& text, int lo, int hi) {
        ll hash = 0;
        for (int i = lo; i <= hi; i++) {
            hash = (hash * 26 + (text[i] - 'a' + 1)) % mod;
        }
        return hash;
    }
    
    ll rehash(string& text, ll headexp, ll hash, int lo, int hi) {
        hash = (hash * 26 + (text[hi] - 'a' + 1)) % mod;
        hash = (hash - headexp * (text[lo] - 'a' + 1) % mod + mod) % mod;
        return hash;
    }
};


bool valid(string& s, int len) {
    if (len == 0)    return 1;
    long long hash = 0, k = 1;
    unordered_set<long long> set;
    for (int i = 0; i < len; i++) {
        hash = (hash * 26 + (s[i] - 'a' + 1)) % mod;
        k = k * 26 % mod;
    }
    set.insert(hash);
    for (int hi = len; hi < s.length(); hi++) {
        int lo = hi - len;
        hash = (hash * 26 + (s[hi] - 'a' + 1)) % mod;
        hash = (hash - k * (s[lo] - 'a' + 1) % mod + mod) % mod;
        if (set.count(hash) > 0)    return 1;
        set.insert(hash);
    }
    return 0;
}