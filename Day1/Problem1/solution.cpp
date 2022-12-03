#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    string currLine;

    int mostCalories = 0;
    int currentCalories = 0;


    ifstream input("input"); 

    while (getline (input, currLine))
    {
        if (currLine == "")
        {
            if (currentCalories > mostCalories)
            {
                mostCalories = currentCalories;
            }
            currentCalories = 0;
        }
        else
        {
            currentCalories += stoi(currLine);
        }
    }
    
    cout << mostCalories;

    return 0;        
}

