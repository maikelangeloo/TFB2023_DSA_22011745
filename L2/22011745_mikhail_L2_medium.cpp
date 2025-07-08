#include <iostream>
#include <vector>
using namespace std;

// Helper function for Depth-First Search (DFS)
void dfs(vector<vector<int>>& image, int x, 
         int y, int oldColor, int newColor) {
    
    // Base case: check boundary conditions and color mismatch
    if (x < 0 || x >= image.size() || 
        y < 0 || y >= image[0].size() || 
        image[x][y] != oldColor) {
    // Backtrack if pixel is out of bounds or color doesn't match
        return; 
    }

    // Update the color of the current pixel
    image[x][y] = newColor;

    // Recursively visit all 4 connected neighbors
    dfs(image, x + 1, y, oldColor, newColor); 
    dfs(image, x - 1, y, oldColor, newColor); 
    dfs(image, x, y + 1, oldColor, newColor); 
    dfs(image, x, y - 1, oldColor, newColor); 
}

// Main flood fill function
vector<vector<int>> floodFill(
    vector<vector<int>>& image, int sr, 
    int sc, int newColor) {

    // If the starting pixel already has the new color,
    // no changes are needed
    if (image[sr][sc] == newColor) {
        return image;
    }

    // Call DFS to start filling from the source pixel
    int oldColor = image[sr][sc]; // Store original color
    dfs(image, sr, sc, oldColor, newColor);

    return image; // Return the updated image
}

// Driver code to test the flood fill function
int main() {
    // Input image (2D grid)
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };
    
    // Starting pixel (row, col)
    int sr = 1, sc = 2;
    
    // New color to apply
    int newColor = 2;        

    // Perform flood fill and get the result
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    // Print the updated image
    for (auto& row : result) {
        for (auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }
    return 0;
}
