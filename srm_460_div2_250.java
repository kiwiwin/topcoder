import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TheQuestionsAndAnswersDivTwo
{
	public int find(String[] questions)
	{
		Set<String> Q = new HashSet<String>();
		Q.addAll(Arrays.asList(questions));
//		for (int i = 0; i < questions.length; i++) Q.add(questions[i]);
		return 1 << (Q.size());
//		return (int)Math.pow(2, Q.size());
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!