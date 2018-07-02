#include "game.h"

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int BOARD_SIZE = 9;

Game::Game() :
    m_board(BOARD_SIZE)
/* To wyżej to lista inijalizująca.
 * Pozwala na zainicjalizowanie memberów klasy jeszcze PRZED utoworzeniem instatncji.
 * Dzięki niej można również wywołac konstruktory klas, które inicjalizujemy, tak jak wyżej.
 */
{

}

void Game::run()
{
    while (!m_board.isGameOver())
    {
        system("cls");

        m_board.draw();
        cout << "Score: " << m_board.getScore() << endl;

        Direction direction = (Direction)getch();

        m_board.moveSnake(direction);
    }

    cout << "You end the game with score: " << m_board.getScore() << endl;
}
