class Solution {
public:
    void go(vector<int>& cand, int sum, int target, vector<int>& stack, int pos, vector<vector<int>>& ret) {
        if(sum==target){
            ret.push_back(stack);
            return;
        }
        if(pos==cand.size())return;
        int tsum=sum,count=0;
        while(tsum<=target){
            go(cand,tsum,target,stack,pos+1,ret);
            count++;
            stack.push_back(cand[pos]);
            tsum+=cand[pos];
        }
        for(int i=0;i<count;i++)stack.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> stack;
        go(candidates, 0, target, stack, 0, ret);
        return ret;
    }
};