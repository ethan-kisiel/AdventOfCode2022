
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

using namespace std;
//
// 1, 0, 0
// 1, 2, 0
// 1, 2, 3
int getLowIndex(vector<int>& threeElves)
{
    if (threeElves.at(0) <= threeElves.at(1) && threeElves.at(0) <= threeElves.at(2))
    {
        return 0;
    }
    if (threeElves.at(1) <= threeElves.at(0) && threeElves.at(1) <= threeElves.at(2))
    {
        return 1;
    }
    if (threeElves.at(2) <= threeElves.at(0) && threeElves.at(2) <= threeElves.at(1))
    {
        return 2;
    }
    return 0;
}

int main()
{
    string currLine;

    vector<int> topThreeElves(3);
    int thisElf = 0;

    ifstream input("input");
    
    while (getline(input, currLine))
    {
        if (currLine == "")
        {
            cout << "NEW LINE" << endl;
            int indexLowestElf = getLowIndex(topThreeElves);
            int checkAgainst = topThreeElves.at(indexLowestElf);

            if (thisElf > checkAgainst)
            {
                topThreeElves.at(indexLowestElf) = thisElf;
            }
            thisElf = 0;
        }
        else
        {
            thisElf += stoi(currLine);
        }
        cout 
        << topThreeElves.at(0)
        << ","
        << topThreeElves.at(1)
        <<","
        << topThreeElves.at(2)
        << endl;
    }

    input.close();

    int totalCalories = 0;
    for (int i = 0; i < 3; i++)
    {
        totalCalories += topThreeElves.at(i);
    }

    cout << totalCalories;
    return 0;        
}

// structure:
// check if the item is greater than the first element
//      check if there are less than 3 elements
//      if so, set it back one.
 
