#include <string>
#include <vector>
using namespace std;

class Animation{
public:
	vector <string> animate(int speed, string init){
		//initial
		vector<string> track;
		string start = init;
		string end = init;
		for(size_t i = 0; i < init.size(); i++)
		{
			if(init[i] != '.') start[i] = 'X';
			end[i] = '.';
		}
		track.push_back(start);
		//check end
		if(start == end) 
			return track;
					
		//cout each time
		for(int t = 1; t < 50; t++)
		{
			string mid = end;
			for(size_t i = 0; i < init.size(); i++)
			{
				int len = t * speed;
				int min = i - len;
				int add = i + len;
				if( (init[i] == 'L') && (min >= 0) )
					mid.at(i - len) = 'X';
				if( (init[i] == 'R') && (add < init.size() ) )
					mid.at(i + len) = 'X';
			}
			track.push_back(mid);
			if(mid == end) 
				return track;
		}		
		return track;		
	}
};