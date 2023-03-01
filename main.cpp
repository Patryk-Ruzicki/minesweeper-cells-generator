#include <iostream>

using namespace std;

int main()
{
    
    srand(time(NULL));
    
    int bombPosY, bombPosX, boardX = 12, boardY = 12, bombsAmount = 20, random;
    
    int testXY[boardY][boardX] = {};
    
    //set bombs randomly
    do{
        bombPosX = (rand() % 10) + 1;
        bombPosY = (rand() % 10) + 1;
        
        if(testXY[bombPosY][bombPosX] < 10){
            
            //set increment around the bomb
            
            testXY[bombPosY][bombPosX] = 88;
            
            testXY[bombPosY][bombPosX-1] += 1;
            testXY[bombPosY][bombPosX+1] += 1;
            
            for(int i = -1; i < 2; i++){
                testXY[bombPosY-1][bombPosX+i] += 1;
                testXY[bombPosY+1][bombPosX+i] += 1;
            }
            bombsAmount--;
        }
        
    }while(bombsAmount > 0);
    
    
    //display cells
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++)
            cout << testXY[i][j] << "\t";
        cout << endl;
    }
    
    return 0;
}
