import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BuyingCheap
{
	public int thirdBestPrice(int[] prices)
	{
		SortedSet<Integer> H =  new TreeSet<Integer>();
		for (int p : prices) H.add(p);
		if (H.size() < 3) return -1;
		Object[] PA = H.toArray();
		return ((Integer)PA[2]).intValue();
	}
	
	
}
//Powered by [KawigiEdit] 2.0!