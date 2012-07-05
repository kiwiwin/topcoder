#include <string>
using namespace std;
class NumberGuesser
{
public:
	int guess(string left)
	{
		int a = left[0] - '0' + left[1] - '0'+ left[2] - '0';		
		int t = (a / 9) + 1;
		int pic = (t * 9) - a;
		return pic;
	}
};