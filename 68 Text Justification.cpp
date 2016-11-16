class Solution {
public:
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> ret;
	int pi = 0, pe;
	while (pi < words.size()) {
		pe = pi;
		int tl = words[pi].size();
		int twl = words[pi].size();
		while (tl <= maxWidth && pe<words.size()-1) {
			if (tl + 1 + words[pe + 1].size() > maxWidth)break;
			pe++;
			tl += words[pe].size() + 1;
			twl += words[pe].size();
		}
		string str = words[pi];
		if (pe == words.size() - 1 || pe == pi) {
			for (pi++; pi <= pe; pi++)str += " " + words[pi];
		}
		else {
			for (int i = 1; pi+i <= pe; i++) {
				if (i <= (maxWidth - twl) % (pe - pi))str += " ";
				for (int i = 0; i < (maxWidth - twl) / (pe - pi); i++)str += " ";
				str += words[pi + i];
			}
		}
		pi = pe + 1;
		while (str.size() < maxWidth)str += " ";
		ret.push_back(str);
	}
	return ret;
}
};