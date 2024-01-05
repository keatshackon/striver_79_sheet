
//SC: O(N) and TC: O(n log(n))
vector<int> findMissingRepeatingNumbers(vector < int > a) {

    map<int, int>m;

    int repeated = 0, missing = 0;

    for (auto q : a) {
        m[q]++;
    }
    int n = a.size();

    for (int i = 0; i < n; i++) {
        if (m.count(i + 1) == 0) {
            missing = i + 1;
        } else {
            if (m[a[i]] >= 2) {
                repeated = a[i];
            }
        }
    }


    return {repeated, missing};
}

// Sc: O(1) And TC: O(n)
vector<int> findMissingRepeatingNumbers(vector < int > a) {


    int repeated = 0, missing = 0;
    int x = 0;
    int n = a.size();

    for (int i = 1; i <= n; i++) {
        x ^= i;
    }

    for (int i = 1; i <= n; i++) {
        x ^= a[i - 1];
    }

    int c = x;
    int i = 0;
    int t = 1;

    while ((c & t) == 0 ) {
        i++;
        t = t << 1;
    }

    for (auto q : a) {
        if ((q & 1 << i) >= 1) {
            repeated ^= q;
        } else {
            missing ^= q;
        }
    }

    for (int k = 1; k <= n; k++) {
        if ((k & 1 << i) >= 1 ) {
            repeated ^= k;
        } else {
            missing ^= k;
        }
    }

    int f = 0;

    for (auto q : a) {
        if (q == repeated) {
            f = 1;
            break;
        }
    }

    if (f == 1) {
        return {repeated, missing};
    } else {
        return {missing, repeated};
    }
}