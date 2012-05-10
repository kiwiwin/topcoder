#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class Date {
public:
	Date(string date) {
		int mm, dd;
		sscanf(date.c_str(), "%d/%d", &mm, &dd);
		m = mm; d = dd;
	}
	
	Date(int mm, int dd) : m(mm), d(dd){}
	
	bool canUS() {
		if (m > 12) return false;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return d <= 31;
		if (m == 2) return d <= 29;
		return d <= 30;
	}
	
	bool canEuro() {
		swap(m,d);
		bool res = canUS();
		swap(m,d);
		return res;
	}
	
	Date toEuro() {
		return Date(d, m);
	}
	
	bool early(Date date, bool myUS, bool dateUS) {
		int myM = m; int myD = d;
		int dateM = date.m; int dateD = date.d;
		if (!myUS) swap (myM, myD);
		if (!dateUS) swap (dateM, dateD);
		if (myM != dateM) return myM < dateM;
		return myD < dateD;
	}
	
	string toString() {
		string res = "";
		res += m/10 + '0';
		res += m%10 + '0';
		res += "/";
		res += d/10 + '0';
		res += d%10 + '0';
		return res;	
	}
	
	
	
	int m;
	int d;
};

class DateFormat {
public:
	vector<string> splitBySpace(string str) {
		vector<string> res;
		stringstream ss(str);
		string child;
		while(ss >> child) res.push_back(child);
		return res;
	}
	
	string vd2s(vector<Date> vd) {
		string res = "";
		for (int i = 0;i < vd.size(); i++) {
			if (res != "") res += " ";
			res += vd[i].toString();
		}
		return res;
	}

	string fromEuropeanToUs(vector<string> dateList) {
		string date = "";
		for (int i = 0; i < dateList.size(); i++) date += dateList[i];
		vector<string> D = splitBySpace(date);
		cout << D.size() << endl;
		vector<Date> vd;
		for (int i = 0; i < D.size(); i++) vd.push_back(Date(D[i]));
		

		Date last(0,0);
		
		for (int i = 0; i < vd.size(); i++) {
			cout << i << " " << last.toString() << endl;
			if (i != 0) last = vd[i-1];
			if (!vd[i].canUS() && !vd[i].canEuro()) return "";
			cout << "xx" << endl;
			if (!vd[i].canUS()) {
				Date euro = vd[i].toEuro();
				if (last.early(euro, true, true)) vd[i] = euro;
				else return "";
			} else if (!vd[i].canEuro()) {
				Date us = vd[i];
				if (last.early(us, true, true)) vd[i] = us;
				else return "";
			} else {
				Date early = vd[i], late = vd[i].toEuro();
				if (late.early(early, true, true)) swap(early, late);
				
				if (last.early(early, true, true)) vd[i] = early;
				else if (last.early(late, true, true)) vd[i] = late;
				else return "";
			}
		}
		return vd2s(vd);
	}
};
