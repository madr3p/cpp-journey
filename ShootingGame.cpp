#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

const int width = 20;
const int height = 20;

int playerX = width / 2;
bool gameOver = false;
int score = 0;

struct Bullet {
    int x, y;
    bool active;
};

struct Enemy {
    int x, y;
    bool alive;
};

Bullet bullet = {0, 0, false};
vector<Enemy> enemies;

void Setup() {
    gameOver = false;
    score = 0;
    playerX = width / 2;
    enemies.clear();

    // Spawn enemies at top
    for (int i = 0; i < 5; i++) {
        Enemy e = {rand() % width, rand() % (height / 2), true};
        enemies.push_back(e);
    }
}

void Draw() {
    COORD pos = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bool printed = false;

            // Draw bullet
            if (bullet.active && bullet.x == x && bullet.y == y) {
                cout << "|";
                printed = true;
            }

            // Draw enemies
            for (auto& e : enemies) {
                if (e.alive && e.x == x && e.y == y) {
                    cout << "X";
                    printed = true;
                    break;
                }
            }

            // Draw player
            if (y == height - 1 && x == playerX) {
                cout << "^";
                printed = true;
            }

            if (!printed) cout << " ";
        }
        cout << endl;
    }

    cout << "Score: " << score << " | Press X to quit" << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                if (playerX > 0) playerX--;
                break;
            case 'd':
                if (playerX < width - 1) playerX++;
                break;
            case ' ':
                if (!bullet.active) {
                    bullet.x = playerX;
                    bullet.y = height - 2;
                    bullet.active = true;
                }
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic() {
    // Move bullet
    if (bullet.active) {
        bullet.y--;
        if (bullet.y < 0) bullet.active = false;

        // Bullet hits enemy
        for (auto& e : enemies) {
            if (e.alive && e.x == bullet.x && e.y == bullet.y) {
                e.alive = false;
                bullet.active = false;
                score += 10;
                break;
            }
        }
    }

    // Move enemies down
    static int frame = 0;
    frame++;
    if (frame % 10 == 0) {
        for (auto& e : enemies) {
            if (e.alive) {
                e.y++;
                if (e.y >= height - 1) {
                    gameOver = true;
                }
            }
        }
    }
}

int main() {
    system("mode con: cols=40 lines=25");
    Setup();

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(50); // adjust to slow down
    }

    cout << "\nGame Over! Final Score: " << score << endl;
    system("pause");
    return 0;
}
