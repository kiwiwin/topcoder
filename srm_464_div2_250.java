import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ColorfulBoxesAndBalls
{
	public int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int result = numRed * onlyRed + numBlue * onlyBlue;
		if (bothColors * 2 > onlyRed + onlyBlue) {
			result += (bothColors * 2 - (onlyRed + onlyBlue)) * Math.min(numRed, numBlue);
		}
		return result;
	}
	
	
}
//Powered by [KawigiEdit] 2.0!

