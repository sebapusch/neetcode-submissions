class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
        for (size_t ix = 0; ix < 9; ++ix)
        {
            vector<bool> present(9, false);
            for (size_t jx = 0; jx < 9; ++jx)
            {
                if (board[ix][jx] == '.')
                    continue;

                int val = board[ix][jx] - '0';
                
                if (present[val - 1]) 
                    return false;

                present[val - 1] = true;
            }
        }

        for (size_t ix = 0; ix < 9; ++ix)
        {
            vector<bool> present(9, false);
            for (size_t jx = 0; jx < 9; ++jx)
            {
                if (board[jx][ix] == '.')
                    continue;

                int val = board[jx][ix] - '0';
                
                if (present[val - 1]) 
                    return false;

                present[val - 1] = true;
            }
        }

        for (size_t ix = 0; ix < 9; ++ix)
        {
            cout << ix << ":\n";
            vector<bool> present(9, false);
            for (size_t jx = 0; jx < 9; ++jx)
            {
                size_t row = (ix / 3) * 3 + (jx / 3);
                size_t col = (ix % 3) * 3 + (jx % 3);

                
                cout << jx << ": " << row << " " << col << "\n";

                if (board[row][col] == '.')
                    continue;

                int val = board[row][col] - '0';

                if (present[val]) 
                    return false;

                present[val] = true;
            }
        }

        return true;
    }
};
