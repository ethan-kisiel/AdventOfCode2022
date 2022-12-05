#include <iostream>
#include <fstream>
#include<vector>

using namespace std;
string subString(int start, int stop, string& arr)
{
    string newString;

    for (int i = start; i < stop; i++)
    {
        newString.push_back(arr[i]);
    }

    return newString;
}

int calcScore(char entry)
{
    // check if capital
    int asciiVal = int(entry);
    if (asciiVal <= 90)
    {
        return asciiVal - 38;
    }
    else
    {
        return asciiVal - 96;
    }

    return 0;
}
int main()
{
    int score = 0; 
    string currLine;
    string itemTypes = "";

    ifstream input("input");

    while (getline(input, currLine))
    {
        int length = currLine.length();
        int midpoint = length / 2;

        string leftSack = subString(0, midpoint, currLine);
        string rightSack = subString(midpoint, length, currLine);

        for (int i = 0; i < leftSack.length(); i++)
        {
            char currLetter = leftSack[i];
            if (rightSack.find(currLetter) != string::npos)
            {
                score += calcScore(currLetter);
                break;
            }
        }
    }

    input.close();

    cout << itemTypes << endl;
    cout << score;

    return 0;
}