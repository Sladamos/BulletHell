#include "BmpManager.h"
using namespace std;

map<string, vector<SDL_Surface*>> BmpManager::bitmaps = map<string, vector<SDL_Surface*>>();

void BmpManager::loadStaticBitmap(const string& objectName)
{
	if (bitmaps.find(objectName) == bitmaps.end())
	{
		string path = "./" + objectName + ".bmp";
		vector<SDL_Surface*> bmpVector = { SDL_LoadBMP(path.c_str()) };
		bitmaps.insert(pair <string, vector<SDL_Surface*>>(objectName, bmpVector));
	}
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