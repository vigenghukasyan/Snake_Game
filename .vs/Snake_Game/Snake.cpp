#include <iostream>
#include <Windows.h>
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

    }

    void Logic() {

    }

};

int main() {
    Snake snake;
    while (!snake.get_gameOver()) {
        snake.Draw();
        snake.Input();
        snake.Logic();
    }


    return 0;
}
