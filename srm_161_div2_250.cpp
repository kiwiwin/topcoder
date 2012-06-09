#include <string>
#include <vector>
using namespace std;
class CardCount{
public:
	string CutCards(int player,string deck){
		int leave = deck.size() % player;
		if(leave != 0)
			deck.erase( deck.end() - leave, deck.end() );
		return deck;
	}
	
	vector <string> dealHands(int numPlayers, string deck){
		string real = CutCards(numPlayers,deck);
		vector<string> hands;
		hands.resize(numPlayers);
		int j = 0;
		while(j != real.size())
		{
			for(int i = 0; i < numPlayers; i++)
			{
				hands[i].push_back(real[j]);
				j++;
			}
		}
		return hands;
	}
};