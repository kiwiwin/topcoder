import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class LotteryTicket
{
	public String buy(int price, int b1, int b2, int b3, int b4)
	{
		List<Integer> list = Arrays.asList(b1, b2, b3, b4);
		return solve(price, list) ? "POSSIBLE" : "IMPOSSIBLE";
	}
	
	public boolean solve(int price, List<Integer> list) 
	{
		if (list.isEmpty()) return price == 0;
		List<Integer> cdr = list.subList(1, list.size());
		return solve(price, cdr) || solve(price - list.get(0), cdr);
	}	
}
//Powered by [KawigiEdit] 2.0!

