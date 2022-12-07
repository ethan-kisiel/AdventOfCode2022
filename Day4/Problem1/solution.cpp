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

bool isContained(vector<int> contained, vector<int> container)
{
    if (contained.at(0) >= container.at(0) && contained.at(1) <= container.at(1))
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

        if (isContained(vFirstSet, vSecondSet) || isContained(vSecondSet, vFirstSet))
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