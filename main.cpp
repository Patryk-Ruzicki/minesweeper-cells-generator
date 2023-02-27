#include <iostream>
#include <random>

using namespace std;

int main()
{
    
    srand(time(NULL));
    
    int max = 5, min = 0, bPosY, bPosX, bombsAmount = 20, random;
    
    int testXY[12][12] = {};
    
    //set bombs randomly
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(bombsAmount > 1){
                random = (rand()%(max + min)) + min;
                if(random == 0){
                    
                    //set increment around the bomb
                        testXY[i-1][j-1] += 1;
                        testXY[i-1][j] += 1;
                        testXY[i-1][j+1] += 1;
                        testXY[i][j-1] += 1;
                        testXY[i][j] = 99;
                        testXY[i][j+1] += 1;
                        testXY[i+1][j-1] += 1;
                        testXY[i+1][j] += 1;
                        testXY[i+1][j+1] += 1;
                        
                        bombsAmount--;
                    //cout << "[" << bombsAmount << "]" << endl; //test line
                }
            }
        }
    }
    
    
    //display cells
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++)
            cout << testXY[i][j] << "\t";
        cout << endl;
    }
    
    
    return 0;
}