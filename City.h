#ifndef CITY_H
#define CITY_H

#include "GenPoint.h"

class City
{
	private:

		char* name;
		char* highway;
		GenPoint location;
		int elevation;
		const static int NUMBER_CITIES = 31;

	public:
	
		City();
		~City();
		City(const City& city);
		void setData(char* fn);
		char* getName();
		char* getHighway();
		GenPoint getLocation();
		int getElevation();
		double computeDistance();
		void draw();
};

#endif