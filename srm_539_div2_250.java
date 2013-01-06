import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class PlatypusPaternity
{
	public int maxFamily(String[] F, String[] M, String[] S)
	{
		int result = 0;
		for (int f = 0; f < F.length; f++)
		for (int m = 0; m < M.length; m++)
		for (int s = 0; s < S.length; s++)
			if (parentsCompatible(intersect(F[f], M[m]), (S[s]))) { result = Math.max(result, countY(S[s])+2);}
		return result;
	}
	
	private boolean parentsCompatible(String P, String S) {
		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == 'Y' && P.charAt(i) != 'Y') return false;
		}
		return true;
	}
	
	private int countY(String str) {
		int result = 0;
		for (int i = 0; i < str.length(); i++) if (str.charAt(i) == 'Y') result ++;
		return result;
	}
	
	private String intersect(String lhs, String rhs) {
		StringBuilder result = new StringBuilder(lhs);
		for (int i = 0; i < rhs.length(); i++) {
			if (result.charAt(i) == 'Y' && rhs.charAt(i) == 'Y') result.setCharAt(i, 'Y');
			else result.setCharAt(i, 'N');
		}
		return result.toString();
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!