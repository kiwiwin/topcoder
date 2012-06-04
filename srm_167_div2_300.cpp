#define HOUR 60

class EyeDrops{
public:
	double closest(int sleepTime, int k){
		double per;
		if(k == 1) return 1440.0;
		per =(double) (24 - sleepTime) * HOUR / (k - 1);
		if(per > sleepTime * HOUR) per = (double) 24 * HOUR / k;
		return per;
	}
};