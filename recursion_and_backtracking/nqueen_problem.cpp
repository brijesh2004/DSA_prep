void solve(int col, int n, vector<int>& rowsUsed, vector<int>& d1, vector<int>& d2,
           vector<int>& current, vector<vector<int>>& res) {
    if (col == n) {
        res.push_back(current);
        return;
    }

    for (int row = 1; row <= n; ++row) {
        // indices for diagonals
        int diag1Index = row - col + n;
        int diag2Index = row + col;

        if (!rowsUsed[row] && !d1[diag1Index] && !d2[diag2Index]) {
            // Place
            rowsUsed[row] = 1;
            d1[diag1Index] = 1;
            d2[diag2Index] = 1;
            current.push_back(row);

            solve(col + 1, n, rowsUsed, d1, d2, current, res);

            // Backtrack
            current.pop_back();
            rowsUsed[row] = 0;
            d1[diag1Index] = 0;
            d2[diag2Index] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> res;
    vector<int> rowsUsed(n + 1, 0);    // rows 1..n
    vector<int> d1(2 * n + 1, 0);      // diag1 (i - j) + n
    vector<int> d2(2 * n + 1, 0);      // diag2 (i + j)

    vector<int> current;
    solve(0, n, rowsUsed, d1, d2, current, res);
    return res;
}



// second version''

 bool isValid(const vector<int>& perm) {
    int n = perm.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(perm[i] - perm[j]) == abs(i - j)) return false;
        }
    }
    return true;
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> res;
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i + 1;

    do {
        if (isValid(perm)) res.push_back(perm);
    } while (next_permutation(perm.begin(), perm.end()));

    return res;
    }