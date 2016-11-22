// Hackerrank.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

void split(const std::string &s, char delim, std::vector<std::string> &elems);

int cplusplus11();
int cplusplus98();

int cplusplus11()
{
	/*string time;
	cin >> time;*/


	string time("12:45:54PM");
	string am("AM");
	string pm("PM");


	std::size_t found = time.find(am);
	bool isAm = false;

	if ((found != std::string::npos))
	{
		isAm = true;
	}
	else
	{
		std::size_t found = time.find(pm);

		if (found == std::string::npos)
		{
			isAm = true;
		}
	}



	struct std::tm when = { 0 };


	std::istringstream ss(time);

	ss >> std::get_time(&when, "%H:%M:%S");
	if (!isAm)
	{
		if (when.tm_hour >0 && when.tm_hour<12)
		{
			when.tm_hour = when.tm_hour + 12;
		}
	}

	when.tm_year = 2016 - 1900;
	when.tm_mon = 11;
	when.tm_isdst = -1;


	time_t timeNew = mktime(&when);

	stringstream stream;
	struct tm timeinfo;
	localtime_s(&timeinfo, &timeNew);

	stream << put_time(&timeinfo, "%H:%M:%S");
	cout << stream.str() << endl;
	return 0;
}

int cplusplus98()
{
	string time("12:45:54PM");

	string am("AM");
	string pm("PM");

	std::size_t found = time.find(am);
	bool isAm = false;


	if ((found != std::string::npos))
	{
		isAm = true;
	}
	else
	{
		std::size_t found = time.find(pm);

		if (found == std::string::npos)
		{
			isAm = true;
		}
	}



	struct std::tm when = { 0 };
	char delim = ':';

	string delimString = ":";


	std::vector<std::string> elems;
	split(time, delim, elems);

	when.tm_hour = atoi(elems[0].c_str());
	when.tm_min = atoi(elems[1].c_str());
	when.tm_sec = atoi(elems[2].c_str());

	if (!isAm)
	{
		if (when.tm_hour >0 && when.tm_hour<12)
		{
			when.tm_hour = when.tm_hour + 12;
		}
	}
	else
	{
		if (when.tm_hour == 12)
		{
			when.tm_hour = 0;
		}
	}

	when.tm_year = 2016 - 1900;
	when.tm_mon = 11;
	when.tm_isdst = -1;
	when.tm_mday = 5;


	char foo[24];
	strftime(foo, sizeof(foo), "%H:%M:%S", &when);

	cout << foo << endl;
	return 0;
}

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

	