public class Solution {
        Dictionary<int, string> d = new Dictionary<int, string>();
        string go(string n)
        {
            var ret = "";
            n += "~";
            int p = 0;
            while (n[p] != '~')
            {
                var v = n[p];
                var c = 0;
                while (n[p] == v) { p++; c++; }
                ret += c;
                ret += v;
            }
            return ret;
        }
        public string CountAndSay(int n)
        {
            var s = "1";
            for (int i = 2; i <= n; i++)
            {
                if (d.ContainsKey(i)) s = d[i];
                else d[i] = s = go(s);
            }
            return s;
        }
}