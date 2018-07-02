#include "board.h"

#include <iostream>
#include <ctime>

using namespace std;

Board::Board(int size) :
    m_size(size)
{
    srand(time(nullptr));
    m_board = new char*[m_size];

    for (int i = 0; i < m_size; ++i)
    {
        m_board[i] = new char[m_size];

        for (int j = 0; j < m_size; ++j)
        {
            m_board[i][j] = Symbol::Empty;
        }
    }

    m_board[0][0] = Symbol::Snake;
    m_currentDirection = Right;

    generateApple();
}

Board::~Board()
{
    // destruktor to idealne miejsce, żeby zwolnić pamięc przydzieloną dynamicznie!
    if (m_board != nullptr)
    {
        for (int i = 0; i < m_size; ++i)
        {
            delete m_board[i];
        }

        delete[] m_board;
    }
}

bool Board::isGameOver() const
{
    return m_gameOver;
}

void Board::draw() const
{
    cout << "|";
    for (int i = 0; i < m_size; ++i)
    {
        cout << "-";
    }
    cout << "|" << endl;

    for (int i = 0; i < m_size; ++i)
    {
        cout << "|";

        for (int j = 0; j < m_size; ++j)
        {
            cout << m_board[i][j];
        }

        cout << "|" << endl;
    }

    cout << "|";
    for (int i = 0; i < m_size; ++i)
    {
        cout << "-";
    }
    cout << "|" << endl;
}

int Board::getScore() const
{
    return m_score;
}

void Board::moveSnake(Direction newDirection)
{
    Position2D head = m_snake.head;

    switch (newDirection)
    {

    case Up:
    {
        if (m_currentDirection != Down && head.x > 0)
        {
            if(m_board[head.x-1][head.y] == Symbol::Snake)
            {
                m_gameOver = true;
                break;
            }

            m_snake.head.x--;
            makeMove();
            m_currentDirection = Up;
        }

        break;
    }

    case Down:
    {
        if (m_currentDirection != Up && head.x < m_size-1)
        {
            if(m_board[head.x+1][head.y] == Symbol::Snake)
            {
                m_gameOver = true;
                break;
            }

            m_snake.head.x++;
            makeMove();
            m_currentDirection = Down;
        }

        break;
    }

    case Left:
    {
        if (m_currentDirection != Right && head.y > 0)
        {
            if(m_board[head.x][head.y-1] == Symbol::Snake)
            {
                m_gameOver = true;
                break;
            }

            m_snake.head.y--;
            makeMove();
            m_currentDirection = Left;
        }

        break;
    }

    case Right:
    {
        if (m_currentDirection != Left && head.y < m_size-1)
        {
            if(m_board[head.x][head.y+1] == Symbol::Snake)
            {
                m_gameOver = true;
                break;
            }

            m_snake.head.y++;
            makeMove();
            m_currentDirection = Right;
        }

        break;
    }

    }
}

void Board::generateApple()
{
    Position2D pos;

    do
    {
        pos.x = rand() % m_size;
        pos.y = rand() % m_size;
    }
    while (m_board[pos.x][pos.y] != Symbol::Empty);

    m_board[pos.x][pos.y] = Symbol::Apple;
}

void Board::makeMove()
{
    Position2D head = m_snake.head;

    /* Zwróc uwagę na &
     * Utworzyłem tutaj referencję na to, co zwróciło mi m_snake.tail
     * Dzięki temu, kiedy zmienię zawartość zmiennej tail, zmieni się również wartość zmiennej m_snake.tail. */
    Position2D& tail = m_snake.tail;

    m_snake.body.push(head);
    if (m_board[head.x][head.y] != Symbol::Apple)
    {
        m_board[tail.x][tail.y] = Symbol::Empty;
        m_snake.body.pop();
    }
    else
    {
        m_score++;
        generateApple();
    }

    tail = m_snake.body.front();
    m_board[head.x][head.y] = Symbol::Snake;
    m_board[tail.x][tail.y] = Symbol::Snake;

}
