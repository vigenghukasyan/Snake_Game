#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

class Snake {
private:
    bool gameOver;
    const int width = 20, height = 20;
    int x, y, fruitX, fruitY, score;
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
                else
                    cout << " "; // Empty space

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
        if (x > width || x < 0 || y > height || y < 0)
            gameOver = true;
        if (x == fruitX && y == fruitY) {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
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
