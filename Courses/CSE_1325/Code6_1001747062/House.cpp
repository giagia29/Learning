//Name: Gia Dao.
//Student ID: 1001747062.
#include "House.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>

House::House(std::string Name, std::map<int, std::string> CandyRanking) : houseName{Name}, CandyRankingMap{CandyRanking}
{
}

House::~House()
{
    std::cout << "\nHOUSE\n";
}
