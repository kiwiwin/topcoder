import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class XorBoardDivTwo
{
	public int theMax(String[] board)
	{
		int result = 0;
		for (int r = 0; r < board.length; r++)
		for (int c = 0; c < board[r].length(); c++)
			result = Math.max(result, oneNumber(flip(board, r, c)));
		return result;
	}
	
	private int oneNumber(String[] board) {
		int result = 0;
		for (int r = 0; r < board.length; r++)
		for (int c = 0; c < board[r].length(); c++)
		 if (board[r].charAt(c) == '1') result++;
		return result;
	}
	
	private String[] flip(String[] board, int R, int C) {
		StringBuilder[] result = ConvertToBuilderArray(board);
		for (int r = 0; r < result.length; r++)
		for (int c = 0; c < result[r].length(); c++)
			if ((r == R || c == C) && !(r == R && c == C)) {
				result[r].setCharAt(c, result[r].charAt(c) == '1' ? '0' : '1');
			}
		return ConvertToStringArray(result);
	}
	
	private StringBuilder[] ConvertToBuilderArray(String[] stringArray) {
		StringBuilder[] result = new StringBuilder[stringArray.length];
		for (int i = 0; i < stringArray.length; i++) result[i] = new StringBuilder(stringArray[i]);		
		return result;
	}
	
	private String[] ConvertToStringArray(StringBuilder[] builderArray) {
		String[] result = new String[builderArray.length];
		for (int i = 0; i < builderArray.length; i++) result[i] = builderArray[i].toString();
		return result;	
	}
}
//Powered by [KawigiEdit] 2.0!