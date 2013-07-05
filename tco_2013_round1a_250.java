import java.util.*;

public class HouseBuilding {
	public int getMinimum(String[] area) {
		int result = Integer.MAX_VALUE;
	
		for (int level = 0; level <= 8 ; level++) {
			int temp = 0;
			for(Integer height : heights(area)) {
				temp += Math.min(Math.abs(height - level), Math.abs(height - level - 1));
			}
			result = Math.min(temp, result);
		}			
			
		return result;
	}
	
	private List<Integer> heights(String[] area) {
		List<Integer> result = new ArrayList<Integer>();
		for (int i = 0; i < area.length; i++)
		for (int j = 0; j < area[i].length(); j++)
			result.add((int)(area[i].charAt(j) - '0'));
		return result;
	}
}
