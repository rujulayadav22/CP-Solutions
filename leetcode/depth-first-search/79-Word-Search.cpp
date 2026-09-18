class Solution {
public:

    bool funct(int row, int col, int index,
           vector<vector<char>>& board,
           string word,
           string& path) {

    if(index == word.size()) {
        return true;
    }

    if(row < 0 || row >= board.size() ||
       col < 0 || col >= board[0].size()) {
        return false;
    }

    if(board[row][col] != word[index]) {
        return false;
    }

    path.push_back(board[row][col]);

    char temp = board[row][col];
    board[row][col] = '#';

    if(funct(row - 1, col, index + 1, board, word, path))
        return true;

    if(funct(row + 1, col, index + 1, board, word, path))
        return true;

    if(funct(row, col - 1, index + 1, board, word, path))
        return true;

    if(funct(row, col + 1, index + 1, board, word, path))
        return true;

    board[row][col] = temp;
    path.pop_back();

    return false;
}

    bool exist(vector<vector<char>>& board, string word) {

        string path = "";

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {

                if(board[i][j] == word[0]) {

                    if(funct(i, j, 0, board, word, path)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};