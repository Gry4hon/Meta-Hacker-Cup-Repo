#include <iostream>
#include <vector>

using std::cout;
using std::isspace;
using std::stoi;
using std::string;
using std::vector;

string input = {"7 1 1 3 0 2 4 5 5 1 0 1 1 1 1 2 97 1 99 97 1 100 "};
vector<int> listOfCases = {};

void ConvertInput(){
    string numberToAdd;
    cout<< "Length of string: " << input[43] << "\n";
     for (int i = 0; i < input.length(); i++)
    {
        if (!isspace(input[i]))
        {
            numberToAdd += input[i];
        }
        else{
            int temp = stoi(numberToAdd);
            listOfCases.push_back(temp);
            numberToAdd = "";
        }
    }
}



int main()
{

    ConvertInput();
   

    for (int i = 1; i < listOfCases.size(); i++)
    {
        
        if(i % 3 != 0){
            cout<< "Item in list: " << listOfCases[i] << " ";
        }else{
            cout<< "Item in list: " << listOfCases[i] << "\n";
        }
    }
    

    return 0;
}