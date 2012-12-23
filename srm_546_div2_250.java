import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ContestWinner
{
	private Map<Integer,Integer> solved = new HashMap<Integer,Integer>();
	private Map<Integer,Integer> last = new HashMap<Integer,Integer>();

	public int getWinner(int[] events)
	{
		for(int i = 0; i < events.length; i++) {
			if (!solved.containsKey(events[i])) {
				solved.put(events[i], 0); last.put(events[i], 0);
			}
			solved.put(events[i], solved.get(events[i])+1);
			last.put(events[i], i);
		}
		
		Object[] keyArray = solved.keySet().toArray();
		Integer result = (Integer)keyArray[0];
		for (int i = 1; i < keyArray.length; i++) {
			Integer key = (Integer)keyArray[i];
			if (solved.get(key) > solved.get(result)) result = key;
			else if (solved.get(key).compareTo(solved.get(result)) == 0 && last.get(key).compareTo(last.get(result)) < 0) result = key;
		}
		
		return result;
	}
	
	
}
//Powered by [KawigiEdit] 2.0!