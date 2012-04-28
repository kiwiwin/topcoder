#include <string>
#include <vector>
#include <sstream>
using namespace std;

class PrefixCode
{ 
public:
	string IsPrefixFound( vector<string> words )
	{
		string notfind = "";
		if(words.size() == 1) return notfind;
		for (int i = 0; i < words.size(); i++)
		{ 
			for (int j = 0 ; j < words.size(); j++)
			{
				if( i == j) continue;
				size_t found = words[j].find(words[i]);
				if ( found == 0 )
				{
					stringstream pos;
					pos<<i;
					return pos.str();
				} 
			}	
		}
		return notfind; 
	}
	
	string	isOne( vector<string> words)
	{
		string findpre = "No, ";
		string nopre = "Yes";
		if ( IsPrefixFound(words) == "" )
			return nopre;
		else
		  	return findpre += IsPrefixFound(words) ;
			 
	}
};