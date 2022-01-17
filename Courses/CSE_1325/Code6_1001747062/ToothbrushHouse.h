//Name: Gia Dao.
//Student ID: 1001747062.
#include "House.h"
#include <iostream>
#include <mutex>
#include <map>
#include <string>
#include <sstream>

#ifndef _TOOTHBRUSHHOUSE_
#define _TOOTHBRUSHHOUSE_


class ToothbrushHouse : public House
{
	public :
	    ToothbrushHouse(std::string, std::map<int, std::string>);
		std::string ringDoorbell(std::ostringstream&);
        ~ToothbrushHouse();
};

#endif
