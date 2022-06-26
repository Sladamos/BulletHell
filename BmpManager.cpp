#include "BmpManager.h"
using namespace std;

map<string, vector<SDL_Surface*>> BmpManager::bitmaps = map<string, vector<SDL_Surface*>>();

void BmpManager::loadStaticBitmap(string objectName)
{
	vector<SDL_Surface*> bmpVector = { SDL_LoadBMP("./eti.bmp") };
	bitmaps.insert(pair <string, vector<SDL_Surface*> >(objectName, bmpVector ));
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

void BmpManager::getBitmap(string objectName)
{
	
}