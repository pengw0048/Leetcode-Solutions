class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ret = "";
        int p = 0;
        while (p < strs[0].size()) {
            for (int i = 1; i < strs.size(); i++) if (strs[i][p] != strs[0][p]) return ret;
            ret += strs[0][p];
            p++;
        }
        return ret;
    }
};