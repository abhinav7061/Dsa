#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool isValid(int x, int y, int M, int N) {
    return (x >= 0 && x < M && y >= 0 && y < N);
}

bool isWord(vector<vector<char>> &board, const string &word, int x, int y, int pos, int M, int N) {
    // If the current character doesn't match the word character at 'pos', return false
    if (board[x][y] != word[pos])
        return false;

    // If we have reached the end of the word, return true
    if (pos == word.length() - 1)
        return true;

    // Save the current character and mark it as visited
    char temp = board[x][y];
    board[x][y] = '*';

    // Directions for x-coordinate (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    // Directions for y-coordinate (up, down, left, right)
    int dy[] = {0, 0, -1, 1};

    // Check all four directions for the next character of the word
    bool found = false;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isValid(nextX, nextY, M, N) && isWord(board, word, nextX, nextY, pos + 1, M, N)) {
            found = true;
            break;
        }
    }

    // Restore the current character
    board[x][y] = temp;

    return found;
}

public:
    bool exist(vector<vector<char>> &board, const string &word)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (isWord(board, word, i, j, 0, board.size(), board[0].size()))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution sl;
    bool res = sl.exist(board, word);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
