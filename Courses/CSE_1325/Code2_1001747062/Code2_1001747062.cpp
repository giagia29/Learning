//Name: Gia Dao, Student ID: 1001747062
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#define dicenum 5
#define facedie 6
#define numrolls 3
#define testrolls 23

using namespace std;

string outcome{};

string TestRollDice(vector<int> &dice);

void RollDice(vector<int> &RD)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < dicenum; i++)
    {
        RD.push_back(1 + (rand() % 6));
    }
}

void PrintRoll(vector<int> &RD)
{
    for (int x : RD)
    {
        cout << x << " ";
    }
    cout << endl;
}

void PickDice(vector<int> &RD)
{
    int count = 0;
    string keep{};
    srand(time(NULL));
    cout << "\nPick which dice to reroll. Answer Y at the prompt to keep that die.\n\n" << endl;
    for (int i = 0; i < RD.size(); i++)
    {
        cout << "Keep " << RD.at(i) << "? ";
        cin >> keep;
        if (keep == "y" || keep == "Y")
        {
            continue;
        }
        else if (keep == "n" || keep == "N")
        {
            RD.at(i) = 0;
        }
    }
    for (auto x = RD.begin(); x != RD.end(); ++x)
    {
        if(*x == 0)
        {
            count = count + 1;
            RD.erase(x);
            x--;
        }
    }
    for (int t = 1; t <= count; t++)
    {
        RD.push_back(1 + (rand() % 6));
    }
    cout << endl;
}

void FillHowMany(vector<int> RD, vector<int> &howMany)
{
    for (int &x : howMany)
    {
        x = 0;
    }

    for(int i : RD)
    {
        howMany[i - 1]++;
    }

    int ofAKind = 0, FullHouse = 0, TwoPair = 0, CPPSlam = 0, LargeStraight = 0, SmallStraight = 0;

    for (int i : howMany)
    {
        if (i == 3)
        {
            FullHouse = FullHouse + 3;
        }
        if (i == 2)
        {
            FullHouse = FullHouse + 2;
            TwoPair = TwoPair + 1;
        }
        if (i == 5)
        {
            CPPSlam = CPPSlam + 1;
        }
        if (i == 1)
        {
            LargeStraight = LargeStraight + 1;
        }
        else if ((i == 0 && LargeStraight > 0) && LargeStraight < 5)
        {
            LargeStraight = 0;
        }
        if (i >= 1)
        {
            SmallStraight = SmallStraight + 1;
        }
        else if ((i == 0 && SmallStraight > 0) && SmallStraight < 4)
        {
            SmallStraight = 0;
        }
        if (i == 4)
        {
            ofAKind = 4;
        }
        if (i == 3)
        {
            ofAKind = 3;
        }
    }

    if (LargeStraight == 5)
    {
        outcome = "Large Straight";
    }
    else if (SmallStraight >= 4)
    {
        outcome = "Small Straight";
    }
    else if (FullHouse == 5)
    {
        outcome = "Full House";
    }
    else if (CPPSlam == 1)
    {
        outcome = "C++Slam!";
    }
    else if (ofAKind == 4)
    {
        outcome = "Four of a Kind";
    }
    else if (ofAKind == 3)
    {
        outcome = "Three of a Kind";
    }
    else if (TwoPair == 2)
    {
        outcome = "Two Pair";
    }
    else
    {
        outcome = "You have nothing";
    }
}

int main(int argc, char *argv[])
{
    int x = 1, pass = 0, fail = 0;
    string answer;
    vector<int> RD;
    vector<int> howMany(facedie);
    if(argc == 1)
    {
        RollDice(RD);
        cout << "\n\nYou rolled ";
        PrintRoll(RD);
        FillHowMany(RD, howMany);
        cout << endl << outcome << endl;
        while(x <= numrolls)
        {
            cout << "\n\n\nDo you want to reroll? ";
            cin >> answer;
            if (answer == "n" || answer == "N")
            {
                exit(0);
            }
            if (answer == "y" || answer == "Y")
            {
                PickDice(RD);
                x = x + 1;
                cout << "\n\nYou rolled ";
                PrintRoll(RD);
                FillHowMany(RD, howMany);
                cout << endl << outcome << endl;
                continue;
            }
        }
    }
    else if (argc == 2)
    {
        string test = argv[1];
        if (test == "TEST")
        {
            for (int z = 1; z <= testrolls; z++)
            {
                    answer = TestRollDice(RD);
                    cout << "\n\nYou rolled ";
                    PrintRoll(RD);
                    cout << endl << answer << endl;
                    FillHowMany(RD, howMany);
                    if (answer == outcome)
                    {
                        cout << endl << "Test passed" << endl;
                        pass = pass + 1;
                    }
                    else
                    {
                        cout << endl << "Test failed" << endl;
                        fail = fail + 1;
                    }
            }
            if (fail == 0)
            {
                cout << endl << "Out of " << testrolls << " tests, " << pass << " tests passed and 0 tests failed." << endl;
            }
            else if (pass == 0)
            {
                cout << endl << "Out of " << testrolls << " tests, " << fail << " tests failed and 0 tests passed." << endl;
            }
            else
            {
                cout << endl << "Out of " << testrolls << " tests, " << pass << " tests passed and " << fail << " tests failed." << endl;
            }
        }
        else
        {
            RollDice(RD);
            PrintRoll(RD);
            FillHowMany(RD, howMany);
            cout << endl << outcome << endl;
            while(x <= numrolls)
            {
                cout << "\n\n\nDo you want to reroll? ";
                cin >> answer;
                if (answer == "n" || answer == "N")
                {
                    exit(0);
                }
                if (answer == "y" || answer == "Y")
                {
                    PickDice(RD);
                    x = x + 1;
                    cout << "\n\nYou rolled ";
                    PrintRoll(RD);
                    FillHowMany(RD, howMany);
                    cout << endl << outcome << endl;
                    continue;
                }
            }
        }
    }
}
