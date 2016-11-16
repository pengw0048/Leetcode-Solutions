public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var h=new Dictionary<string,IList<string>>();
        foreach(var s in strs){
            var count=new int[26];
            foreach(var c in s) count[c-'a']++;
            var t="";
            for(int i=0;i<26;i++)t+=count[i]+" ";
            if(!h.ContainsKey(t))h.Add(t,new List<string>());
            h[t].Add(s);
        }
        return (IList<IList<string>>)(h.Values.ToList());
    }
}