#include <string>
using namespace std;

class Substitute{
public:
	int getValue(string key, string code){
		int count;
		int num = 0;
		for(int i = 0; i < code.size(); i++)
		{
			if(string::npos == key.find(code[i]))
				continue;
			if( (key.size() - 1) == key.find(code[i]))
			{
				count = 0;
			}
			else
			{
				count = key.find(code[i]) + 1;
			}
			num = num * 10 + count;
		}
		return num;	
	}
};