// Problem link - https://leetcode.com/problems/valid-sudoku/description/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // create 3 maps
        // row map, col map, 3*3 square map
        unordered_map<int, vector<int>> rowMap;
        unordered_map<int, vector<int>> colMap;
        unordered_map<int, vector<int>> squareMap;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0';

                // Check if num exists in row i
                if (find(rowMap[i].begin(), rowMap[i].end(), num) != rowMap[i].end())
                    return false;
                rowMap[i].push_back(num);

                // Check if num exists in col j
                if (find(colMap[j].begin(), colMap[j].end(), num) != colMap[j].end())
                    return false;
                colMap[j].push_back(num);

                // Check if num exists in square (i/3, j/3)
                int ind = 3 * (i / 3) + (j / 3);
                if (find(squareMap[ind].begin(), squareMap[ind].end(), num) != squareMap[ind].end())
                    return false;
                squareMap[ind].push_back(num);
            }
        }
        return true;
    }
};
