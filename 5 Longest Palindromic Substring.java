public class Solution {
    public static String longestPalindrome(String s) {
        char[] c = s.toCharArray();
        int bs = 0, bv = 1;
        for (int i = 0; i < c.length; i++) {
            int l = i, r = i;
            while (l > 0 && r < c.length - 1 && c[l-1] == c[r+1]) {
                l--;
                r++;
            }
            if (r - l + 1 > bv) {
                bv = r - l + 1;
                bs = l;
            }
            l = i;
            r = i - 1;
            while (l > 0 && r < c.length - 1 && c[l-1] == c[r+1]) {
                l--;
                r++;
            }
            if (r - l + 1 > bv) {
                bv = r - l + 1;
                bs = l;
            }
        }
        return s.substring(bs, bs + bv);
    }
}
