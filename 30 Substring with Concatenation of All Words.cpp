class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> count;
		for (string word : words)
			count[word]++;
		vector<int> ret;
		int cl = words[0].size(), ub = s.size() - words.size()*cl;
		for (int i = 0; i <= ub; i++) {
			unordered_map<string, int> you;
			for (int j = 0; j < words.size(); j++) {
				string sub = s.substr(i + j*cl, cl);
				if (count[sub]==0||you[sub] >= count[sub])goto nxt;
				you[sub]++;
			}
			ret.push_back(i);
		nxt:;
		}
		return ret;
	}
};