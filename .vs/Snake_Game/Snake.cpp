#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

class Snake {
private:
    bool gameOver;
    const int width = 20, height = 20;
    int x, y, fruitX, fruitY, score, tailX[100], tailY[100], nTail;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
public:
    Snake() {
        srand(time(0));
        gameOver = false;
        x = width / 2;
        y = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        score = 0;
        nTail = 0; // Initialize the tail length to 0
    }

    bool get_gameOver() const { return gameOver; }

    void Draw() {
        system("cls"); // Clear the console

        // Top wall
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        // Sides and inside of the game area
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    cout << "#"; // Left wall
                if (i == y && j == x)
                    cout << "O";
                else if (i == fruitY && j == fruitX)
                    cout << "F";
                else {
                    bool print = false;

                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " "; // Empty space
                }
                    
                if (j == width - 1)
                    cout << "#"; // Right wall
            }
            cout << endl;
        }

        // Bottom wall
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        cout << "Score: " << score << endl;
    }



    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'w':
                dir = UP;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
    }
        }
    }

    void Logic() {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        
        switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }
         // Check for boundary conditions
        if (x >= width) x = 0; else if (x < 0) x = width - 1;
        if (y >= height) y = 0; else if (y < 0) y = height - 1;
        
        // Check if the snake hits itself
        for (int i = 0; i < nTail; i++) {
            if (tailX[i] == x && tailY[i] == y)
                gameOver = true;
    }

        // Check if the snake eats the fruit
        if (x == fruitX && y == fruitY) {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            nTail++;
    }
}

};

int main() {
    Snake snake;
    while (!snake.get_gameOver()) {
        snake.Draw();
        snake.Input();
        snake.Logic();
        Sleep(100);
    }


    return 0;
}
