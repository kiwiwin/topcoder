#include <string>
#include <vector>

using namespace std;

class CubeNets {
public:
	vector<vector<string> > P;

	vector<string> T(const vector<string> &figure) {
		vector<string> res;
		for (int i = 0; i < figure[0].size(); i++) {
			string s = "";
			for (int j = 0; j < figure.size(); j++) {
				s += figure[j][i];
			}
			res.push_back(s);
		}
		return res;
	}
	
	vector<string> getSubFigure(const vector<string> &figure, int i, int j, int I, int J) {
		vector<string> res;
		for (int offset = 0; offset < I; offset++)
			res.push_back(figure[i+offset].substr(j, J));
		return res;	
	}
	
	bool canBeCube(const vector<string> &figure) {
		for (int p = 0; p < P.size(); p++) 
		for (int i = 0; i+P[p].size() <= figure.size(); i++)
		for (int j = 0; j+P[p][0].size() <= figure[i].size(); j++) {
			vector<string> subFigure = getSubFigure(figure, i, j, P[p].size(), P[p][0].size());
			if (subFigure == P[p]) return true;
		}
		
		return false;
	}
	
	string singleSquare(int index) {
		string res(4, '.');
		res[index] = '#';
		return res;
	}
	
	vector<string> turnRight(const vector<string> &figure) {
		vector<string> res(figure[0].size(), string(figure.size(), '.'));
		for (int i = 0; i < figure.size(); i++)
		for (int j = 0; j < figure[i].size(); j++)
			res[figure[i].size()-j-1][i] = figure[i][j];
		return res;
	}

 	string isCubeNet(vector<string> figure) {
		vector<string> tmp;
		tmp.push_back("###..");
		tmp.push_back("..###");
		P.push_back(tmp);
		
		tmp.clear();
		tmp.push_back("##..");
		tmp.push_back(".##.");
		tmp.push_back("..##");
		P.push_back(tmp);
		
		tmp.clear();
		tmp.push_back("..##");
		tmp.push_back("###.");
		tmp.push_back(".#..");
		P.push_back(tmp);
				
		tmp.clear();
		tmp.push_back("..##");
		tmp.push_back("###.");
		tmp.push_back("..#.");
		P.push_back(tmp);
		
		tmp.clear();
		tmp.push_back("..##");
		tmp.push_back("###.");
		tmp.push_back("#...");
		P.push_back(tmp);
		
		
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			tmp.clear();
			tmp.push_back(singleSquare(i));
			tmp.push_back("####");
			tmp.push_back(singleSquare(j));
			P.push_back(tmp);
		}
		
		
		//look as it is
		if (canBeCube(figure)) return "YES";
		for (int i = 0; i < 3; i++) {
			figure = turnRight(figure);
			cout << "turn" << endl;
			if (canBeCube(figure)) return "YES";
		}
		//T transation
		figure = T(figure);
		if (canBeCube(figure)) return "YES";
		for (int i = 0; i < 3; i++) {
			figure = turnRight(figure);
			if (canBeCube(figure)) return "YES";
		}
		return "NO";
	}
};
