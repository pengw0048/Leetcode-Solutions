class Solution {
public:
char os[10][5] = { " ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
int len[10] = { 1,0,3,3,3,3,3,4,3,4 };
void gen(string digits, string cur, int pos, vector<string> &ret) {
	if (pos == digits.size()) {
		ret.push_back(cur);
		return;
	}
	for (int i = 0; i < len[digits[pos]-'0']; i++) {
		gen(digits, cur + os[digits[pos]-'0'][i], pos + 1, ret);
	}
}
vector<string> letterCombinations(string digits) {
	vector<string> ret;
	if (digits == "")return ret;
	gen(digits, "", 0, ret);
	return ret;
}
};