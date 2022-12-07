#include <iostream>
#include <fstream>
#include <vector>

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

bool doesOverlap(vector<int> testOne, vector<int> testTwo)
{
    bool oneOverlapTwo = (testOne.at(0) >= testTwo.at(0) && testOne.at(0) <= testTwo.at(1));
    bool twoOverlapOne = (testOne.at(1) >= testTwo.at(0) && testOne.at(1) <= testTwo.at(1));

    if (oneOverlapTwo || twoOverlapOne)
    {
        return true;
    }

    return false;
}

int main()
{
    int fullOverlaps = 0;

    string currLine;
    ifstream input("input");

    while (getline(input, currLine))
    {
        int commaIndex = currLine.find(',');
        string firstSet = subString(0, commaIndex, currLine);
        string secondSet = subString(commaIndex+1, currLine.length(), currLine);

        vector<int> vFirstSet;
        vector<int> vSecondSet;

        int iFirstSetDelim = firstSet.find('-');
        int iSecondSetDelim = secondSet.find('-');

       // push back the integer version of each half of each set
        vFirstSet.push_back(stoi(subString(0, iFirstSetDelim, firstSet)));
        vFirstSet.push_back(stoi(subString(iFirstSetDelim+1, firstSet.length(), firstSet)));

        vSecondSet.push_back(stoi(subString(0, iSecondSetDelim, secondSet)));
        vSecondSet.push_back(stoi(subString(iSecondSetDelim+1, secondSet.length(), secondSet)));

        cout << "FIRST: " << vFirstSet.at(0) << "-" << vFirstSet.at(1) << endl;
        cout << "SECOND: " << vSecondSet.at(0) << "-" << vSecondSet.at(1) << endl;

        if (doesOverlap(vFirstSet, vSecondSet) || doesOverlap(vSecondSet, vFirstSet))
        {
            fullOverlaps++;
        }

    }

    vector<int> left = {1, 5};
    vector<int> right = {2, 8};

    input.close();

    cout << fullOverlaps;
    return 0;
}