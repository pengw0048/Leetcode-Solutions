public class Solution {
    public int[] TwoSum(int[] nums, int target) {
            var hs = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
                if (hs.ContainsKey(nums[i]))
                {
                    if (nums[i] * 2 == target) return new int[] { hs[nums[i]], i };
                }
                else hs.Add(nums[i], i);
            for (int i = 0; i < nums.Length; i++) if (hs.ContainsKey(target - nums[i]) && hs[target - nums[i]] != i)
                    return new int[] { i, hs[target - nums[i]] };
            return new int[] { };
    }
}