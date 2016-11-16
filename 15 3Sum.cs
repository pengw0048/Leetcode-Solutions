public class Solution {
        class MList<T> : List<T>
        {
            public override int GetHashCode()
            {
                return this[0].GetHashCode() + this[1].GetHashCode() * 195624456 + this[2].GetHashCode() * 43523;
            }
            public override bool Equals(object oobj)
            {
                var obj = oobj as MList<T>;
                return this[0] .Equals( obj[0]) && this[1] .Equals(obj[1]) && this[2] .Equals( obj[2]);
            }
        }
        public IList<IList<int>> ThreeSum(int[] nums)
        {
            var ret = new HashSet<IList<int>>();
            Array.Sort(nums);
            for(int i = 0; i < nums.Length; i++)
            {
                int target = -nums[i];
                int l = i+1, r = nums.Length - 1;
                while (l < r)
                {
                    if (nums[l] + nums[r] < target) l++;
                    else if (nums[l] + nums[r] > target) r--;
                    else
                    {
                        if (i != r && i != l && l != r) ret.Add(new MList<int>() { nums[i], nums[l], nums[r] });
                        if (nums[l] == nums[l + 1]) l++;
                        else r--;
                    }
                }
            }
            return ret.ToList();
        }

}