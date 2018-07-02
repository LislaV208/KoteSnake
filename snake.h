#ifndef SNAKE_H
#define SNAKE_H

#include <queue>

using namespace std;

struct Position2D
{
    int x = 0;
    int y = 0;
};

/* W C++ struktury prawie nie różnią się od klas.
 * Jedyna różnica jest taka, że domyślnie w strukturze wszystko jest publiczne
 * A w klasie prywatne. Oczywiscie można używać dalej modyfikatorów public i private itp (ale w strukturze nie ma to sensu :P)
 * (Jeszcze jest różnica w dziedziczeniu, ale na to przyjdzie jeszcze czas)"
 */
struct Snake
{
    Snake()
    {
        body.push( {} ); // wsadzam domyślny obiekt Position2D, z wartościami (0,0)
        head = body.front();
        tail = body.back();
    }

    queue<Position2D> body;
    Position2D head;
    Position2D tail;
};

#endif // SNAKE_H
