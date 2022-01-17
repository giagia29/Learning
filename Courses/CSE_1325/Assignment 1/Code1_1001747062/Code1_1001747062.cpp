//Name: Gia Dao
//Student ID: 1001747062
 /* #include <iostream>
#include <cstdlib>
#include <string.h>
#define price 0.60

using namespace std;

enum Status
{
    GiveChange,
    NoChange,
    NotEnoughInventory,
    NotEnoughChange,
    InsuffPayment,
};

int Number()
{
    while(true)
    {
        int n;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout << endl << "Input must be numeric. Please reenter ";
        }
        else
        {
            cin.ignore(32767,'\n');
            return n;
        }
    }
}

int Payment()
{
    while(true)
    {
        int p;
        cin >> p;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout << endl << "Input must be numeric. Please reenter ";
        }
        else
        {
            cin.ignore(32767,'\n');
            return p;
        }
    }
}

string MoneyAmount(long amount)
{
    string dollar{""}, cents{""}, result{""};
    dollar = to_string(amount / 100);
    cents = to_string(amount % 100);
    result = dollar + "." + (cents.size() == 1 ? "0" : "") + cents;
    return result;
}

bool BuyPencils(int& ilevel, int& clevel, int payment, int total, int number, Status& status)
{
    if (payment - total == 0)
    {
        clevel = clevel - (payment - total);
        ilevel = ilevel - number;
        status = NoChange;
        return true;
    }
    else if ((payment - total > 0) && (payment - total < clevel))
    {
        ilevel = ilevel - number;
        clevel = clevel - (payment - total);
        status = GiveChange;
        return true;
    }
    else if (ilevel < number)
    {
        status = NotEnoughInventory;
        return false;
    }
    else if (clevel < (payment - total))
    {
        status = NotEnoughChange;
        return false;
    }
    else if (payment < total)
    {
        status = InsuffPayment;
        return false;
    }
    else return false;
}

int Menu()
{
    cout << endl << "Please choose from the following options" << endl << endl;
    cout << "0. No pencils for me today" << endl;
    cout << "1. Purchase pencils" << endl;
    cout << "2. Check inventory level" << endl;
    cout << "3. Check change level" << endl << endl;
    cout << "Choice: ";
    while(true)
    {
        int c;
        cin >> c;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout << endl << "Input must be numeric. Please reenter ";
        }
        else
        {
            cin.ignore(32767,'\n');
            return c;
        }
    }
}

int main()
{
    int payment{}, number{}, total{}, choice{};
    int ilevel = 100, clevel = 500;
    Status status;
    string change{""}, result{""};
    bool check;
    cout << "Welcome to my Pencil Machine" << endl;
    while(true)
    {
        choice = Menu();
        switch(choice)
        {
            case 0:
                exit(0);
            case 1:
                if (ilevel == 0)
                {
                    cout << endl << "This Pencil Dispenser is out of inventory." << endl;
                    continue;
                }
                cout << endl << "A pencil costs: $" << price << endl << endl;
                cout << "How many pencils would you like to purchase? ";
                number = Number();
                if (number < 1)
                {
                    cout << endl << "You must purchase at least one pencil." << endl;
                    continue;
                }
                if (number > ilevel)
                {
                    cout << endl << "The machine does not have that many pencils - buy " << ilevel << " or fewer." << endl;
                    continue;
                }
                total = (price * 100) * number;
                result = MoneyAmount(total);
                cout << endl << "Your total is $" << result << endl << endl;
                cout << "Enter your payment (in cents) ";
                payment = Payment();
                check = BuyPencils(ilevel,clevel,payment,total,number,status);
                if (check == true && status == NoChange)
                {
                    cout << endl << "Here's your pencils. Thank you for your exact payment." << endl;
                }
                else if (check == true && status == GiveChange)
                {
                    change = MoneyAmount(payment - total);
                    cout << endl << "Here's your pencils and your change of $" << change << endl;
                }
                else if (check == false && status == NotEnoughChange)
                {
                    cout << endl << "This Pencil Dispenser does not have enough change and cannot accept your payment." << endl;
                }
                else if (check == false && status == InsuffPayment)
                {
                    cout << endl << "You did not enter a sufficient payment. No pencils for you." << endl;
                }
                else if (check == false && status == NotEnoughInventory)
                {
                    cout << endl << "The machine does not have that many pencils - buy " << ilevel << " or fewer" << endl;
                }
                else
                {
                    cout << endl << "Input must be numeric. Please reenter." << endl;
                }
                break;
            case 2:
                cout << endl << "The current inventory level is " << ilevel << endl;
                break;
            case 3:
                cout << endl << "The current change level is " << clevel << endl;
                break;
            default:
                cout << endl << "Invalid menu choice. Please choose again." << endl;
                break;
        }
    }
    return 0;
} */

#include <vector>
#include <iostream>
class Fruit
{
    public:
        virtual void whoamI()= 0;
};

class Orange : public Fruit
{   public:
        void whoamI()
        {
            std::cout << "Orange";
        }
};

class Grapefruit : public Fruit
{   public:
        void whoamI()
        {
            std::cout << "Grapefruit";
        }
};

class Orangelo : public Orange, public Grapefruit
{
    public:
        void whoamI()
        {
            std::cout << "Orangelo";
        }
};

int main(void)
{
    std::vector<Fruit*> fruits;
    fruits.push_back(new Orange());
    fruits.push_back(new Grapefruit());
    fruits.push_back(new Orangelo());
    for(Fruit* f : fruits)
    {
        std::cout << f->whoamI() << std::endl;
    }
    return 0;
}
