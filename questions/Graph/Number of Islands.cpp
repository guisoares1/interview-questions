class Solution {
int n =0;
int m =0;
    
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(),
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // if you find a number 1, you wil find every 1's than is conected to it using a dfs algorithm
		if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
	// mark it with 0, to dont count again
        grid[i][j] = '0';
	// looking up, down, left and right 
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};