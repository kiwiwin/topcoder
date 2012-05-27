#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Doc {
	Doc(){}
	
	void addRecord(string room, string group) {
		groups.push_back(make_pair(room, group));
	}
	
	bool access(const vector<string>& room, const vector<string>& group) const {
		bool flag = false;
		for (int i = 0; i < room.size(); i++) {
			for (int j = 0; j < groups.size(); j++) {
				if (room[i] == groups[j].first) {flag = true; break;}
			}
			if (flag) break;
		}
		if (!flag) return false;
		flag = false;
		for (int i = 0; i < group.size(); i++) {
			for (int j = 0; j < groups.size(); j++) {
				if (group[i] == groups[j].second) {flag = true; break;}
			}
			if (flag) break;
		}
		return flag;
	}
	
	vector<pair<string,string> > groups;
};

class Library {
public:
	int documentAccess(vector <string>, vector <string>, vector <string>);
	void addRecord(string doc_name, string room, string group_name) {
		if (docs.find(doc_name) == docs.end()) {
			Doc doc; doc.addRecord(room, group_name);
			docs[doc_name] = doc;
		} else {
			docs[doc_name].addRecord(room, group_name);
		}
	}
	map<string, Doc> docs;
};

int Library::documentAccess(vector <string> records, vector <string> userGroups, vector <string> roomRights) {
	int res = 0;
	
	for (int i = 0; i < records.size(); i++) {
		stringstream ss(records[i]);
		string doc_name, room, group_name;
		ss >> doc_name >> room >> group_name;
		addRecord(doc_name, room, group_name);
	}
	
	for (map<string, Doc>::iterator itr = docs.begin(); itr != docs.end(); itr++) {
		if (itr->second.access(roomRights, userGroups)) res++;
	}
	
	return res;
}


//Powered by [KawigiEdit] 2.0!