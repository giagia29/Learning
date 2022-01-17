//Name: Gia Dao, Student ID: 1001747062
#include<string>

#ifndef COKE_MACHINE_H
#define COKE_MACHINE_H

class CokeMachine
{
    public:
        /* CokeMachine(std::string name, int cost, int change, int inventory)
        : machineName{name}, CokePrice{cost}, changeLevel{change}, inventoryLevel{inventory}
        {
        } */
        friend std::ostream& operator<<(std::ostream&, CokeMachine&);

        friend std::string CreateCokeOutputLine(CokeMachine&);

        CokeMachine(std::string = "New Machine", int = 50, int = 500, int = 100);

        ~CokeMachine();

        std::string getMachineName();

        bool buyACoke(int, std::string&, int&);

        int getInventoryLevel();

        int getMaxInventoryCapacity();

        bool incrementInventory(int);

        std::string getChangeLevel();

        bool incrementChangeLevel(int);

        std::string getMaxChangeCapacity();

        std::string getCokePrice();

        std::string displayMoney(int);

        void setMachineName(std::string&);

        void setCokePrice(int);

    private:
        std::string machineName;
        int CokePrice;
        int changeLevel;
        int inventoryLevel;
        int maxChangeCapacity = 5000;
        int maxInventoryCapacity = 100;
};

#endif // COKE_MACHINE_H
