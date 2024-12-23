#include <bits/stdc++.h>
using namespace std;

const int SIZE = 5;

vector<vector<int>> visited(SIZE, vector<int>(SIZE, -1));

int movesX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int movesY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool checkInsideBoard(int positionX, int positionY) {
    return (positionX < SIZE && positionX >= 0 && positionY < SIZE && positionY >= 0 && visited[positionX][positionY] == -1);
}

int knightTour(int StepCount, int positionX, int positionY) {

    if (StepCount == SIZE*SIZE) {
        return 1;
    }
    for (int i = 0; i < 8; i++) {
        int newPositionX = positionX + movesX[i];
        int newPositionY = positionY + movesY[i];

        if (checkInsideBoard(newPositionX, newPositionY)) {
            visited[newPositionX][newPositionY] = StepCount;
            int result = knightTour(StepCount+1, newPositionX, newPositionY);

            if (result) {
                return 1;
            } else {
                visited[newPositionX][newPositionY] = -1;
            }
        }
    }
    return 0;
}

void printsol() {
    for (int i = 0; i < visited.size(); i++)  
    { 
        for (int j = 0; j < visited[i].size(); j++) 
        { 
            cout << visited[i][j] << " "; 
        }     
        cout << endl; 
    } 
}

int main() {

    visited[0][0] = 0;
    
    int result = knightTour(1, 0, 0);

    if (!result) {
        cout<<"solution desnot exist"<<endl;
    } else {
        printsol();
    }

    return 0;
}