class Solution {
public:
    int lengthOfLastWord(string s) {
        int p=s.size()-1,ans=0;
        while(p>=0&&s[p]==' ')p--;
        while(p>=0&&s[p--]!=' ')ans++;
        return ans;
    }
};