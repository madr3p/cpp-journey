#include <iostream>
#include <conio.h>      // For _kbhit() and _getch()
#include <windows.h>    // For Sleep() and console cursor
using namespace std;

// Game variables
bool gameOver;
const int width = 20;
const int height = 20;

int x, y; // Snake head position
int tailX[100], tailY[100];
int nTail;

const int maxFruits = 100;
int fruitX[maxFruits], fruitY[maxFruits];
int fruitCount = 1;

int score;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Function to move the cursor to top left (no flickering)
void MoveCursorToTop() {
    COORD cursorPos;
    cursorPos.X = 0;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
}

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    score = 0;
    nTail = 0;
    fruitCount = 1;

    // Spawn the first fruit
    fruitX[0] = rand() % width;
    fruitY[0] = rand() % height;
}

void Draw() {
    MoveCursorToTop(); // No flicker screen

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Top border
    SetConsoleTextAttribute(hConsole, 7); // White
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                SetConsoleTextAttribute(hConsole, 7); // White
                cout << "#";
            }

            if (i == y && j == x) {
                SetConsoleTextAttribute(hConsole, 10); // Green (Snake head)
                cout << "O";
            } else {
                bool printed = false;

                // Tail
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        SetConsoleTextAttribute(hConsole, 14); // Yellow (Tail)
                        cout << "o";
                        printed = true;
                        break;
                    }
                }

                // Fruit
                if (!printed) {
                    for (int f = 0; f < fruitCount; f++) {
                        if (fruitX[f] == j && fruitY[f] == i) {
                            SetConsoleTextAttribute(hConsole, 12); // Red (Fruit)
                            cout << "F";
                            printed = true;
                            break;
                        }
                    }
                }

                // Empty space
                if (!printed) {
                    cout << " ";
                }
            }

            if (j == width - 1) {
                SetConsoleTextAttribute(hConsole, 7); // White
                cout << "#";
            }
        }
        cout << endl;
    }

    // Bottom border
    SetConsoleTextAttribute(hConsole, 7);
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Score display
    cout << "Score: " << score << "  ";
    cout << "Fruits: " << fruitCount << "  ";
    cout << "Press X to quit" << endl;

    // Reset to default color
    SetConsoleTextAttribute(hConsole, 7);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}

void Logic() {
    // Move tail
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

    // Move head
    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
    }

    // Wall wrapping
    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;

    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    // Tail collision
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // Check fruit collision
    for (int f = 0; f < fruitCount; f++) {
        if (x == fruitX[f] && y == fruitY[f]) {
            score += 10;
            nTail++;

            // Move eaten fruit to new position
            fruitX[f] = rand() % width;
            fruitY[f] = rand() % height;

            // Spawn a new fruit
            if (fruitCount < maxFruits) {
                fruitX[fruitCount] = rand() % width;
                fruitY[fruitCount] = rand() % height;
                fruitCount++;
            }
        }
    }
}

int main() {
    // Resize console for better experience (optional)
    system("mode con: cols=40 lines=30");

    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        int speed = 120;
	if (score > 50) speed = 100;
	if (score > 100) speed = 80;
	if (score > 200) speed = 60;
	Sleep(speed);
    }

    // Game over screen
    cout << "\nGame Over! Final Score: " << score << endl;
    system("pause");
    return 0;
}
