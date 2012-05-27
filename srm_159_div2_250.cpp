#include <cmath>
class FryingHamburgers{
public:
	int howLong(int panSize, int hamburgers){
		if(hamburgers == 0)	
			return 0;
		if(panSize > hamburgers)
			return 10;
	 	double need = (hamburgers * 2);
		return (int) ceil(need / panSize) * 5;
	}
};