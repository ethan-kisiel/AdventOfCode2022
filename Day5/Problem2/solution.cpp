#include <iostream>
#include <vector>
#include <fstream>

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

void decryptStacks(string input, vector<string>& output)
{
    for (int i = 1; i <= 33; i+=4)
    {
        int currLetter = int(input[i]);
        if (currLetter >= 65 && currLetter <= 90)
        {
            output.at(i / 4).push_back(input[i]);
        }
        //cout << input[i] << ",";
    }
}

void swap(int x, string& from, string& to)
{
    string toAppend = subString((from.size()-x), from.size(), from);
    to.append(toAppend);

    for (int i = 0; i < x; i++)
    {
        if (from.length() == 0)
        {
            return;
        }

        
        from.pop_back();
    }
}

vector<int> getMove(string input)
{
    vector<int> move;
    cout << input << ": ";
    string moves = subString(input.find("move")+5, input.find(" from"), input);
    string from = subString(input.find("from")+5, input.find(" to"), input);
    string to = subString(input.length()-1, input.length(), input);
    
    cout << moves << "," << from << "," << to << endl;
    move.push_back(stoi(moves));
    move.push_back(stoi(from));
    move.push_back(stoi(to));

    return move;
}
/*
vector<int> splitString(string input)
{
    vector<string> instructions;
    int moves;
    int left;
    int right;
    string temp;
    int capturingSpace;
}
*/

int main()
{
    string currLine;

    ifstream input("input");

    vector<string> sortedStacks(9);

    vector<string> daStacks;
    
    bool readingStacks = true;

    while (getline(input, currLine))
    {
        if (currLine == "" && readingStacks)
        {
            // sort out da stacks
            
            for (int i = daStacks.size()-2; i >= 0; i--)
            {
                decryptStacks(daStacks.at(i), sortedStacks);
            }
            for (int i = 0; i < sortedStacks.size(); i++)
            {
                cout << sortedStacks.at(i) << endl;
            }
            readingStacks = false;

            continue;
        }

        if (readingStacks)
        {
            daStacks.push_back(currLine);
        }
        else
        {
            vector<int> move = getMove(currLine);
            swap(move.at(0), sortedStacks.at((move.at(1)-1)), sortedStacks.at(move.at(2)-1));
        }
    }
    input.close();

    string topBoxes = "";

    for (int i = 0; i < sortedStacks.size(); i++)
    {
        char box = sortedStacks.at(i)[sortedStacks.at(i).length() -1];
        topBoxes.push_back(box);
    }

    cout << topBoxes;
    return 0;
}