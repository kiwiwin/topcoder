class Inchworm{
public:
	int lunchtime(int branch, int rest, int leaf){
		int count = 1;
		int numleaf = branch / leaf;
		for(int i = 1; i <= numleaf; i++)
		{ 
			if( ((leaf * i) % rest) == 0)
				count++;
		}
		return count;
	}
};