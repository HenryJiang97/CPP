class Solution {
    vector<int> kmp(string s, string p) {
        vector<int> res;
        auto next = buildNext(p);
        for (int i = 0, j = 0; i < s.length(); i++) {
            while (j > 0 && s[i] != p[j])    j = next[j];
            if (s[i] == p[j])    j++;
            if (j == p.length()) {
                res.push_back(i - p.length() + 1);
                j = next[j];
            }
        }
        return res;
    }

    // Build next array
    vector<int> buildNext(string p) {
        vector<int> next = {0, 0};
        for (int i = 1, j = 0; i < p.length(); i++) {
            while (j > 0 && p[i] != p[j])    j = next[j];
            if (p[i] == p[j])    j++;
            next.push_back(j);
        }
        return next;
    }
};



class Solution {
public:
    int strStr(string s, string p) {
        int ns = s.length(), np = p.length();
        
        vector<int> suffix = getSuffix(p);
        
        vector<int> dp(ns, 0);
        dp[0] = s[0] == p[0];
        
        for (int i = 1; i < ns; i++) {
            int j = dp[i - 1];
            while (j > 0 && s[i] != p[j]) {
                j = suffix[j - 1];
            }
            dp[i] = j + (s[i] == p[j]);
            if (dp[i] == np)    return i - np + 1;
        }
        
        return -1;
    }
    
private:
    vector<int> getSuffix(string p) {
        int np = p.length();
        vector<int> suffix(np, 0);
        for (int i = 1; i < np; i++) {
            int j = suffix[i - 1];
            while (j > 0 && p[j] != p[i]) {
                j = suffix[j - 1];
            }
            suffix[i] = j + (p[j] == p[i]);
        }
        return suffix;
    }
};