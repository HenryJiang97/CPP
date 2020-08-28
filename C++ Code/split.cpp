class Solution {  
private:
    vector<string> split(string s) {
		s += ' ';
        vector<string> res;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                res.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        return res;
    }
};