// C++ program to find out the maximum length
// of a side of a square sub-matrix with all 1s.
#include <bits/stdc++.h>
using namespace std;

// Recursive function to find side of square 
// originating from i,j
int maxSquareRecur(int i, int j, vector<vector<int>> &mat, int &ans) {
    
    // Return 0 for invalid cells
    if (i<0 || i==mat.size() || j<0 || j==mat[0].size()) 
        return 0;
    
    // Find the side of square for right, bottom,
    // and diagonal cells.
    int right = maxSquareRecur(i, j+1, mat, ans);
    int down = maxSquareRecur(i+1, j, mat, ans);
    int diagonal = maxSquareRecur(i+1, j+1, mat, ans);
    
    // If mat[i][j]==0, then square cannot
    // be formed.
    if (mat[i][j]==0) return 0;
    
    // Side of square will be 
    int val = 1+min({right, down, diagonal});
    ans = max(ans, val);
    
    return val;
}

int maxSquare(vector<vector<int>> &mat) {

    int ans = 0;
    maxSquareRecur(0,0,mat, ans);
    return ans;
}

int main() {
    vector<vector<int>> mat = 
    {{0, 1, 1, 0, 1}, 
     {1, 1, 0, 1, 0},
     {0, 1, 1, 1, 0},
     {1, 1, 1, 1, 0},
     {1, 1, 1, 1, 1},
     {0, 0, 0, 0, 0}};
    cout << maxSquare(mat) << endl;

    return 0;
}