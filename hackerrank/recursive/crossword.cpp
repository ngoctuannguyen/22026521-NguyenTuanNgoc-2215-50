#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


vector<string> split_string(string s, char delimiter) {
    vector<string> list_string;
    string temp_str = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == delimiter) {
            list_string.push_back(temp_str);
            temp_str = "";
        } else {
            temp_str += s[i];
        }
    }
    if (!temp_str.empty()) {
        list_string.push_back(temp_str);
    }

    return list_string;
}

bool canPlaceHorizontally(vector<string>& grid, const string& word, int row, int col) {
    if (col + word.size() > 10) return false;
    for (int i = 0; i < word.size(); ++i) {
        if (grid[row][col + i] != '-' && grid[row][col + i] != word[i])
            return false;
    }
    return true;
}

bool canPlaceVertically(vector<string>& grid, const string& word, int row, int col) {
    if (row + word.size() > 10) return false;
    for (int i = 0; i < word.size(); ++i) {
        if (grid[row + i][col] != '-' && grid[row + i][col] != word[i])
            return false;
    }
    return true;
}

void placeHorizontally(vector<string>& grid, const string& word, int row, int col, vector<bool>& placed) {
    for (int i = 0; i < word.size(); ++i) {
        if (grid[row][col + i] == '-') {
            grid[row][col + i] = word[i];
            placed[i] = true;
        }
    }
}

void placeVertically(vector<string>& grid, const string& word, int row, int col, vector<bool>& placed) {
    for (int i = 0; i < word.size(); ++i) {
        if (grid[row + i][col] == '-') {
            grid[row + i][col] = word[i];
            placed[i] = true;
        }
    }
}

void removeHorizontally(vector<string>& grid, const string& word, int row, int col, const vector<bool>& placed) {
    for (int i = 0; i < word.size(); ++i) {
        if (placed[i]) {
            grid[row][col + i] = '-';
        }
    }
}

void removeVertically(vector<string>& grid, const string& word, int row, int col, const vector<bool>& placed) {
    for (int i = 0; i < word.size(); ++i) {
        if (placed[i]) {
            grid[row + i][col] = '-';
        }
    }
}

bool solveCrossword(vector<string>& grid, vector<string>& words, int index) {
    if (index == words.size()) return true;

    string word = words[index];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (canPlaceHorizontally(grid, word, i, j)) {
                vector<bool> placed(word.size(), false);
                placeHorizontally(grid, word, i, j, placed);
                if (solveCrossword(grid, words, index + 1)) return true;
                removeHorizontally(grid, word, i, j, placed);
            }
            if (canPlaceVertically(grid, word, i, j)) {
                vector<bool> placed(word.size(), false);
                placeVertically(grid, word, i, j, placed);
                if (solveCrossword(grid, words, index + 1)) return true;
                removeVertically(grid, word, i, j, placed);
            }
        }
    }
    return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> list_goal_word = split_string(words, ';');
    solveCrossword(crossword, list_goal_word, 0);
    return crossword;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
