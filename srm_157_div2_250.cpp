using namespace std;

class GuessTheNumber{
public:
	int noGuesses(int upper, int answer){
	    int tries = 0;
	    int guess = upper + 1;
	    int low = 1;
	    while( guess != answer)
	    {
	    	guess =  (upper + low) / 2;
	    	tries++;
	    	if (guess > answer)
	    		upper = guess - 1;
	    	if(guess < answer)
	    		low = guess + 1;
	    }
		return tries;
	}
};