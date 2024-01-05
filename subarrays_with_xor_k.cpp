

//SC: O(1) and TC O(N^2)
int subarraysWithSumK(vector<int> A, int b) {

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            x = x ^ A[i];
            if (x == b) {
                cnt++;
            }
        }
    }

    return cnt;
}

//SC: O(n) and TC: O(N)
int subarraysWithSumK(vector<int> A, int b) {

    map<int, int>m;
    int x = 0;
    m[x]++;

    int cnt = 0;
    int n = A.size();

    for (int i = 0; i < n; i++) {
        x = x ^ A[i];
        cnt += m[x ^ b];
        m[x]++;
    }

    return cnt;
}
