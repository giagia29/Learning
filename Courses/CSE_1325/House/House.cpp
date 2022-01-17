//Name:Gia Dao.
//Student ID: 1001747062.
#include "House.h"
#include <chrono>
#include <thread>
#include <time.h>
House::House(std::string Name, std::map<int, std::string> CandyRanking) : houseName{Name}, CandyRankingMap{CandyRanking}
{
}

std::string House::ringDoorbell(std::ostringstream &path)
{
    door.lock();
    path << "*";
    this_thread::sleep_for(std::chrono::seconds(3));
    int candy = rand() % (CandyRankinMap.size()) + 1;
    door.unlock();
    return CandyRankingMap[candy];
}
