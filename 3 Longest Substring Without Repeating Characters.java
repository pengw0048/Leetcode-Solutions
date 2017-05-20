public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.equals("")) return 0;
        boolean[] you = new boolean[256];
        int p = 0, ans = 1;
        you[s.charAt(0)] = true;
        for (int i = 1; i < s.length(); i++) {
            while (you[s.charAt(i)]) {
                you[s.charAt(p++)] = false;
            }
            you[s.charAt(i)] = true;
            ans = Math.max(ans, i - p + 1);
        }
        return ans;
    }
}
