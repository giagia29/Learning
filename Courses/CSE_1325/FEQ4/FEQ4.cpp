#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

void get_command_line(int argc, char* argv[], string& PhoneFile)
{
    if (argc == 2)
    {
        PhoneFile = argv[1];
    }
    else
    {
        throw invalid_argument("Missing Command Line\n\n");
    }
}

int main(int argc, char* argv[])
{
    string PhoneFile;
    try
    {
        get_command_line(argc, argv, PhoneFile);
    }
    catch(invalid_argument& ex)
    {
        cout << ex.what() << endl;
    }
    ifstream FileInput{PhoneFile};
    string FileLine;
    vector<string> FileVector;
    if(FileInput.is_open())
    {
        while(getline(FileInput, FileLine))
        {
            FileVector.push_back(FileLine);
        }
    }
    FileInput.close();
    map<string,int> mp;
    for (int i = 0; i < FileVector.size(); i++)
    {
        string s1 = FileVector.at(i);
        string s2 = s1.substr(1,3);
        mp[s2]++;
    }
    for (auto x : mp)
    {
        cout << x.first << " - " << x.second << endl;
    }
    return 0;
}
