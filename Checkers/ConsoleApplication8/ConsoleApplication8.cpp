#include <iostream>
#include <vector>

using namespace std;

int i = 0, j = 0;
char numberLetter[8]{ 'a','b','c','d','e','f','g','h' };
struct Board {
	struct position {
		int x;
		int y;
	};
	class Checker {
	public:
		Checker() { 
			p.x = 1;
			p.y = 1;
			color = true;
		}
		Checker(int x1, int y1, bool color1) {
			p.x = x1;
			p.y = y1;
			color = color1;
		}
		vector <Checker> chekersList;
		position p;
		bool color;
		//possible position
		vector <position> posPos;
		//print possible position
		void print_posPos() {
			for (i = 0; i < posPos.size(); i++) {
				cout << numberLetter[posPos.at(i).x - 1] << posPos.at(i).y << endl;
			}
		}
		void set_posPos() {
			position f;
			int xf = p.x, yf = p.y,myf;
			if (color) {
				myf = 1;
			}
			else {
				myf = -1;
			}
			for (i = -1; i < 2; i += 2) {
				xf += i;
				for (j = 0; j < chekersList.size(); j++) {
					if (!(chekersList.at(j).p.x == xf && (chekersList.at(j).p.y) == yf+myf)) {
						f.x = xf;
						f.y = yf + myf;
						if(xf > 0 && xf < 9 && yf > 0 && yf < 9)posPos.push_back(f);
					}
					if (chekersList.at(j).p.x == xf && (chekersList.at(j).p.y) == yf + myf && chekersList.at(j).color == color) {
						for (int l = 0; l < chekersList.size(); l++) {
							if (!!(chekersList.at(j).p.x == xf + i && (chekersList.at(j).p.y) == yf + 2 * myf)) {
								f.x = xf + i;
								f.y = yf + 2 * myf;
								if (xf > 0 && xf < 9 && yf > 0 && yf < 9) posPos.push_back(f);
							}
						}
					}
					if (chekersList.at(j).p.x == xf && (chekersList.at(j).p.y) == yf + -1 * myf && chekersList.at(j).color == color) {
						for (int l = 0; l < chekersList.size(); l++) {
							if (!!(chekersList.at(j).p.x == xf + i && (chekersList.at(j).p.y) == yf + -2 * myf)) {
								f.x = xf + i;
								f.y = yf + -2 * myf;
								if(xf > 0 && xf < 9 && yf > 0 && yf < 9) posPos.push_back(f);
							}
						}
					}
				}
				xf = p.x;
			}
		}
	};
	
	
};
	
	

int main()
{
	Board board;
	Board::Checker checker(3,3,true);
	checker.chekersList.push_back(checker);
	checker.set_posPos();
	checker.print_posPos();
}