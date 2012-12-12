import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class FoxAndHandleEasy
{
	public String isPossible(String S, String T)
	{
		for (int i = 0; i <= S.length(); i++)
			if (expand(S, i).equals(T)) return "Yes";
		return "No";
	}
	
	public String expand(String S, int insertLocation) {
		String result = S;
		return result.substring(0, insertLocation) + S + result.substring(insertLocation, result.length());
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!