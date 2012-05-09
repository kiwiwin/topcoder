#include <string>
using namespace std;

class TireRotation{
public:
	string GetNextPhase(string cur){
		string phase = cur;
		phase[0] = cur[3];
		phase[1] = cur[2];
		phase[2] = cur[0];
		phase[3] = cur[1];
		return phase;
	}
	
	int getCycle(string initial, string current){
		int status = 1;
		string phase = initial;
		string mid;
		while(status < 5)
		{
			if(current == phase)		
				return status;
			else 
				phase = GetNextPhase(phase);
				status++;
		}
		return -1;
	}
};