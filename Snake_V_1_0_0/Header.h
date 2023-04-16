#ifndef __HEADER_H__
#define __HEADER_H__

#include <iostream>
#include "windows.h"	//rand()
#include <conio.h>		//_getch() - reading a character from the keyboard
#include <vector>

using namespace std;

void UP(int&, int&, vector<int>&, vector<int>&, int&);
void RIGHT(int&, int&, vector<int>&, vector<int>&, int&);
void LEFT(int&, int&, vector<int>&, vector<int>&, int&);
void DOWN(int&, int&, vector<int>&, vector<int>&, int&);

void HIT_HERSELF(int, vector<int>&, vector<int>&, int&);
void HIT_AT_WALL(vector<int>&, vector<int>&, int&, int&, int&);

#endif // !__HEADER_H__