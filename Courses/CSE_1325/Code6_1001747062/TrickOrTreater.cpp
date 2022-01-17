//Name: Gia Dao.
//Student ID: 1001747062.
#include "TrickOrTreater.h"
#include <chrono>
#include <thread>
#include <time.h>
#include <sstream>
int TrickOrTreater::ImDone = 0;

TrickOrTreater::TrickOrTreater(std::string Name, std::vector<House*> List) : name{Name}, ListOfHouses{List}
{
}

std::ostream& operator<<(std::ostream& output, TrickOrTreater& TOT)
{
    output << TOT.name << "'s - ";
    for (auto x : TOT.Bucket)
    {
        output << x.second << " " << x.first << ", ";
    }
    output << std::endl;
    return output;
}

void TrickOrTreater::Walk(int speed)
{
    for (int i = 0; i < 10; ++i)
    {
        path << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}

void TrickOrTreater::GoTrickOrTreating()
{
    int speed;
    for (auto it : ListOfHouses)
    {
        speed = rand()%500 + 1;
        Walk(speed);
        Bucket[it->ringDoorbell(path)]++;
    }
    ImDone++;
}

std::string TrickOrTreater::getName()
{
    return name;
}

void TrickOrTreater::startThread()
{
    TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}

void TrickOrTreater::joinThread()
{
    this->TOTThreadPtr->join();
    delete this->TOTThreadPtr;
}

std::string TrickOrTreater::getPath()
{
    return path.str();
}

