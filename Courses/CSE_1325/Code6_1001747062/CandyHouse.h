//Name: Gia Dao.
//Student ID: 1001747062.
#include "House.h"
#include <iostream>
#include <mutex>
#include <map>
#include <string>
#include <sstream>

#ifndef _CANDYHOUSE_
#define _CANDYHOUSE_


class CandyHouse : public House
{
	public :
	    CandyHouse(std::string, std::map<int, std::string>);
		std::string ringDoorbell(std::ostringstream&);
        ~CandyHouse();
};

#endif
