#include <iostream>
#include "GenPoint.h"
#include "graph1.h"
#include "City.h"

using namespace std;

int main()
{
	int Shape_no = 0;
	City city;
	char* fn = new char[255];
	char repeat = 'Y';
	double dist = 0;

	do
	{

		displayGraphics();
		
		cout << "What '.txt' file would you like to use? ";
		cin >> fn;

		city.setData(fn);
		dist = city.computeDistance();
		city.getName();
		city.getHighway();
		city.getElevation();
	  city.draw();
	
		cout << "Distance between Little Rock and " << city.getName() << " located on" << city.getHighway() << endl;
		cout << " with an elevation of " << city.getElevation() << " feet is " << dist << " miles." << endl;

	cout << "Would you like to repeat?" << endl;
	cin >> repeat;
	clearGraphics();
	system("cls");
	
		
	}while(repeat == 'y' || repeat == 'Y');
		


}