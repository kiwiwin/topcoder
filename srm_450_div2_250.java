import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class StrangeComputer
{
	public int setMemory(String mem)
	{
		int result = 0;
		char c = '0';
		for (int i = 0; i < mem.length(); i++) 
		if (c != mem.charAt(i)) {
			result ++;
			c = mem.charAt(i);
		}	
		return result;
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!