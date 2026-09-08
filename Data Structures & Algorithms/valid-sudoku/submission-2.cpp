class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
        for (size_t ix = 0; ix < 9; ++ix)
        {
            vector<bool> cols(9, false);
            vector<bool> rows(9, false);
            vector<bool> quad(9, false);

            for (size_t jx = 0; jx < 9; ++jx)
            {
                if (board[ix][jx] != '.')
                {
                    int val = board[ix][jx] - '0';
                    
                    if (cols[val - 1]) 
                        return false;

                    cols[val - 1] = true;
                }

                if (board[jx][ix] != '.')
                {
                    int val = board[jx][ix] - '0';

                    if (rows[val - 1])
                        return false;

                    rows[val - 1] = true;
                }

                size_t row = (ix / 3) * 3 + (jx / 3);
                size_t col = (ix % 3) * 3 + (jx % 3);

                if (board[row][col] != '.')
                {
                    int val = board[row][col] - '0';

                    if (quad[val - 1])
                        return false;

                    quad[val - 1] = true;
                }
            }
        }

        return true;
    }
};
