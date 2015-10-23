#include <iostream>
#include <string>
#include <cctype>
#include "DateFormat.h"

using namespace std;

void DateFormat::DateFormat(string dateString){
	date = dateString;
	year = "30000";
}

string DateFormat :: getYear(){
	return year;
}

int DateFormat :: format(){
	if (date.compare("") == 0){
		return 1;
	}
	char first = date.at(0);
	if (isdigit(first)){
		year = date.substr(0,4);
	} else {
		string endString = date.substr(4,6);
		if (endString.compare("15") <= 0){
			year = "20" + endString;
		} else {
			year = "19" + endString;
		}
	}
	return 0;
}

int main(){

	int test = 0;

	DateFormat a("");
	DateFormat b("May-00");
	DateFormat c("2015");
	DateFormat d("1975-01-04");
	DateFormat e("Jan-25");
	DateFormat f("Feb-14");
	DateFormat g("May-15");
	DateFormat h("May-51");
	
	test += a.format();
	test += b.format();
	test += c.format();
	test += d.format();
	test += e.format();
	test += f.format();
	test += g.format();
	test += h.format();
	
	cout << "test a: " << a.getYear() << "\n";
	cout << "test b: " << b.getYear() << "\n";
	cout << "test c: " << c.getYear() << "\n";
	cout << "test d: " << d.getYear() << "\n";
	cout << "test e: " << e.getYear() << "\n";
	cout << "test f: " << f.getYear() << "\n";
	cout << "test g: " << g.getYear() << "\n";
	cout << "test h: " << h.getYear() << "\n";
	
	return 0;
	
}
