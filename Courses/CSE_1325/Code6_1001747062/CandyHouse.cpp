//Name: Gia Dao.
//Student ID: 1001747062.
#include "CandyHouse.h"
#include "House.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>

CandyHouse::CandyHouse(std::string Name, std::map<int, std::string> CandyRanking) : House::House(Name,CandyRanking)
{

}

std::string CandyHouse::ringDoorbell(std::ostringstream& path)
{
    door.lock();
    path << "+";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    int candy = rand() % (CandyRankingMap.size()) + 1;
    door.unlock();
    return CandyRankingMap[candy];
}

CandyHouse::~CandyHouse()
{
    std::cout << "\nCANDYHOUSE\n";
}
