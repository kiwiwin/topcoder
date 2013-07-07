import java.util.*;

public class EllysPairs {
	public int getDifference(int[] knowledge) {
		Arrays.sort(knowledge);
		int best = 0, worst = 2500;
		for (int i = 0; i < knowledge.length; i++) {
			int pair_score = knowledge[i] + knowledge[knowledge.length - 1 - i];
			best = Math.max(pair_score, best);
			worst = Math.min(pair_score, worst);
		}
		return best - worst;
	}
}
