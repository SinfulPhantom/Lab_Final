#include <iostream>
#include "GenPoint.h"
#include "graph1.h"
#include "City.h"
#include <ctime>
#include <fstream>

City::City()
{
	char* name = NULL;
	char* highway = NULL;
	elevation = NULL;
	NUMBER_CITIES;
}

City::~City()
{
	delete[] name;
	delete[] highway;
}

City::City(const City& city)
{
	int i = 0;
	int length = 0;

	name = new char [length];
	
		for(i=0; i < length; i++)
		{
			name[i] = city.name[i];
		}
}

 void City::setData(char* fn)
{
	char* file = "cities.txt";
	char word [1000];
	int line_no = 0;
	int line_count = 0;
	int x = 0;
	int y = 0;
  int i = 0;
	
	//open txt file
	 fstream in_file(file,ios::in);
		
		// test to see if opened correctly
		if(!in_file)
		{
			cout<< "Error cannot open file, check file spelling." << endl;
			exit(-1);
		}
	
		 srand(time(0));
		 line_no = rand()%NUMBER_CITIES-1;
		
			while(true)
			{
				in_file >> word;
				this->name = new char[strlen(word) + 1];
				strcpy(this->name, word);
		
				in_file >> x;
				in_file >> y;

				location.setPoint(x,y);

				in_file >> word;
				this->highway = new char[strlen(word) + 1];
				strcpy(this->highway, word);

				in_file >> elevation;
				

				//test for eof
				if (in_file.eof())
				break;

				//check the rand_no
				if (line_no == line_count)
				{
					break;
				}
				//increment the word_count
				line_count++;
		}	
}
char* City::getName()
{
	return name;
}		

char* City::getHighway()
{
	return highway;
}	

GenPoint City::getLocation()
{
  return this-> location;
}

int City::getElevation()
{
	return this-> elevation;
}
		
double City::computeDistance()
{
	double distance = 0;
	int LRx = 306;
	int LRy = 240;

	distance = sqrt((pow(LRx - location.getX(),2)) - pow(LRy - location.getY(),2));
	
	return distance;
}

void City::draw()
{
	int LRx = 306;
	int LRy = 240;
	int obj_no = 0;

	displayBMP("arkansas1.bmp",0,0);
	
	obj_no = drawLine(LRx,LRy,location.getX(),location.getY(),2);
	setColor(obj_no,0,0,255); 
}
			
