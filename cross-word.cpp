#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> split_string(string s, char delimiter)
{
    vector<string> list_string = {};
    string temp_str = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == delimiter)
        {
            list_string.push_back(temp_str);
            temp_str = "";
        }
        else
        {
            temp_str += s[i];
        }
    }

    return list_string;
}

bool checkSufficient(string blank, string word)
{
    // blank LP----OP
    // word  LPOPOIOP
    if (blank.length() != word.length())
        return false;

    for (int i = 0; i < blank.length(); i++)
        if (blank[i] != '-')
        {
            if (blank[i] != word[i])
                return false;
        }
    return true;
}

vector<string> fillHorizontal(vector<string> recentState,
                              int iRow, int iCol,
                              string word)
{
    int leftMostCol = iCol - 1;
    // +|LP-----L|+
    while (leftMostCol >= 0 && recentState[iRow][leftMostCol] != '+')
        leftMostCol--;

    int rightMostCol = iCol + 1;
    while (iCol < recentState[0].length() && recentState[iRow][rightMostCol] != '+')
        rightMostCol++;

    // +|LP-----L|+
    string recentBlank = "";
    for (int i = leftMostCol + 1; i < rightMostCol; i++)
        recentBlank += recentState[iRow][i];

    if (checkSufficient(recentBlank, word))
    {
        for (int i = leftMostCol + 1; i < rightMostCol; i++)
            recentState[iRow][i] = word[i - leftMostCol - 1];
        return recentState;
    }

    vector<string> nullNoti = {};
    return nullNoti;
}

vector<string> fillVertical(vector<string> state, int iRow, int iCol, string word)
{
    int upMostRow = iRow - 1;
    // +|LP-----L|+
    while (upMostRow >= 0 && state[upMostRow][iCol] != '+')
        upMostRow--;

    int downMostRow = iRow + 1;
    while (iRow < state.size() && state[downMostRow][iCol] != '+')
        downMostRow++;

    // +|LP-----L|+
    string recentBlank = "";
    for (int i = upMostRow + 1; i < downMostRow; i++)
        recentBlank += state[i][iCol];

    if (checkSufficient(recentBlank, word))
    {
        for (int i = upMostRow + 1; i < downMostRow; i++)
            state[i][iCol] = word[i - upMostRow - 1];
        return state;
    }

    vector<string> nullNoti = {};
    return nullNoti;
}

bool checkCompleteState(vector<string> state)
{
    for (string s : state)
    {
        for (char c : s)
            if (c == '-')
                return false;
    }
    return true;
}

vector<string> resultState = {};

void fillBlank(vector<string> recentState, vector<string> unusedWord)
{

    for (string s : recentState)
    {
        for (char c : s)
        {
            cout << c;
        }
        cout << endl;
    }
    cout << "-------------------------------\n";

    if (checkCompleteState(recentState))
    {
        resultState = recentState;
        return;
    }

    for (int iRow = 0; iRow < recentState.size(); iRow++)
    {
        for (int iCol = 0; iCol < recentState[0].length(); iCol++)
        {
            char c = recentState[iRow][iCol];
            if (c == '-')
            {
                for (int i = 0; i < unusedWord.size(); i++)
                {
                    vector<string> newState = fillHorizontal(recentState, iRow, iCol, unusedWord[i]);
                    if (newState.size() == recentState.size())
                    {
                        vector<string> newUnusedWord = {};
                        for (string word : unusedWord)
                            newUnusedWord.push_back(word);
                        newUnusedWord.erase(newUnusedWord.begin() + i);
                        fillBlank(newState, newUnusedWord);
                    }

                    newState = fillVertical(recentState, iRow, iCol, unusedWord[i]);
                    if (newState.size() == recentState.size())
                    {
                        vector<string> newUnusedWord = {};
                        for (string word : unusedWord)
                            newUnusedWord.push_back(word);
                        newUnusedWord.erase(newUnusedWord.begin() + i);
                        fillBlank(newState, newUnusedWord);
                    }
                }
            }
        }
    }
}

vector<string> crosswordPuzzle(vector<string> crossword, string words)
{
    // TO-DO
    // crossword 2-D
    // words ;
    vector<string> list_goal_word = split_string(words, ';');
    fillBlank(crossword, list_goal_word);

    for (string row : resultState)
    {
        for (char c : row)
        {
            cout << c;
        }
        cout << endl;
    }

    return crossword;
}

int main()
{
    vector<string> initState = {};
    for (int i = 0; i < 10; i++)
    {
        string s;
        cin >> s;
        initState.push_back(s);
    }
    string filledWord;
    cin >> filledWord;

    crosswordPuzzle(initState, filledWord);
}