// C(n, k) = cnk[n][k]

vector<vector<int>> getCnk(int n) {
    const int mod = 1e9 + 7;
    vector<vector<int>> cnk(n + 1, vector<int>(n + 1, 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % mod;
        }
    }
    return cnk;
}


// Pascal's triangle
//         1
//       1   1
//      1  2  1
//    1  3  3  1
//   1 4   6  4 1
//  1 5 10  10 5 1
// 1 6 15 20 15 6 1