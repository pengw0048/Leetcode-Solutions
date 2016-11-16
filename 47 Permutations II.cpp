class Solution {
public:
    void go(vector<int>& nums,int pos,vector<vector<int>>& res,vector<int>& way,vector<bool>& mark){
        if(pos==nums.size()){
            res.push_back(way);
            return;
        }
        for(int i=0;i<nums.size();i++)if(mark[i]==false&&(i==0||nums[i-1]!=nums[i]||mark[i-1]==true)){
            mark[i]=true;
            way.push_back(nums[i]);
            go(nums,pos+1,res,way,mark);
            way.pop_back();
            mark[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> way;
        vector<bool> mark;
        for(auto n:nums)mark.push_back(false);
        sort(nums.begin(),nums.end());
        go(nums,0,res,way,mark);
        return res;
    }
};