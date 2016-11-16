class Solution {
public:
    void go(int zuo,int sheng,string chuan,vector<string> &v){
        if(sheng==0&&zuo==0){v.push_back(chuan);return;}
        if(sheng>0)go(zuo+1,sheng-1,chuan+"(",v);
        if(zuo>0)go(zuo-1,sheng,chuan+")",v);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        go(0,n,"",v);
        return v;
    }
};