//Name: Gia Dao, Student ID: 1001747062
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CokeMachine.h"
#include "CokeLib.h"

using namespace std;

enum Action
{
    ReturnChange,
    NotEInventory,
    NotEChange,
    InsufficientFund,
    ExactChange,
    MaxChange,
};

void Menu()
{
    cout << "\n\n0. Walk away";
    cout << "\n\n1. Buy a Coke";
    cout << "\n\n2. Restock Machine";
    cout << "\n\n3. Add change";
    cout << "\n\n4. Display Machine Info";
    cout << "\n\n5. Update Machine Name";
    cout << "\n\n6. Update Coke Price";
}

int main(int argc, char* argv[])
{
    int option, pay, addchange, addinventory, newprice;
    int action, choice;
    bool check, cokeline;
    string change = "", newname, input, output, result;
   //CokeMachine MyCokeMachine;
    vector<CokeMachine> SetOfCokeMachines;
    vector<string> ConstructorValues(4);

    try
    {
        get_command_line_params(argc, argv, input, output);
    }
    catch (invalid_argument& ex)
    {
        cout << ex.what() << endl;
        exit(0);
    }

    ifstream CokeInputFile{input};
    string CokeMachineLine;
    if(CokeInputFile.is_open())
    {
        while(!CokeInputFile.eof())
        {
            getline(CokeInputFile,CokeMachineLine);
            cokeline = ParseCokeLine(CokeMachineLine, ConstructorValues);
            if (cokeline == true)
            {
                CokeMachine temporary{ConstructorValues.at(0),stoi(ConstructorValues.at(1)),stoi(ConstructorValues.at(2)),stoi(ConstructorValues.at(3))};
                SetOfCokeMachines.push_back(temporary);
            }
        }
    }
    else
    {
        cout << "\n\nUnable to open file" << endl;
        exit(0);
    }
    CokeInputFile.close();

    cout << "\n\nPick a Coke Machine:\n\n";
    cout << "0. Exit\n\n";
    for (int i = 0; i < SetOfCokeMachines.size(); i++)
    {
            cout << i + 1 << ". " << SetOfCokeMachines[i].getMachineName() << endl << endl;
    }
    cout << SetOfCokeMachines.size() + 1 << ". Add a new machine" << endl << endl;
    cout << "Enter choice: ";
    cin >> choice;

    ofstream CokeOutputFile{output};

    while(0 <= choice && choice <= SetOfCokeMachines.size() + 1)
    {
        if (choice == 0)
        {
            for (auto x : SetOfCokeMachines)
            {
                result = CreateCokeOutputLine(x);
                CokeOutputFile << result << "\n";
            }
            CokeOutputFile.close();
            return 0;
        }
        if (choice == SetOfCokeMachines.size() + 1)
        {
            if (choice > 0)
            {
                CokeMachine MyCokeMachine;
                SetOfCokeMachines.push_back(MyCokeMachine);
                cout << "\n\nNew machine added\n\n";
            }
            cout << "\n\nPick a Coke Machine:\n\n";
            cout << "0. Exit\n\n";
            for (int i = 0; i < SetOfCokeMachines.size(); i++)
            {
                cout << i + 1 << ". " << SetOfCokeMachines.at(i).getMachineName() << endl << endl;
            }
            cout << SetOfCokeMachines.size() + 1 << ". Add a new machine" << endl << endl;
            cout << "Enter choice: ";
            cin >> choice;
        }

        if (0 < choice && choice < SetOfCokeMachines.size() + 1)
        {
            Menu();
            cout << "\n\n\nChoose an option: ";
            cin >> option;

            while(option < 0 || option > 6)
            {
                cin.fail();
                cin.clear();
                cin.ignore(32767,'\n');
                cout << "\n\n\nOption is not available. Please choose again: ";
                cin >> option;
                if (option == 0) cout << "\n\nAre you sure you aren't really thirsty and need a Coke?" << endl << endl;
            }

            while(option > 0 && option <= 6)
            {
                if (option == 1)
                {
                    cout << "\n\nInsert payment: ";
                    cin >> pay;
                    check = SetOfCokeMachines.at(choice - 1).buyACoke(pay, change, action);
                    if (check == true && action == ReturnChange)
                    {
                        cout << "\n\nHere is your Coke and your change of " << change << endl << endl;
                    }
                    else if (check == true && action == ExactChange)
                    {
                        cout << "\n\nThank you for your exact change. Here is your Coke." << endl << endl;
                    }
                    else if (check == false && action == InsufficientFund)
                    {
                        cout << "\n\nInsufficient payment...returning your payment." << endl << endl;
                    }
                    else if (check == false && action == NotEChange)
                    {
                        cout << "\n\nUnable to give change at this time...returning your payment." << endl << endl;
                    }
                    else if (check == false && action == NotEInventory)
                    {
                        cout << "\n\nThe machine does not have that many Coke." << endl << endl;
                    }
                    else if (check == false && action == MaxChange)
                    {
                        cout << "\n\nChange box is full - call 1800IMFULL to remove change...returning your payment." << endl << endl;
                    }
                    else
                    {
                        cout << "\n\nThe Coke machine is out of order." << endl << endl;
                    }
                }
                else if (option == 2)
                {
                    cout << "\n\nHow many product are you adding to the machine? ";
                    cin >> addinventory;
                    if (SetOfCokeMachines.at(choice - 1).incrementInventory(addinventory) == true)
                    {
                        cout << "\n\nYour machine has been restocked.\n";
                        cout << "\n\nYour inventory level is now: " << SetOfCokeMachines.at(choice - 1).getInventoryLevel() << endl;
                    }
                    else
                    {
                        cout << "\n\nYou have exceeded your machine's max inventory capacity" << endl << endl;
                        cout << "\n\nYour inventory level is now: " << SetOfCokeMachines.at(choice - 1).getInventoryLevel() << endl;
                    }
                }
                else if (option == 3)
                {
                    cout << "\n\nHow much change are you adding to the machine? ";
                    cin >> addchange;
                    if (SetOfCokeMachines.at(choice - 1).incrementChangeLevel(addchange) == true)
                    {
                        cout << "\n\nYour change has been updated.\n";
                        cout << "\n\nYour change level is now: " << SetOfCokeMachines.at(choice - 1).getChangeLevel();
                    }
                    else
                    {
                        cout << "\n\nYou have exceeded your machine's max change capacity" << endl << endl;
                        cout << "\n\nYour change level is now: " << SetOfCokeMachines.at(choice - 1).getChangeLevel();
                    }
                }
                else if (option == 4)
                {
                    cout << SetOfCokeMachines.at(choice - 1) << endl;
                }
                else if (option == 5)
                {
                    cout << "\n\nEnter a new machine name: ";
                    getline(cin, newname);
                    getline(cin, newname);
                    SetOfCokeMachines.at(choice - 1).setMachineName(newname);
                    cout << "\n\nMachine name has been updated.\n\n";
                }
                else
                {
                    cout << "\n\nEnter a new Coke price: ";
                    cin >> newprice;
                    SetOfCokeMachines.at(choice - 1).setCokePrice(newprice);
                    cout << "\nCoke price has been updated.\n\n";
                }
                Menu();
                cout << "\n\n\nChoose an option: ";
                cin >> option;

                if (option == 0)
                {
                    cout << "\n\nAre you sure you aren't really thirsty and need a Coke?" << endl << endl;
                    cout << "\n\nPick a Coke Machine:\n\n";
                    cout << "0. Exit\n\n";
                    for (int i = 0; i < SetOfCokeMachines.size(); i++)
                    {
                        cout << i + 1 << ". " << SetOfCokeMachines[i].getMachineName() << endl << endl;
                    }
                    cout << SetOfCokeMachines.size() + 1 << ". Add a new machine" << endl << endl;
                    cout << "Enter choice: ";
                    cin >> choice;
                }
            }
        }
    }
    return 0;
}
