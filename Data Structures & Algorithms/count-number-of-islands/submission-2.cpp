class Solution {
    // This array stores the 4 directions we can move in the grid:
    // down, up, right, left
    int directions[4][2] = {
        {1, 0},   // move down  -> row + 1, same col
        {-1, 0},  // move up    -> row - 1, same col
        {0, 1},   // move right -> same row, col + 1
        {0, -1}   // move left  -> same row, col - 1
    };

public:
    // This function returns the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        // ROWS = number of rows in the grid
        // COLS = number of columns in the grid
        int ROWS = grid.size(), COLS = grid[0].size();

        // This will count how many islands we find
        int islands = 0;

        // Loop through every row
        for (int r = 0; r < ROWS; r++) {
            // Loop through every column in the current row
            for (int c = 0; c < COLS; c++) {
                // If this cell is land ('1'), we found a new island
                if (grid[r][c] == '1') {
                    // Run BFS starting from this land cell
                    // This will mark the entire island as visited
                    bfs(grid, r, c);

                    // Since this starting cell belonged to a new island,
                    // increase the island count
                    islands++;
                }
            }
        }

        // After checking the whole grid, return the total number of islands
        return islands;
    }

    // BFS function to explore all connected land cells starting at (r, c)
    void bfs(vector<vector<char>>& grid, int r, int c) {
        // Create a queue to process cells level by level
        // Each queue item stores a pair: {row, col}
        queue<pair<int, int>> q;

        // Mark the starting cell as visited by changing '1' to '0'
        // This prevents us from visiting it again
        grid[r][c] = '0';

        // Put the starting cell into the queue
        q.push({r, c});

        // Continue until there are no more cells left to process
        while (!q.empty()) {
            // Get the cell at the front of the queue
            auto node = q.front();

            // Remove it from the queue
            q.pop();

            // Extract row and column from the pair
            int row = node.first, col = node.second;

            // Check all 4 possible directions from the current cell
            for (int i = 0; i < 4; i++) {
                // Compute the neighboring row
                int nr = row + directions[i][0];

                // Compute the neighboring column
                int nc = col + directions[i][1];

                // Check that:
                // 1. nr is inside the grid
                // 2. nc is inside the grid
                // 3. the neighbor is land ('1')
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == '1') {
                    
                    // Add this neighboring land cell to the queue
                    q.push({nr, nc});

                    // Mark it as visited immediately
                    // so we do not add it to the queue more than once
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};