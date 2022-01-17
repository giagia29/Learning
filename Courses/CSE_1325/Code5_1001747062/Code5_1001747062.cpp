//Name: Gia Dao.
//Student ID: 1001747062.
#include "House.h"
#include "TrickOrTreater.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <time.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void get_command_line_params(int argc, char *argv[], string& TOTfile, string& Housefile, string& Candyfile) //, std::string& InputFileName, std::string& OutputFileName)
{
    if (argc == 4)
    {
        TOTfile = argv[1];
        Housefile = argv[2];
        Candyfile = argv[3];
    }
    else
    {
        throw invalid_argument("\nMissing command line parameters.\n");
    }
}

int main(int argc, char *argv[])
{
    string TOTFilename, HouseFilename, CandyFilename;
    map<int, string> CandyRankingMap;
    string CandyLine;
    char CandyLineA[50] = {};
    string CandyName;
    int CandyRanking;
    char *CandyPtr = NULL;
    vector<House*> Houses;
    string HouseLine;
    vector<TrickOrTreater> TOTs;
    string TotLine;
    ostringstream HouseHeading;

    srand(time(NULL));

    try
    {
        get_command_line_params(argc, argv, TOTFilename, HouseFilename, CandyFilename);
    }
    catch (invalid_argument& ex)
    {
        cout << ex.what() << endl;
        exit(0);
    }
    ifstream TOTFH{TOTFilename};
    ifstream HouseFH{HouseFilename};
    ifstream CandyFH{CandyFilename};

    while(getline(CandyFH, CandyLine))
    {
        strcpy(CandyLineA, CandyLine.c_str());
        CandyPtr = strtok(CandyLineA, "|");
        CandyName = CandyPtr;
        CandyRanking = atoi(CandyPtr);
        CandyRankingMap.insert(make_pair(CandyRanking,CandyName));
    }
    CandyFH.close();

    HouseHeading << "          ";
    while(getline(HouseFH, HouseLine))
    {
        Houses.push_back(new House(HouseLine, CandyRankingMap));
        HouseHeading << HouseLine;
        for (int i = 0; i < 11 - HouseLine.length(); i++) HouseHeading << " ";
    }
    HouseHeading << endl << endl;
    HouseFH.close();

    while(getline(TOTFH, TotLine))
    {
        TOTs.push_back(TrickOrTreater{TotLine, Houses});
    }
    TOTFH.close();

    for (auto t : TOTs)
    {
        startThread();
    }

    while(TrickOrTreater::ImDone != TOTs.size())
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << HouseHeading.str();
        for (auto t : TOTs)
        {
            cout << getPath() << " " << getName() << endl;
        }
        this_thread::sleep_for(chrono::miliseconds(5));
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << HouseHeading.str();

    for (auto t : TOTs)
    {
        cout << getPath() << getName() << endl;
    }
    for (auto it : TOTs)
    {
        cout << it;
    }
    for (auto t : TOTs)
    {
        joinThread();
    }
    for (auto h : Houses)
    {
        delete(h);
    }
    return 0;
}
