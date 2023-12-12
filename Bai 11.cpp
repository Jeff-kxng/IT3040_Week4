/*
Bài tập 11. Bảo vệ lâu đài
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long s;
    vector<vector<long>> a;

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        vector<long> tmp(3);
        cin >> tmp[0] >> tmp[1];
        tmp[2] = min(tmp[0], tmp[1]);
        a.push_back(tmp);
    }

    for (int i = 0; i < s; i++) {
        sort(a.begin(), a.end(), [](const vector<long> &a, const vector<long> &b) {
            return a[2] > b[2];
        });

        a[0][0] = (a[0][0] - a[0][1]) > 0 ? (a[0][0] - a[0][1]) : 0;
        a[0][2] = min(a[0][0], a[0][1]);
    }

    long long res = 0; // Initialize res as a long long variable to avoid overflow
    for (int i = 0; i < n; i++) {
        res += a[i][0];
    }

    cout << res;

    return 0;
}
