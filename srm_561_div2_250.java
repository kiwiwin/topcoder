import java.util.Arrays;

public class FoxAndVacation
{
	public int maxCities(int total, int[] d)
	{
		Arrays.sort(d);
		int index = 0;
		while(index < d.length && total >= d[index]) {
			total -= d[index]; index++;
		}
		return index;
	}
}
