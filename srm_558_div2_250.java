import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SurroundingGameEasy
{
	private String[] C;
	private String[] B;
	private String[] S;
	
	public int score(String[] cost, String[] benefit, String[] stone)
	{
		C = cost; B = benefit; S = stone;
		return allBenefit() - allCost();
	}
	
	private int allBenefit() {
		int res = 0;
		for (int i = 0; i < S.length; i++)
		for (int j = 0; j < S[i].length(); j++)
			if (isCellDominated(i, j)) res += B[i].charAt(j) - '0';
		return res;
	}
	
	private boolean isCellDominated(int i, int j) {
		if (S[i].charAt(j) == 'o') return true;
		if (i > 0 && S[i-1].charAt(j) != 'o') return false;
		if (i < S.length-1 && S[i+1].charAt(j) != 'o') return false;
		if (j > 0 && S[i].charAt(j-1) != 'o') return false;
		if (j < S[i].length()-1 && S[i].charAt(j+1)  != 'o') return false;
		return true; 
	}
	
	private int allCost() {
		int res = 0;
		for (int i = 0; i < S.length; i++)
		for (int j = 0; j < S[i].length(); j++)
			if (S[i].charAt(j) == 'o') res += C[i].charAt(j) - '0';
		return res;
	}
	
}
//Powered by [KawigiEdit] 2.0!