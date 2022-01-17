//Name: Gia Dao.
//Student ID: 1001747062.
#include <mutex>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

#ifndef _HOUSE_
#define _HOUSE_

class House
{
	public :
	    House(std::string, std::map<int, std::string>);
		virtual std::string ringDoorbell(std::ostringstream&) = 0;
		virtual ~House();


	protected :
		std::string houseName;
		std::mutex door;
		std::map<int, std::string> CandyRankingMap;
};

#endif
