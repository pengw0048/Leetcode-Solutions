class Hasher
{
public:
	size_t operator() (const vector<int> & key) const
	{
		size_t hash = 0;
		for (size_t i = 0; i<key.size(); i++)
		{
			hash += (71 * hash + key[i]) % 100000007;
		}
		return hash;
	}
};
class EqualFn
{
public:
	bool operator() (const vector<int> & t1, const vector<int> & t2) const
	{
		if (t1.size() != t2.size())return false;
		for (int i = 0; i < t1.size(); i++)if (t1[i] != t2[i])return false;
		return true;
	}
};

class Solution {
public:
void go(vector<int>& cand, int sum, int target, vector<int>& stack, int pos, unordered_set<vector<int>,Hasher,EqualFn>& ret) {
	if (sum == target) {
		ret.insert(stack);
		return;
	}
	if (pos == cand.size())return;
	int tsum = sum, count = 0;
	while (tsum <= target && count<2) {
		go(cand, tsum, target, stack, pos + 1, ret);
		count++;
		stack.push_back(cand[pos]);
		tsum += cand[pos];
	}
	for (int i = 0; i<count; i++)stack.pop_back();
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	unordered_set<vector<int>,Hasher,EqualFn> ret;
	vector<int> stack;
	go(candidates, 0, target, stack, 0, ret);
	vector<vector<int>> vret;
	for (auto v : ret) vret.push_back(v);
	return vret;
}
};