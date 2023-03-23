/*
LeetCode problem #200: Number of Islands
https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number ofislands.
An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically. You may assume all four edges of the grid are all
surrounded by water.
*/

#include <vector>

using std::vector;


class Coords {
public:
    int row;
    int col;
    Coords(int row_, int col_) {
        row = row_;
        col = col_;
    }
    Coords operator + (const Coords& in) const {
        return Coords(row + in.row, col + in.col);
    }
};

class Map {
private:
    const vector<Coords> moves = {Coords(1,0), Coords(-1,0), Coords(0,1), Coords(0,-1)};

public:
    vector<vector<char>>& grid;
    Map(vector<vector<char>>& grid_) : grid(grid_) {
        dims.push_back(grid.size());

        if (dims[0] != 0) dims.push_back(grid[0].size());
    };
    vector<int> dims;
    void mark_island(const Coords c);
};

void Map::mark_island(const Coords c) {
    grid[c.row][c.col] = '*';

    for (auto it = moves.begin(); it != moves.cend(); it++) {
        Coords new_loc = c + *it;
        if (0 <= new_loc.row && new_loc.row < dims[0] && 0 <= new_loc.col && new_loc.col < dims[1] &&
            grid[new_loc.row][new_loc.col] == '1') {
            mark_island(new_loc);
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid);
};

int Solution::numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) return 0;

    int island_count = 0;
    Map m(grid);

    for (int row = 0; row < m.dims[0]; row++) {
        for (int col = 0; col < m.dims[1]; col++) {
            Coords new_loc(row, col);

            if (grid[new_loc.row][new_loc.col] == '1') {
                island_count++;
                m.mark_island(new_loc);
            }
        }
    }

    return island_count;
}