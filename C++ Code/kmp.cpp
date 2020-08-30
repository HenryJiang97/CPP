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
            while (j > 0 && p[i] != p[j])s    j = next[j];
            if (p[i] == p[j])    j++;
            next.push_back(j);
        }
        return next;
    }
};