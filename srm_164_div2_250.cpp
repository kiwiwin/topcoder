#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Justifier{
public:
	size_t bigest(vector<string> str){
		size_t size = 0;
		for(size_t i = 0; i < str.size(); i++)
		{
			size = max(size,str[i].size());
		}
		return size;
	}
	
	string GetPad(int pad){
		string padstr = "";
		for(int i = 0; i < pad; i++)
		{ 
			padstr += " "; 		
		}
		return padstr;
	}
	
	vector <string> justify(vector <string> textIn){
		size_t size = bigest(textIn);
		vector<string> textOut;
		textOut.resize(textIn.size());
		for(size_t i = 0; i < textIn.size(); i++)
		{
			int pad = size - textIn[i].size();
			textOut[i] = GetPad(pad) + textIn[i];
		}
		return textOut;
	}
};