#pragma once
#ifndef DATA_H
#define DATA_H
#include<vector>
#include<string>
#include<iostream>
#include<stdexcept>
class date
{
public:
	unsigned year, month, day;
public:
	date(unsigned m = 1,unsigned d=1,unsigned y=1990):month(m),day(d),year(y){}
	date(std::string s);
};

#endif // !DATA_H

date::date(std::string s)
{
	std::string numbers("0123456789");
	std::vector<std::string> month1 = { "January","February","March","April","May","June","July","August","September","Octobor","Novermber","December" };
	std::vector<std::string> month2 = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	int i = 0;
	int n1 = s.find_first_of(numbers);
	int n2 = s.find_first_not_of(numbers);
	for (; i != 12; i++)
	{
		if ((s.find(month1[i]) != std::string::npos)||(s.find(month2[i])!=std::string::npos))
			break;
	}
	if (i != 12)
	{
		month = i + 1;
		n1 = s.find_first_of(numbers, n2);
		n2 = s.find_first_not_of(numbers, n1);
		day = stoi(s.substr(n1, n2 - n1));
		n1 = s.find_first_of(numbers, n2);
		year = stoi(s.substr(n1));
	}
	else
	{
		month = stoi(s.substr(n1, n2 - n1));
		n1 = s.find_first_of(numbers, n2);
		n2 = s.find_first_not_of(numbers, n1);
		day = stoi(s.substr(n1, n2 - n1));
		n1 = s.find_first_of(numbers, n2);
		year = stoi(s.substr(n1));
	}
}

int main()
{
	cout << "Warning: you must enter the date by the queue of month,date and year(like October 3, 1994)." << '\n';
	date one("Feb 10, 2001");
	cout << one.month<<'\n' << one.day <<'\n'<< one.year << endl;
	return 0;
}
