#include<set>

// Basic appraoche or worst case time complexity o(n^3)
vector<vector<int>> triplet(int n, vector<int> &arr) {

    vector<vector<int>>ans;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((arr[i] + arr[j] + arr[k]) == 0) {
                    s.insert({arr[i], arr[j], arr[k]});
                }
            }
        }
    }

    return ans;
}


// optimised appraoche O(n^2 * log(n))

#include<set>
vector<vector<int>> triplet(int n, vector<int> &arr) {


    sort(arr.begin(), arr.end());
    set<vector<int>>s;
    vector<vector<int>>ans;

    // O(n ^ 2 * log(n))
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == 0) {
                s.insert({arr[i], arr[j], arr[k]});
                j++;
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    for (auto q : s) {
        ans.push_back(q);
    }

    return ans;
}
