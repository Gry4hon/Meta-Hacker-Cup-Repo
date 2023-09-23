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

string input = "40 97 1 99 1 1 2 88 99 37 78 95 78 14 29 22 70 16 86 90 61 18 95 29 33 4 98 23 3 18 73 14 52 10 97 1 100 44 87 73 48 7 24 45 68 27 95 2 83 69 59 26 80 60 87 100 100 1 100 12 73 69 10 27 24 100 92 0 2 4 95 35 54 9 1 74 80 9 18 5 5 1 33 89 88 64 71 56 5 40 27 91 25 96 91 45 24 27 99 25 1 1 100 96 100 52 1 1 3 0 1 1 29 57 87 73 11 11 65 58 100";
vector<int>
    listOfCases = {};
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

bool TestDecker(int ingredients[], int numberOfDecker)
{
    bool canBeDecker = true;

    int numberOfBuns = ingredients[0];
    int numberOfCheese = ingredients[1];
    int numberOfPatties = ingredients[2];

    cout << "\n";
    cout << "# of decker: " << numberOfDecker << "\n";
    cout << "# of buns before: " << numberOfBuns << "\n";
    cout << "# of cheese before: " << numberOfCheese << "\n";
    cout << "# of patties before: " << numberOfPatties << "\n";

    for (int i = 0; i < numberOfDecker - 1; i++)
    {

        if (i == 0)
        {
            numberOfBuns -= 1;
            numberOfCheese -= 1;
            numberOfPatties -= 1;
            numberOfBuns -= 1;
        }

        numberOfCheese -= 1;
        numberOfPatties -= 1;
        numberOfBuns -= 1;

        if (numberOfBuns <= 0 && numberOfCheese > 0 && numberOfPatties > 0)
        {
            cout << "Made it here"
                 << "\n";
            canBeDecker = false;
            break;
        }
        else if (numberOfCheese < 0 || numberOfPatties < 0)
        {
            cout << "Made it here"
                 << "\n";
            canBeDecker = false;
            break;
        }
    }

    cout << "# of buns after: " << numberOfBuns << "\n";
    cout << "# of cheese after: " << numberOfCheese << "\n";
    cout << "# of patties after: " << numberOfPatties << "\n";
    cout << "\n";

    return canBeDecker;
}

void TestTheCase(vector<int> cases)
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

    bool isPossibleDecker = TestDecker(listOfIngredients, cases[2]);

    if (isPossibleDecker)
    {
        listOfAnswers.push_back("YES");
    }
    else
    {
        listOfAnswers.push_back("NO");
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
            TestTheCase(testCases);
            testCases.clear();
        }
    }
}

int main()
{

    ConvertInput();
    ConvertListToTestCases();

    for (int i = 1; i <= listOfCases[0]; i++)
    {
        cout << "Case #" << i << ": " << listOfAnswers[i - 1] << "\n";
    }

    return 0;
}