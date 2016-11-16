public class Solution {
    public NestedInteger Deserialize(string s) {
        s += ',';
        var stack = new List<NestedInteger>();
        int pos = 0;
        long num = 0;
        bool neg = false;
        stack.Add(new NestedInteger());
        while (pos < s.Length) {
            if (s[pos] >= '0' && s[pos] <= '9') num = num * 10 + (s[pos] - '0');
            else if (s[pos] == '-') neg = true;
            else if (s[pos] == ',' && s[pos - 1] >= '0' && s[pos - 1] <= '9') {
                stack[stack.Count - 1].Add(new NestedInteger((int)(neg?-num:num)));
                num = 0;
                neg = false;
            } else if (s[pos] == '[') {
                var newList = new NestedInteger();
                stack[stack.Count - 1].Add(newList);
                stack.Add(newList);
            } else if (s[pos] == ']') {
                if (s[pos - 1] >= '0' && s[pos - 1] <= '9') {
                    stack[stack.Count - 1].Add(new NestedInteger((int)(neg?-num:num)));
                    num = 0;
                    neg = false;
                }
                stack.RemoveAt(stack.Count - 1);
            }
            pos++;
        }
        return stack[0].GetList()[0];
    }
}