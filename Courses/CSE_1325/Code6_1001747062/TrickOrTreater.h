//Name: Gia Dao.
//Student ID: 1001747062.
#include "House.h"
#include <map>
#include <thread>
#include <sstream>
#include <string>
#include <vector>


#ifndef _TOT_H
#define _TOT_H

class TrickOrTreater
{
    friend std::ostream& operator<<(std::ostream&, TrickOrTreater&);

	public :
		TrickOrTreater(std::string, std::vector<House*>);
		std::string getName();
		void startThread();
		void joinThread();
		void GoTrickOrTreating();
		void Walk(int);
		std::string getPath();
		static int ImDone;


	private :
		std::string name;
		std::ostringstream path;
		std::thread *TOTThreadPtr = nullptr;
        std::map<std::string, int> Bucket;
		std::vector<House*> ListOfHouses;
};

#endif
