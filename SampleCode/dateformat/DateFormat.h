#ifndef DATEFORMAT_H
#	define DATEFORMAT_H

#include <string>

class DateFormat{
	
private:
	
	std::string date;
	std::string year;	
	
public:
	
	std::string DateFormat(std::string dateString);
	std::string getYear();
	int format();
	
}

#endif
