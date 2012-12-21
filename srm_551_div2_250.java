import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ColorfulBricks
{
	public int countLayouts(String bricks)
	{
		Set<Character> S = new HashSet<Character>();
		for (Character c : bricks.toCharArray()) S.add(c);
		return S.size() > 2 ? 0 : S.size();
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!