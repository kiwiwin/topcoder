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

class ProgressBar {
public:
	string showProgress(vector <int>, int);
};

string ProgressBar::showProgress(vector <int> taskTimes, int tasksCompleted) {
	int sum = 0;
	int com = 0;
	for(int i = 0; i < taskTimes.size(); i++){
		sum += taskTimes[i];
		if(i < tasksCompleted){
			com += taskTimes[i];
		}
	}
	int n = floor(20 * com / sum);
	string str(n,'#');
	str.append(20-n,'.');	
	return str;
}

<%:testing-code%>
/*Powered by [KawigiEdit] 2.0!

Problem Statement
????
When doing any work with visual media it is often very useful to have the complement of a color on hand to create contrast and bring the focus of a picture to a particular place. To create the complement of a color on a computer, each of the red, green, and blue values of a color are inverted. Each of the red, green, and blue values of a color can range from 0 to 255, inclusive. If a particular component of one color is 50, then that component of its complement is 255-50=205.  Although this generally works well, it doesn't generate good complements for grey colors that have all three components right around 128. To fix this you will return an alternate complement for grey colors. If each component of a color and its corresponding component of the color's complement differ by 32 or less, then make the complement of each component by either adding 128 to a component's value, or by subtracting 128 from a component's value, whichever one results in a legal value. For example, the color {120,130,140} would have the complement {125,105,115}, but each component in the color and the complement differ by 32 or less, so we make the complement {248,2,12}.  Create a class RGBColor with a method getComplement that takes a vector <int> rgb representing the red, green, and blue values of a color, in that order, and returns a vector <int> representing the red, green, and blue values of the complement of that color, in that same order.
Definition
????
Class:
RGBColor
Method:
getComplement
Parameters:
vector <int>
Returns:
vector <int>
Method signature:
vector <int> getComplement(vector <int> rgb)
(be sure your method is public)
????

Constraints
-
rgb will contain exactly three elements.
-
Each element of rgb will be a value between 0 and 255, inclusive.
Examples
0)

????
{255,0,0}
Returns: { 0,  255,  255 }
The complement of red is cyan.
1)

????
{115,115,143}
Returns: { 243,  243,  15 }
The complement of this bluish-grey would normally have been {140,140,112}. But since each component of the complement would have been within 32 of the corresponding component of rgb we return the alternate complement instead.
2)

????
{115,115,144}
Returns: { 140,  140,  111 }
Also a bluish-grey, but in this case the blue component of the complement differs by 33 from the blue component of rgb, just enough so that we don't need to return the alternate complement.
3)

????
{153,12,55}
Returns: { 102,  243,  200 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.*/