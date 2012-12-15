public class FoxAndFlowerShopDivTwo {
    private int R;
	private	int C;
	private String[] F;
	public int theMaxFlowers(String[] flowers, int sR, int sC) {
		R = flowers.length;
		C = flowers[0].length();
		F = flowers;
		int result = 0;
		result = Math.max(getFlowersNumber(0, 0, R-1, sC-1), result);
		result = Math.max(getFlowersNumber(0, sC+1, R-1, C-1), result);
		result = Math.max(getFlowersNumber(0, 0, sR-1, C-1), result);
		result = Math.max(getFlowersNumber(sR+1, 0, R-1, C-1), result);
		return result;
	}
	
	private int getFlowersNumber(int smallR, int smallC, int bigR, int bigC) {
		int result = 0;
		for (int r = smallR; r <= bigR; r++)
		for (int c = smallC; c <= bigC; c++)
			if (F[r].charAt(c) == 'F') result++;
		return result;
	}
}