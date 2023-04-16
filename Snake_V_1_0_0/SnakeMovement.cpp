#include "Header.h"

void UP(int &iOldValX, int &iOldValY, vector<int> &SnakePositionX, vector<int> &SnakePositionY, int &iRandomMoving)
{
	iOldValX = SnakePositionX[0];		//old head position			
	iOldValY = SnakePositionY[0];		
	SnakePositionX[0] = SnakePositionX[0];			//new head position
	SnakePositionY[0] = SnakePositionY[0] - 1;	
	iRandomMoving = 1;
}

void RIGHT(int& iOldValX, int& iOldValY, vector<int>& SnakePositionX, vector<int>& SnakePositionY, int& iRandomMoving)
{
	iOldValX = SnakePositionX[0];		
	iOldValY = SnakePositionY[0];		
	SnakePositionX[0] = SnakePositionX[0] + 1;	
	SnakePositionY[0] = SnakePositionY[0];		
	iRandomMoving = 2;
}

void DOWN(int& iOldValX, int& iOldValY, vector<int>& SnakePositionX, vector<int>& SnakePositionY, int& iRandomMoving)
{
	iOldValX = SnakePositionX[0];			
	iOldValY = SnakePositionY[0];		
	SnakePositionX[0] = SnakePositionX[0];			
	SnakePositionY[0] = SnakePositionY[0] + 1;	
	iRandomMoving = 3;
}

void LEFT(int& iOldValX, int& iOldValY, vector<int>& SnakePositionX, vector<int>& SnakePositionY, int& iRandomMoving)
{
	iOldValX = SnakePositionX[0];				
	iOldValY = SnakePositionY[0];		
	SnakePositionX[0] = SnakePositionX[0] - 1;	
	SnakePositionY[0] = SnakePositionY[0];			
	iRandomMoving = 4;
}