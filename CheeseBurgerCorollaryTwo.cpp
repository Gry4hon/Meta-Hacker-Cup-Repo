#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::isspace;
using std::stoi;
using std::string;
using std::vector;

string input = "7 1 1 3 0 2 4 5 5 1 0 1 1 1 1 2 97 1 99 97 1 100";
vector<int>listOfCases = {};
vector<string> listOfAnswers = {};

void ConvertInput()
{
    string numberToAdd;
    input += " ";

    for (int i = 0; i < input.length(); i++)
    {
        if (!isspace(input[i]))
        {
            numberToAdd += input[i];
        }
        else
        {
            int temp = stoi(numberToAdd);
            listOfCases.push_back(temp);
            numberToAdd = "";
        }
    }
}

void TestTheCase(vector<int> cases)
{
    //gunna write a comparrison that takes into account the deckers build with only singles, doubles, and both
    //and depending on which one is the highest, that is the one that returns for the output
    //alternativly, if there is one or all of them are equal to each other, then that number will be returned for the output

    int deckerWithSingles = round(cases[2]/cases[0]);
    

}

void ConvertListToTestCases()
{
    vector<int> testCases = {};

    for (int i = 1; i < listOfCases.size(); i++)
    {

        if (i % 3 != 0)
        {
            testCases.push_back(listOfCases[i]);
        }
        else
        {
            testCases.push_back(listOfCases[i]);
            TestTheCase(testCases);
            testCases.clear();
        }
    }
}

int main(){
    
    
    return 0;
}