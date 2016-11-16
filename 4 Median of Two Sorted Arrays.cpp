typedef long long ll;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
	ll l = 0, h = 0x7fffffff;
	while (l < h) {
		ll m = (l + h) / 2;
		vector<int>::iterator l1 = lower_bound(nums1.begin(), nums1.end(), m), l2 = lower_bound(nums2.begin(), nums2.end(), m);
		vector<int>::iterator h1 = upper_bound(nums1.begin(), nums1.end(), m), h2 = upper_bound(nums2.begin(), nums2.end(), m);
		int xiaoyu = (l1 - nums1.begin()) + (l2 - nums2.begin()), dayu = (h1 - nums1.begin()) + (h2 - nums2.begin());
		if (xiaoyu * 2 == n1 + n2) {
			int ra, rb;
			if (l1 == nums1.begin()) ra = *(l2 - 1);
			else if (l2 == nums2.begin()) ra = *(l1 - 1);
			else ra = max(*(l1 - 1), *(l2 - 1));
			if (l1 == nums1.end()) rb = *l2;
			else if (l2 == nums2.end())rb = *l1;
			else rb = min(*l1, *l2);
			return ((double)ra + rb) / 2;
		} else if (dayu * 2 == n1 + n2) {
			int ra, rb;
			if (h1 == nums1.begin()) ra = *(h2 - 1);
			else if (h2 == nums2.begin()) ra = *(h1 - 1);
			else ra = max(*(h1 - 1), *(h2 - 1));
			if (h1 == nums1.end()) rb = *h2;
			else if (h2 == nums2.end())rb = *h1;
			else rb = min(*h1, *h2);
			return ((double)ra + rb) / 2;
		}
		else if (xiaoyu * 2 < n1 + n2 && dayu * 2 > n1 + n2) return m;
		else if (xiaoyu * 2 >= n1 + n2)h = m - 1;
		else l = m + 1;
	}
	return l;
    }
};