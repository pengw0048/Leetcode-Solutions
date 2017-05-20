class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (pos.count(target - num)) {
                vector<int> res;
                res.push_back(pos[target - num]);
                res.push_back(i);
                return res;
            }
            pos[num] = i;
        }
    }
};
