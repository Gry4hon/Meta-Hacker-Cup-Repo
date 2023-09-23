#include <iostream>
#include <vector>
#include <thread>
#include <map>

using std::cout;
using std::isspace;
using std::map;
using std::stoi;
using std::string;
using std::thread;
using std::vector;

string input = {"7 1 1 3 0 2 4 5 5 1 0 1 1 1 1 2 97 1 99 97 1 100 "};
vector<int> listOfCases = {};
vector<string> listOfAnswers = {};
int numberOfCases = 0;

void ConvertInput()
{
    string numberToAdd;

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

bool TestDecker(int ingredients[], int numberOfDecker)
{
    bool canBeDecker = true;

    int numberOfBuns = ingredients[0];
    int numberOfCheese = ingredients[1];
    int numberOfPatties = ingredients[2];

    for (int i = 0; i < numberOfDecker; i++)
    {
        if (i <= 0)
        {
            numberOfBuns -= 1;
            numberOfCheese -= 1;
            numberOfPatties -= 1;
            numberOfBuns -= 1;
        }
        else if (i > 0)
        {
            numberOfCheese -= 1;
            numberOfPatties -= 1;
            numberOfBuns -= 1;

            if (numberOfBuns <= 0)
        {
            cout<< "Made it here" << "\n";
            canBeDecker = false;    
            break;
        }
        }
    }

    return canBeDecker;
}

void TestTheCases(vector<int> cases)
{

    //[0] is buns [1] is cheese [2] is patties

    int listOfIngredients[] = {0, 0, 0};
    for (int s = 0; s < cases[0]; s++)
    {
        listOfIngredients[0] += 2;
        listOfIngredients[1] += 1;
        listOfIngredients[2] += 1;
    }

    for (int d = 0; d < cases[1]; d++)
    {
        listOfIngredients[0] += 2;
        listOfIngredients[1] += 2;
        listOfIngredients[2] += 2;
    }

    // cout << "Number of Ingredients: " << "\n";
    // cout << "Buns: " << listOfIngredients[0] << "\n";
    // cout << "Cheese: " << listOfIngredients[1] << "\n";
    // cout << "Patties: " << listOfIngredients[2] << "\n";
    // cout << "\n";

    bool isPossibleDecker = TestDecker(listOfIngredients, cases[0]);

    if (isPossibleDecker)
    {
        listOfAnswers.push_back("Yes");
    }
    else
    {
        listOfAnswers.push_back("No");
    }
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
            TestTheCases(testCases);
            numberOfCases++;
            testCases.clear();
        }
    }
}

int main()
{

    ConvertInput();
    ConvertListToTestCases();

    for (int i = 1; i <= numberOfCases; i++)
    {
        cout << "Case #" << i << ": " << listOfAnswers[i - 1] << "\n";
    }

    return 0;
}