#include "BmpManager.h"
#include "ShapesManager.h"
#include "Polygon.h"
#include "Circle.h"
using namespace std;

map<string, vector<SDL_Surface*>> BmpManager::bitmaps = map<string, vector<SDL_Surface*>>();

void BmpManager::loadStaticBitmap(const string& objectName, int radius)
{
	if (isntLoadedAlready(objectName))
	{
		addShapeAndVector(objectName, new Circle(radius));
		addStaticBitmap(objectName);
	}
}

void BmpManager::loadStaticBitmap(const string& objectName, const vector<MathPoint>& corners)
{
	if (isntLoadedAlready(objectName))
	{
		addShapeAndVector(objectName, new Polygon(corners));
		addStaticBitmap(objectName);
	}
}

void BmpManager::loadAnimation(const std::string& objectName, const std::vector<MathPoint>& corners, int numberOfAnimations)
{
	if (isntLoadedAlready(objectName))
	{
		addShapeAndVector(objectName, new Polygon(corners));
		addAnimations(objectName, numberOfAnimations);
	}
}

void BmpManager::loadAnimation(const std::string& objectName, int radius, int numberOfAnimations)
{
	if (isntLoadedAlready(objectName))
	{
		addShapeAndVector(objectName, new Circle(radius));
		addAnimations(objectName, numberOfAnimations);
	}
}

void BmpManager::addShapeAndVector(const string& objectName, Shape* shape)
{
	bitmaps.insert(pair <string, vector<SDL_Surface*>>(objectName, vector<SDL_Surface*>()));
	ShapesManager::addShape(objectName, shape);
}

void BmpManager::addAnimations(const std::string& objectName, int numberOfAnimations)
{
	vector<SDL_Surface*>& animationVector = (bitmaps.find(objectName)->second);
	for (int i = 1; i <= numberOfAnimations; i++)
	{
		string animationName = "./" + objectName + "_an_" + to_string(i) + ".bmp";
		animationVector.push_back(SDL_LoadBMP(animationName.c_str()));
	}
}

bool BmpManager::isntLoadedAlready(const std::string& objectName)
{
	return bitmaps.find(objectName) == bitmaps.end();
}

void BmpManager::addStaticBitmap(const string& objectName)
{
	string path = "./" + objectName + ".bmp";
	(bitmaps.find(objectName)->second).push_back(SDL_LoadBMP(path.c_str()));
}

void BmpManager::freeBitmaps()
{
	for (auto bitmapsVector : bitmaps)
	{
		for (SDL_Surface* bitmap : bitmapsVector.second)
			SDL_FreeSurface(bitmap);
	}
	bitmaps.clear();
}

SDL_Surface* BmpManager::getBitmap(const string& objectName)
{
	return (bitmaps.find(objectName)->second)[0];
}

SDL_Surface* BmpManager::getAnimation(const string& objectName, int numberOfAnimation)
{
	return (bitmaps.find(objectName)->second)[numberOfAnimation];
}