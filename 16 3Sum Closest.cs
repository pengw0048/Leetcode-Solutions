public class Solution {
        public int ThreeSumClosest(int[] nums, int target)
        {
            var ret = nums[0] + nums[1] + nums[2];
            Array.Sort(nums);
            for(int i = 0; i < nums.Length; i++)
            {
                int l = i+1, r = nums.Length - 1;
                while (l < r)
                {
                    if (Math.Abs(nums[i] + nums[l] + nums[r] - target) < Math.Abs(ret - target))
                        ret = nums[i] + nums[l] + nums[r];
                    if (nums[i] + nums[l] + nums[r] < target) l++;
                    else if (nums[i] + nums[l] + nums[r] > target) r--;
                    else return target;
                }
            }
            return ret;
        }

}