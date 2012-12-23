import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class MinimalTriangle
{
	public double maximalArea(int length)
	{
		double len = length;
		return len*len*Math.sin(2.0*Math.PI/3.0)/2;
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!