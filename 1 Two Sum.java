public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> pos = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (pos.containsKey(target - num)) {
                return new int[]{pos.get(target - num), i};
            }
            pos.put(num, i);
        }
        return null;
    }
}
