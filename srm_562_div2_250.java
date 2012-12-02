import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class CucumberMarket
{
	public String check(int[] price, int budget, int k)
	{
		Arrays.sort(price);
		int total = 0;
		for (int i = 1; i <= k; i++) total += price[price.length - i];
		return total > budget ? "NO" : "YES";
	}
}
//Powered by [KawigiEdit] 2.0!