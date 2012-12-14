import java.util.*;

public class TheBrickTowerEasyDivTwo {
	private int RC, RH, BC, BH;

	public int find(int RC, int RH, int BC, int BH) {
		this.RC = RC; this.RH = RH; this.BC = BC; this.BH = BH;
		Set<Integer> S = new HashSet<Integer>();
		for (int r = 0; r <= RC; r++)
		for (int b = r-1; b <= r+1; b++) 
		if (varifyBlueCount(b)) S.add(r * RH + b * BH);

		return S.size() -1;
	}
	
	private boolean varifyBlueCount(int count) {
		return count >= 0 && count <= BC;
	}
}
