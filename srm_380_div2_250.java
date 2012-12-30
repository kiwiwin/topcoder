import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class LuckyTicketSubstring
{
	public int maxLength(String s)
	{
		int result = 0;
		for (int begin = 0; begin < s.length(); begin++)
		for (int end = begin+1; end <= s.length(); end++) {
			if (isLuckTicket(s.substring(begin, end)))
				result = Math.max(result, end-begin);
		}
		return result;
	}
	
	private boolean isLuckTicket(String ticket) {
		if (ticket.length() % 2 == 1) return false;
		int result = 0;
		for (int i = 0; i < ticket.length()/2; i++) result += (int)ticket.charAt(i);
		for (int i = ticket.length()/2; i < ticket.length(); i++) result -= (int)ticket.charAt(i);
		return result == 0;
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!