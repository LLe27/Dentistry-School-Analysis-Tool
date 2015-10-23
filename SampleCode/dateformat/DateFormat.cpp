#include <iostream>
#include <string>
#include <cctype>
#include "DateFormat.h"

using namespace std;

DateFormat :: DateFormat(string dateString){
	date = dateString;
	year = 30000;
}

string getYear(){
	return year;
}

int format(){
	string yearString;
	if (dateString.at(0).isdigit){
		year = dateString.substr(0,4);
	} 
	return 0;
}

int main(){

	int test = 0;

	DateFormat a("");
	DateFormat b("May-00");
	DateFormat c("2015");
	DateFormat d("1975-01-04");
	
	test += a.format();
	test += b.format();
	test += c.format();
	test += d.format();
	
	if (test > 0){
		return 1;
	}
	
	cout << "test a: " << a.getYear() << "\n";
	cout << "test b: " << c.getYear() << "\n";
	cout << "test c: " << b.getYear() << "\n";
	cout << "test d: " << d.getYear() << "\n";
	
	return 0;
	
}
