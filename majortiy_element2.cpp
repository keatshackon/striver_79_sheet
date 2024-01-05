
//SC: O(n) and TC: O(nlog(n))
vector<int> majorityElement(vector<int> v) {

	map<int, int>m;

	int len = v.size();
	int j = len / 3;
	vector<int>ans;

	for (auto q : v) {
		m[q]++;
	}

	for (auto q : m) {
		if (q.second > j) {
			ans.push_back(q.first);
		}
	}

	return ans;
}

//SC: O(1) and TC: O(nlog(n))

