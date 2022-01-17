#include <iostream>
#include <string>
#include <sstream>
#include "CokeMachine.h"


CokeMachine::CokeMachine(std::string name, int cost, int change, int inventory)
: machineName{name}, CokePrice{cost}, changeLevel{change}, inventoryLevel{inventory}
{
}

std::ostream& operator<<(std::ostream& output, CokeMachine& MyCokeMachine)
{
    output << "\nMachine Name: " << MyCokeMachine.getMachineName() << "\n\nCurrent Inventory Level: " << MyCokeMachine.getInventoryLevel()
    << "\nMax Inventory Capacity: " << MyCokeMachine.getMaxInventoryCapacity()
    << "\nCurrent Change Level: " << MyCokeMachine.getChangeLevel()
    << "\nMax Change Capacity: " << MyCokeMachine.getMaxChangeCapacity()
    << "\nCurrent Coke Price: " << MyCokeMachine.getCokePrice();

    return output;
}


std::string CokeMachine::getMachineName()
{
    return machineName;
}

bool CokeMachine::buyACoke(int payment, std::string& change, int& action)
{
    if (changeLevel < maxChangeCapacity)
    {
        if (payment < CokePrice)
        {
            action = 3;
            return false;
        }
        else if (payment - CokePrice > changeLevel)
        {
            action = 2;
            return false;
        }
        else if (payment == CokePrice)
        {
            action = 4;
            inventoryLevel = inventoryLevel - 1;
            changeLevel = changeLevel + CokePrice;
            return true;
        }
        else if ((payment - CokePrice > 0) && (payment - CokePrice < changeLevel))
        {
            action = 0;
            inventoryLevel = inventoryLevel - 1;
            changeLevel = changeLevel + CokePrice;
            change = displayMoney(payment - CokePrice);
            return true;
        }
        else if (inventoryLevel < 1)
        {
            action = 1;
            return false;
        }
        else return false;
    }
    else if (changeLevel >= maxChangeCapacity)
    {
        action = 5;
        return false;
    }
    else return false;
}

int CokeMachine::getInventoryLevel()
{
    return inventoryLevel;
}

int CokeMachine::getMaxInventoryCapacity()
{
    return maxInventoryCapacity;
}

bool CokeMachine::incrementInventory(int amountToAdd)
{
    if (inventoryLevel + amountToAdd <= maxInventoryCapacity)
    {
        inventoryLevel = inventoryLevel + amountToAdd;
        return true;
    }
    else
    {
        inventoryLevel = inventoryLevel + 0;
        return false;
    }
}

std::string CokeMachine::getChangeLevel()
{
    std:: string result;
    result = displayMoney(changeLevel);
    return result;
}

bool CokeMachine::incrementChangeLevel(int amountToAdd)
{
    if (changeLevel + amountToAdd <= maxChangeCapacity)
    {
        changeLevel = changeLevel + amountToAdd;
        return true;
    }
    else
    {
        changeLevel = changeLevel + 0;
        return false;
    }
}

std::string CokeMachine::getMaxChangeCapacity()
{
    std::string result;
    result = displayMoney(maxChangeCapacity);
    return result;
}

std::string CokeMachine::getCokePrice()
{
    std::string result;
    result = displayMoney(CokePrice);
    return result;
}

std::string CokeMachine::displayMoney(int amount)
{
    std::string dollars, cents, result;
    dollars = std::to_string(amount / 100);
    cents = std::to_string(amount % 100);
    result = "$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
    return result;
}

void CokeMachine::setMachineName(std::string& newMachineName)
{
    machineName = newMachineName;
}

void CokeMachine::setCokePrice(int newCokePrice)
{
    CokePrice = newCokePrice;
}

std::string CreateCokeOutputLine(CokeMachine& MyCokeMachine)
{
    std::ostringstream out;
    std::string cp = std::to_string(MyCokeMachine.CokePrice);
    std::string cl = std::to_string(MyCokeMachine.changeLevel);
    std::string il = std::to_string(MyCokeMachine.inventoryLevel);
    out << MyCokeMachine.getMachineName() << "|" << cp << "|" << cl << "|" << il;
    return out.str();
}


CokeMachine::~CokeMachine()
{
    std::cout << "\nCoke Machine " << machineName << " has been destroyed\n";
}

