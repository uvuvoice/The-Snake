#include "Header.h"

void HIT_HERSELF(int ArrOfSnakePositionX, vector<int> &SnakePositionX, vector<int> &SnakePositionY, int &iSnakeLive)
{
	for (int i = 1; i < ArrOfSnakePositionX; i++){
		if (SnakePositionX[0] == SnakePositionX[i] && SnakePositionY[0] == SnakePositionY[i]){
			iSnakeLive = 0;  //Game Over		
		}
	}
}

void HIT_AT_WALL(vector<int> &SnakePositionX, vector<int> &SnakePositionY, int &iLengthSize, int & iHeightSize, int &iSnakeLive)
{
	if (iSnakeLive == 1){
		if (SnakePositionX[0] > 0 && SnakePositionX[0] < iLengthSize && SnakePositionY[0] > 0 && SnakePositionY[0] < iHeightSize) //проверка удара со стеной
			iSnakeLive = 1;	//Game Continues
		else
			iSnakeLive = 0;	//Game Over
	}
	else
		iSnakeLive = 0;	//Game Over
}