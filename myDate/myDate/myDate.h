#pragma once
#include <iostream>;
#include <unordered_map>;
using namespace std;
class myDate
{
	private: 
		int month;
		int day;
		int year;
		unordered_map<int, string> months;
		unordered_map<int, string> days;
public:
	myDate();
	myDate(int M, int D, int Y);
	void display();
	void increaseDate(int N);
	void decreaseDate(int N);
	int daysBetween(myDate D);
	int getMonth();
	int getDate();
	int getYear();
	int dayOfYear();
	string dayName();
	bool isLeapYear(int Y);
	void populateMaps();
	int getGreg();
};

