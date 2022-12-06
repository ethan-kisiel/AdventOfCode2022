#include <iostream>
#include <fstream>
#include<vector>

using namespace std;
/*
string subString(int start, int stop, string& arr)
{
    string newString;

    for (int i = start; i < stop; i++)
    {
        newString.push_back(arr[i]);
    }

    return newString;
}
*/

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

char getBadge(vector<string> rucksacks)
{
    // the badge will be a shared value between
    // each of the strings
    
    string firstSack = rucksacks.at(0);
    string secondSack = rucksacks.at(1);
    string thirdSack = rucksacks.at(2);

     for (int i = 0; i < firstSack.size(); i++)
        {
            char currLetter = firstSack[i];
            if (secondSack.find(currLetter) != string::npos
            && thirdSack.find(currLetter) != string::npos)
            {
               return currLetter;
               break;
            }
        }

    for (int i = 0; i < 3; i++)
    {
        cout << rucksacks.at(i) << endl;
    }
    return '.';
}

int main()
{
    int score = 0; 
    string currLine;
    int lines = 0;
    vector<string> elfGroup;

    ifstream input("input");

    while (getline(input, currLine))
    {
        if (lines == 0)
        {
            cout << currLine << endl;
        }
        lines++;
        if (elfGroup.size() == 2)
        {
            elfGroup.push_back(currLine);
            // handle finding badges and score
            char currentBadge = getBadge(elfGroup);
            //cout << currentBadge << endl;
            score += calcScore(currentBadge);

            elfGroup = {};
        }
        else
        {
            elfGroup.push_back(currLine);
        }
    }

    input.close();

    cout << lines << endl;
    cout << score;

    return 0;
}