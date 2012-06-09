#include <vector>
#include <cmath>
using namespace std;

class StairClimb{
public:
	int stridesTaken(vector <int> flights, int stairsPerStride){
		int stride = 0;
		int turns =( flights.size() - 1) * 2;
		double tmp = stairsPerStride;
		for(int i = 0; i < flights.size();i++)
		{ 
			stride +=(int) ceil(flights[i] / tmp);
		}
		return stride + turns;
	}
};