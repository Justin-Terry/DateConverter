#include "myDate.h";
#include <iostream>;
#include <string>;
using namespace std;


int Greg2Julian(int  month, int day, int year) {
	return day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
};
void Julian2Greg(int JD, int & month, int & day, int & year) {
	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	year = 4000 * (L + 1) / 1461001;
	L = L - 1461 * year / 4 + 31;
	month = 80 * L / 2447;
	day = L - 2447 * month / 80;
	L = month / 11;
	month = month + 2 - 12 * L;
	year = 100 * (N - 49) + year + L;
};

myDate::myDate()
{
	month = 5;
	day = 11;
	year = 1959;
	populateMaps();
}

int myDate::getGreg() {
	return Greg2Julian(month, day, year);
}

myDate::myDate(int M, int D, int Y)
{
	if ((M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
		&& (D > 0 && D < 32) && (Y > 0)) {
		month = M;
		day = D;
		year = Y;
	}
	else if ((M == 4 || M == 6 || M == 9 || M == 11)
		&& (D > 0 && D < 31) && (Y > 0)) {
		month = M;
		day = D;
		year = Y;
	}
	else if ((M == 2) && (Y > 0) && (D > 0 && D < 30)) {
		if (isLeapYear(Y) && (D > 0 && D < 30)) {
			month = M;
			day = D;
			year = Y;
		}
		else if (!isLeapYear(Y) && (D > 0 && D < 29)) {
			month = M;
			day = D;
			year = Y;
		}
		else {
			month = 5;
			day = 11;
			year = 1959;
		}
	}
	else {
		month = 5;
		day = 11;
		year = 1959;
	}
	populateMaps();
}

bool myDate::isLeapYear(int Y)
{
	if ((Y % 4 == 0) && (Y % 100 != 0)) {
		return true;
	}
	else if ((Y % 4 == 0) && (Y % 100 == 0) && (Y % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

void myDate::increaseDate(int N) {
	int greg = Greg2Julian(month, day, year);
	greg = greg + N;
	Julian2Greg(greg, month, day, year);
}

void myDate::decreaseDate(int N) {
	int greg = Greg2Julian(month, day, year);
	greg = greg - N;
	Julian2Greg(greg, month, day, year);
}

int myDate::getYear() {
	return year;
}

int myDate::getDate() {
	return day;
}

int myDate::getMonth() {
	return month;
}

void myDate::display() {
	cout << months[this->getMonth()] + " " << this->getDate() << ", " << this->getYear() << endl; 
}

void myDate::populateMaps() {
	months[1] = "January";
	months[2] = "February";
	months[3] = "March";
	months[4] = "April";
	months[5] = "May";
	months[6] = "June";
	months[7] = "July";
	months[8] = "August";
	months[9] = "September";
	months[10] = "October";
	months[11] = "November";
	months[12] = "December";

	days[0] = "Monday";
	days[1] = "Tuesday";
	days[2] = "Wednesday";
	days[3] = "Thursday";
	days[4] = "Friday";
	days[5] = "Saturday";
	days[6] = "Sunday";
}

int myDate::daysBetween(myDate m) {
	int thisGreg = Greg2Julian(month, day, year);
	int thatGreg = Greg2Julian(m.getMonth(), m.getDate(), m.getYear());
	if (thisGreg > thatGreg) {
		return thisGreg - thatGreg;
	}else {
		return thatGreg - thisGreg;

	}
}

string myDate::dayName() {
	int juli = Greg2Julian(month, day, year);
	return days[juli % 7];
}

int myDate::dayOfYear() {
	myDate temp = myDate(1, 1, year);
	return daysBetween(temp)+1;
}


