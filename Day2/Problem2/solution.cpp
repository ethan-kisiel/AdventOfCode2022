#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int getCommonScore(char play)
{
    if (play == 'A' || play == 'X')
    {
        return 1;
    }
    if (play == 'B' || play == 'Y')
    {
        return 2;
    }
    if (play == 'C' || play == 'Z') 
    {
        return 3;
    }
    return 0;
}
int calculateScore(char elfPlay, char strategy)
{
    int elfScore = getCommonScore(elfPlay);
    int strat = getCommonScore(strategy);
    int difference = elfScore - strategy;

    //cout << elfPlay << " , " << myPlay << " : " << elfScore << " , " <<  myScore << endl;

    // strategy is to draw
    if (strat == 2)
    {
        return 3 + elfScore;
    }

    // strategy is to lose
    if (strat == 1)
    {
        if (elfScore > 1)
        {
            return elfScore - 1;
        }

        return elfScore + 2;
    }

    // strategy is to win
    else
    {
        if (elfScore < 3)
        {
            return 6 + (elfScore+1);
        }
        return 6 + (elfScore-2);
    }

    return 0;
    /*
    2 beats 1 -> difference = 1
    3 beats 2 -> difference = 1
    1 beats 3 -> difference = -2
    */
}

int main()
{
    string currLine;
    ifstream input("input");

    int myScore = 0;

    while (getline(input, currLine))
    {
        char elfPlay = currLine[0];
        char myPlay = currLine[2];
        int score = calculateScore(elfPlay, myPlay);

        //cout << elfPlay << " , " << myPlay << " : " << score << endl;
        myScore += score;
    }
    cout << myScore;
    return 0;

}