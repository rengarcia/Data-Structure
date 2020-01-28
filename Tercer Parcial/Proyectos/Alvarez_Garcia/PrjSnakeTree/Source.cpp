#include <SFML/Graphics.hpp>
#include <SFML//Graphics/Text.hpp>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include "BinaryTree.h"
#include "UtilMenu.h"

#define size 20
#define N 30
#define M 20
#define UP 72
#define DOWN 80
#define ENTER  13
#define ESCAPE 27
#define LEFT 75
#define RIGHT 77

using namespace sf;

///// variables ///////
ABB tree = NULL;
int dir, num = 4;
int auxX = 0; //for printing
bool GAMEOVER = false;

//// classes ///
class Snake {
public:
    int x, y;
}s[100];

class Fruit {
public:
    int x, y;
    int number; //random from 1 to 50
}f;
//////////////

void Tick() {
    ////// next state /////
    for (int i = num; i > 0; --i) {
        s[i].x = s[i - 1].x; s[i].y = s[i - 1].y;
    }

    ///// Movement /////
    if (dir == 0) s[0].y += 1;
    if (dir == 1) s[0].x -= 1;
    if (dir == 2) s[0].x += 1;
    if (dir == 3) s[0].y -= 1;

    ///// Get fruit /////
    if ((s[0].x == f.x) && (s[0].y == f.y)) {
        insert(tree, f.number);
        num++; 
        f.x = rand() % N; 
        f.y = rand() % M;
        f.number = 1 + (rand() % 51);
    }

    ///// Out of the screen /////
    if (dir == 0 && s[0].y >= M) GAMEOVER = true;
    if (dir == 1 && s[0].x < 0) GAMEOVER = true;
    if (dir == 2 && s[0].x >= N) GAMEOVER = true;
    if (dir == 3 && s[0].y < 0) GAMEOVER = true;

    ////// collision /////
    for (int i = 1; i < num; i++) {
        if (s[0].x == s[i].x && s[0].y == s[i].y) 
            GAMEOVER = true;
    }
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void showTree(ABB& tree, int auxY) {
    if (tree == NULL) {
        return;
    }
    auxX += 5;

    showTree(tree->left, auxY + 2);
    gotoxy(10 + auxX - auxY, 15 + auxY);
    cout << tree->number << endl << endl;
    showTree(tree->right, auxY + 2);
}

int main() {
	int posY = 0;
	menuSelecInformation();
	char key;

	while (true) {
		key = _getch();

		switch (key) {
		case UP:
			posY--;
			if (posY < 0) {
				posY = 3;
			}
			utilMenu(posY);
			break;

		case DOWN:
			posY++;
			if (posY == 0) {
				posY = 1;
			}
			if (posY > 3) {
				posY = 0;
			}
			utilMenu(posY);
			break;

		case ENTER:
            srand(time(0));
            RenderWindow window(VideoMode(size * N, size * M), "Snake Game!");
            window.setActive(false);
            window.setVisible(false);

            sf::Font font;
            font.loadFromFile("font/arial_narrow_7.ttf");

            sf::Text text;
            sf::String string;

            Texture t1, t2, t3, gameover;
            t1.loadFromFile("images/white.png");
            t2.loadFromFile("images/red.png");
            t3.loadFromFile("images/green.png");
            gameover.loadFromFile("images/gameover_1.jpg");

            Sprite sprite1(t1);
            Sprite sprite2(t2);
            Sprite sprite3(t3);
            Sprite spriteGO(gameover);

            Clock clock;
            float timer = 0, delay = 0.1, time;

            f.x = rand() % N;
            f.y = rand() % M;
            f.number = 1 + (rand() % 51);
			char tecla;

            Event e;

			switch (posY) {
			case 0:
				/*Show information about the game*/
				

				system("pause");
				break;

			case 1:
				/*PLAY NOW!*/
                window.setActive(true);
                window.setVisible(true);

                while (window.isOpen() && !GAMEOVER) {
                    time = clock.getElapsedTime().asSeconds();
                    clock.restart();
                    timer += time;

                    while (window.pollEvent(e)) {
                        if (e.type == Event::Closed)
                            window.close();
                    }

                    if (Keyboard::isKeyPressed(Keyboard::Left))  dir = 1;
                    if (Keyboard::isKeyPressed(Keyboard::Right)) dir = 2;
                    if (Keyboard::isKeyPressed(Keyboard::Up))    dir = 3;
                    if (Keyboard::isKeyPressed(Keyboard::Down))  dir = 0;

                    if (timer > delay) { timer = 0; Tick(); }

                    ////// draw  ///////
                    window.clear();

                    ///// chess //////
                    for (int i = 0; i < N; i++)
                        for (int j = 0; j < M; j++) {
                            sprite1.setPosition(i * size, j * size);  window.draw(sprite1);
                        }

                    ///// snake /////
                    for (int i = 0; i < num; i++) {
                        sprite2.setPosition(s[i].x * size, s[i].y * size);  window.draw(sprite2);
                    }

                    ///// fruit with number/////
                    sprite3.setPosition(f.x * size, f.y * size);  window.draw(sprite3);
                    string = to_string(f.number);
                    text.setString(string);
                    text.setFont(font);
                    text.setCharacterSize(12);
                    text.setFillColor(Color::Black);
                    text.setPosition(f.x * size, f.y * size); window.draw(text);

                    window.display();
                }
                window.clear();
                window.draw(spriteGO);
                window.display();
                Sleep(5000);
                window.close();

				/*PDF creation
				system("java -jar dist/textToPdf.jar");*/

				system("pause");
				break;

            case 2:
                /*Binary tree*/
                system("cls");
                cout << "\t\t\tARBOL RESULTANTE" << endl;
                auxX = 0;
                showTree(tree, 0);

                _getch();
                break;
			case 3:
				/*Exit*/

				std::cout << "Gracias por jugar :)" << std::endl;
				exit(0);
			}
			utilMenu(posY);
			break;
		}
	}

    return 0;
}
