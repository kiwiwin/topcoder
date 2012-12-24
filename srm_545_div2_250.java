import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ANDEquation
{
	public int restoreY(int[] A)
	{
		for (int yIndex = 0; yIndex < A.length; yIndex++) {
			int temp = yIndex == 0 ? A[1] : A[0];
			for (int i = 0; i < A.length; i++) if (i != yIndex) temp &= A[i];
			if (temp == A[yIndex]) return temp;
		}
		return -1;
	}	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!