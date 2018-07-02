#ifndef BOARD_H
#define BOARD_H

#include "snake.h"

enum Direction
{
    Up = 72,
    Down = 80,
    Left = 75,
    Right = 77
};

/* Tutaj mały hack.
 * Nie można utworzyć enumów, które by zawierały chary.
 * (Tzn można, ale to troche komplikuje później)
 * Zrobilem sobie tak o, bo mi sie tak podobało xD
 * */
namespace Symbol
{
    const char Empty = ' ';
    const char Snake = 'o';
    const char Apple = '$';
}

class Board
{
public:
    // Do konstruktora można przekazać także parametr
    Board(int size);
    // Destruktor, wywołuje się zawsze PRZED usunięciem obiektu klasy z pamięci
    ~Board();

    bool isGameOver() const; // const na końuc metody wskazuje na to, że metoda nie zmienia żadnych wartości żadnego membera klasy. właściwie to zabrania tego zrobić
    //jeżeli spróbujesz zmienić wartość membera w const metodzie, to kompilator wyjebie error
    void draw() const;
    int getScore() const;
    void moveSnake(Direction newDirection);

private:
    int m_size;
    int m_score = 0;
    char** m_board = nullptr; // nullptr - kiedyś używało się NULL ale był problematyczny i zrobili coś takiego jak nullptr. jak pewnie sie domyślasz, ustawia wskaźnik na pusty
    bool m_gameOver = false;
    Direction m_currentDirection;
    Snake m_snake;

    void generateApple();
    void makeMove();
};

#endif // BOARD_H
