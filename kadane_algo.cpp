long long maxSubarraySum(vector<int> arr, int n) {

    long long sum = 0;
    long long ans = 0;

    // O(n)
    for (int i = 0; i < n; i++) {

        sum += arr[i];
        ans = max(sum, ans);
        if (sum <= 0) {
            sum = 0;
        }
    }
    return ans;
}