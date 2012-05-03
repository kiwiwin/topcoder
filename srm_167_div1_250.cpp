#include <string>
#include <vector>
using namespace std;

class LeftChamper;
class RightChamper;

class Champer {
public:
	virtual void move() = 0;
	virtual ~Champer() {}
	bool in() {
		return place >= 0 && place < SIZE;
	}
	int getPlace() { return place; }
protected:
	Champer(int SIZE_, int speed_, int place_) : SIZE(SIZE_), speed(speed_), place(place_) {}
	int SIZE;
	int speed;
	int place;
};

class LeftChamper : public Champer {
public:
	LeftChamper(int SIZE, int speed, int place) : Champer(SIZE, speed, place) {}

	virtual void move() {
		place -= speed;
	}
};

class RightChamper : public Champer {
public:
	RightChamper(int SIZE, int speed, int place) : Champer(SIZE, speed, place) {}
	virtual void move() {
		place += speed;
	}
};

class ChamperFactory {
public:
	static Champer* createChamper(char type, int SIZE, int speed, int place) {
		Champer *champer = NULL;
		if( type == 'L') champer = new LeftChamper(SIZE, speed, place);
		if( type == 'R') champer = new RightChamper(SIZE, speed, place);
		return champer;
	}
};

class ChamperList {
public:
	void addChamper(Champer* c) {
		list.push_back(c);
	}

	void move() {
		for (int i = 0; i < list.size(); i++)
			list[i]->move();
	}

	vector<int> getPlaces() {
		vector<int> res;
		for (int i = 0; i < list.size(); i++)
			if (list[i]->in()) res.push_back(list[i]->getPlace());
		return res;
	}
	
	string toString(int SIZE) {
		string res(SIZE, '.');
		vector<int> places = getPlaces();
		for (int i = 0; i < places.size(); i++)
			res[places[i]] = 'X';
		return res;
	}
private:
	vector<Champer*> list;
};

class Animation {
public:
	ChamperList getChamperListFromInit(int speed, string init) {
		ChamperList cl;
		for (int i = 0; i < init.size(); i++) {
			if (init[i] != '.') cl.addChamper(ChamperFactory::createChamper(init[i], init.size(), speed, i));
		}
		return cl;
	}
	
	vector <string> animate(int speed, string init) {
		ChamperList list = getChamperListFromInit(speed, init);
		vector<string> res;
		string final(init.size(), '.');
		while(true) {
			res.push_back(list.toString(init.size()));
			if (res[res.size()-1] == final) break;
			list.move();
		}
		return res;
	}
};
