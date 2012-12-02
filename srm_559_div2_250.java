import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BlockTower
{
	private int[] H;

	public int getTallest(int[] heights)
	{
		H = heights;
		int res = 0;
		for(int maxEvenIndex = -1; maxEvenIndex < H.length; maxEvenIndex++)	
			res = Math.max(res, getFirstHalfEven(maxEvenIndex) + getSecondHalfOdd(maxEvenIndex + 1));
		return res;
	}
	
	private int getFirstHalfEven(int maxIndex) {
		int res = 0;
		for (int i = 0; i <= maxIndex; i++) if (H[i] % 2 == 0) res += H[i];
		return res;
	} 

	private int getSecondHalfOdd(int smallIndex) {
		int res = 0;
		for (int i = smallIndex; i < H.length; i++) if (H[i] % 2 ==1) res += H[i];
		return res;
	}	
}
//Powered by [KawigiEdit] 2.0! 