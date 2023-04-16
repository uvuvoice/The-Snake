#include "Header.h"

int main()
{
	// Explanation of the "rand()" function 
	//if a - left limit, b - right limit
	//then: rand()%(b-a+1)+a; 

	int total = 0;  //score counter
	cout << "Total " << total << endl;

	int iLengthSize = 20, iHeightSize = 10;  //field parameters

	int iFruitLength = rand() % (iLengthSize - 1) + 1;  //fruit parameters
	int	iFruitHeight = rand() % (iHeightSize - 2) + 1;  //random place where the fruit appears at length and height
	int iOneFruitChecking;  //there should be only one fruit on field	

	int iSnakeLive = 1;  //snake parameters
	vector<int> Snake = {1}, SnakePositionX, SnakePositionY;
	int iRandSnakeHeadX = rand() % (iLengthSize - 1) + 1;
	int iRandSnakeHeadY = rand() % (iHeightSize - 2) + 1;  //random place where the snake's head appears at length and height
	SnakePositionX.insert(SnakePositionX.begin(), iRandSnakeHeadX);
	SnakePositionY.insert(SnakePositionY.begin(), iRandSnakeHeadY);
	int iRandomMoving = rand() % (4 - 1 + 1) + 1;  //a random direction of snake movement: 1-up, 2-right, 3-down, 4-left

	while (iSnakeLive == 1){  //rendering
		iOneFruitChecking = 1;
		for (int y = 0; y < iHeightSize; y++){  //row counter (by height)
			for (int x = 0; x < iLengthSize; x++){  //column counter for current row (by lenght)	
				if (y == 0 || y == iHeightSize - 1)	cout << '*';  //printig a '*' for the 1st and last rows 
				else{
					if (x == 0 || x == iLengthSize - 1) cout << '*';  //printing a friut and snake's head or nothing (for edges by lenght also '*')
					else if (x == iFruitLength && y == iFruitHeight && iOneFruitChecking == 1) {  //appearing of 1 fruit in 1 random place
						if (x == SnakePositionX[0] && y == SnakePositionY[0]) cout << Snake[0];  //checking what should to draw: a Snake's head or a fruit						
						else {
							cout << 'o'; iOneFruitChecking = 0;	//until snake eats this fruit		
						}
					}
					else {  //printing other snake's parts					
						int check = 0;
						for (int i = 0; i < SnakePositionX.size(); i++) {
							if (x == SnakePositionX[i] && y == SnakePositionY[i]) {
								cout << Snake[i]; check = 1;
							}
						}
						if (check == 0) cout << ' ';						
					}
				}
			}//column counter for current row (by lenght)
			cout << '\n';
		}//row counter (by height)

		/* After full rendering */		
		for (int i = 10; i > 0; i--) Sleep(20);  //delay for decision-making			
		
		int iOldValX = 0, iOldValY = 0;
		int iArrGetch[2];  //for function _getch()
		
		if (_kbhit() != 0){  //0 - the keyboard buffer is empty, 1 - there was a click		
			*iArrGetch = _getch();
			*(iArrGetch + 1) = _getch();

			switch (*(iArrGetch+1)){
			case 72:	//moving up
				UP(iOldValX, iOldValY, SnakePositionX, SnakePositionY, iRandomMoving); break;
			case 77:	//moving right
				RIGHT(iOldValX, iOldValY, SnakePositionX, SnakePositionY, iRandomMoving); break;
			case 80:	//moving down
				DOWN(iOldValX, iOldValY, SnakePositionX, SnakePositionY, iRandomMoving); break;
			case 75:	//moving left
				LEFT(iOldValX, iOldValY, SnakePositionX, SnakePositionY, iRandomMoving); break;
			}
		}
		else{  //if the key is not pressed		
			switch (iRandomMoving){
			case 1:	//moving up
				UP(iOldValX, iOldValY, SnakePositionX, SnakePositionY, iRandomMoving);
				break;
			case 2:	//moving right
				RIGHT(iOldValX, iOldValY, SnakePositionX, SnakePositionY, iRandomMoving);
				break;
			case 3:	//moving down
				DOWN(iOldValX, iOldValY, SnakePositionX, SnakePositionY, iRandomMoving);				
				break;
			case 4:	//moving left
				LEFT(iOldValX, iOldValY, SnakePositionX, SnakePositionY, iRandomMoving);
				break;
			}
		}

		HIT_HERSELF(SnakePositionX.size(), SnakePositionX, SnakePositionY, iSnakeLive);  //hit check
		HIT_AT_WALL(SnakePositionX, SnakePositionY, iLengthSize, iHeightSize, iSnakeLive);

		if (iOldValX == iFruitLength && iOldValY == iFruitHeight){ //if snake coordinates == fruit coordinates
			iFruitLength = rand() % (iLengthSize - 1) + 1;
			iFruitHeight = rand() % (iHeightSize - 2) + 1;  //new random place where the fruit appears at length and height
			total++;
			Snake.push_back(0);  //adding one part (zero symbol) to snake			
			SnakePositionX.push_back(0);  //increasing the size of the vector by 1
			SnakePositionY.push_back(0);	
		}

		for (int x = 0; x < SnakePositionX.size()-1; x++){  //required offset of the snake body coordinates for new rendering
			int iOldX = SnakePositionX[x + 1];
			int iOldY = SnakePositionY[x + 1];
			SnakePositionX[x + 1] = iOldValX;
			SnakePositionY[x + 1] = iOldValY;
			iOldValX = iOldX;
			iOldValY = iOldY;
		}

		iOneFruitChecking++;  //appearance of a one fruit in a new random place
		system("cls");  //console clearing
		cout << "Total " << total << endl;  //output of total points	
	}
	cout << "Game Over" << endl;
}