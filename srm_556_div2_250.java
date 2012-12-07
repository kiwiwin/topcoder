import java.lang.*;

public class ChocolateBar {
	public int maxLength(String letters) {
		int result = 1;
		for (int i = 0; i < letters.length(); i++) {
			for (int j = i+1; j <= letters.length(); j++) {
				String temp = letters.substring(i,j);
				if (isUnique(temp))
					result = Math.max(temp.length(), result);
			}
		}
		return result;
	}
	
	private boolean isUnique(String s) {
		for (int i = 0; i < s.length(); i++)
			for (int j = i+1; j < s.length(); j++)
				if (s.charAt(i) == s.charAt(j)) return false;
		return true;
	}
}
