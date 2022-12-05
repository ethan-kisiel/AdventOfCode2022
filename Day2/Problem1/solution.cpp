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
int calculateScore(char elfPlay, char myPlay)
{
    int elfScore = getCommonScore(elfPlay);
    int myScore = getCommonScore(myPlay);
    int difference = elfScore - myScore;

    //cout << elfPlay << " , " << myPlay << " : " << elfScore << " , " <<  myScore << endl;

    if (elfScore == myScore)
    {
        return 3 + myScore;
    }

    if (difference == 1 || difference == -2)
    {
        return myScore;
    }
    else
    {
        return 6 + myScore;
    }
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