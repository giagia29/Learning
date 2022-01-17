//Name: Gia Dao, Student ID: 1001747062
#include <iostream>
#include <string>
#include "CokeMachine.h"

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
}

int main()
{
    int option, pay, addchange, addinventory;
    int action;
    bool check;
    string change = "";
    CokeMachine MyCokeMachine{"CSE 1325 Coke Machine", 50, 500, 100};
    cout << "\n\n\n" << MyCokeMachine.getMachineName() << endl;
    Menu();
    cout << "\n\n\nChoose an option: ";
    cin >> option;
    if (option == 0) cout << "\n\nAre you sure you aren't really thirsty and need a Coke?" << endl << endl;
    while(option < 0 || option > 4)
    {
        cin.fail();
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "\n\n\nOption is not available. Please choose again: ";
        cin >> option;
        if (option == 0) cout << "\n\nAre you sure you aren't really thirsty and need a Coke?" << endl << endl;
    }
    while(option > 0 && option <= 4)
    {
        if (option == 1)
        {
            cout << "\n\nInsert payment: ";
            cin >> pay;
            check = MyCokeMachine.buyACoke(pay, change, action);
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
            if (MyCokeMachine.incrementInventory(addinventory) == true)
            {
                cout << "\n\nYour machine has been restocked.\n";
                cout << "\n\nYour inventory level is now: " << MyCokeMachine.getInventoryLevel();
            }
            else
            {
                cout << "\n\nYou have exceeded your machine's max inventory capacity" << endl << endl;
                cout << "\n\nYour inventory level is now: " << MyCokeMachine.getInventoryLevel();
            }
        }
        else if (option == 3)
        {
            cout << "\n\nHow much change are you adding to the machine? ";
            cin >> addchange;
            if (MyCokeMachine.incrementChangeLevel(addchange) == true)
            {
                cout << "\n\nYour change has been updated.\n";
                cout << "\n\nYour change level is now: " << MyCokeMachine.getChangeLevel();
            }
            else
            {
                cout << "\n\nYou have exceeded your machine's max change capacity" << endl << endl;
                cout << "\n\nYour change level is now: " << MyCokeMachine.getChangeLevel();
            }
        }
        else if (option == 4)
        {
            cout << "\n\nCurrent Inventory Level: " << MyCokeMachine.getInventoryLevel() << endl << endl;
            cout << "Max Inventory Capacity: " << MyCokeMachine.getMaxInventoryCapacity() << endl << endl << endl;
            cout << "\n\nCurrent Change Level: " << MyCokeMachine.getChangeLevel() << endl << endl;
            cout << "Max Change Capacity: " << MyCokeMachine.getMaxChangeCapacity() << endl << endl << endl;
            cout << "\n\nCurrent Coke Price: " << MyCokeMachine.getCokePrice() << endl;
        }
        cout << "\n\n\n" << MyCokeMachine.getMachineName() << endl;
        Menu();
        cout << "\n\n\nChoose an option: ";
        cin >> option;
        if (option == 0) cout << "\n\nAre you sure you aren't really thirsty and need a Coke?" << endl << endl;
    }
    return 0;
}
