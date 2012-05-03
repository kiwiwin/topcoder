#include <cmath>
#include <algorithm>
using namespace std;

class ParallelSpeedup {
public:
	long long costTime(int k, int overhead, long long proc) {
		long long communicationTime = proc * (proc - 1) / 2 * overhead;
		long long taskTime = ceil(1.0 * k / proc);
		return communicationTime + taskTime;
	}

	int numProcessors(int k, int overhead) {
		long long mintime = k; int res = 1;
		for (long long proc = 2; proc <= 1000000; proc++)
		{
			if (mintime > costTime(k, overhead, proc)) {
				mintime = costTime(k, overhead, proc);
				res = proc;
			}
		}
		return res;
	}
};
