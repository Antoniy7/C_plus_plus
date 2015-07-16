#include <iostream>
#include <vector>
#include "FigureFactory.h"

typedef std::vector<Figure*> FIGVECTOR; // vidqh go tova  ot docent semerdzhiev :D 
using namespace std;
int main() {

	FIGVECTOR figures;

	FigureFactory pFactory("input.txt");

	Figure* pFigure = NULL;

	do {

	     pFigure = pFactory.createFigure();

		if (pFigure)
                  {
		   figures.push_back(pFigure);
	          }
		
	} while (pFactory.canCreate());


	double testX= 0.1;
	double testY = 0.2;

	for (int i = 0; i < figures.size(); i++) 
       {
		if (figures.at(i)->isPointInFigure(testx, testy)) // at(i) // tova e ot vektora 
                {
			cout << "is in the figure" <<endl;
		}
		else 
                {
			cout << "not in the figure" << endl;
		}
	}



	return 0;
}