//te makra ifndef, define i endif tworzą mi sie automatycznie kiedy tworzę nową klasę
//służą one do tego, żeby zapobiec wielokrotnemu zainclude'owaniu pliku
// wiecej info - google -> c++ header guards

#ifndef GAME_H
#define GAME_H

// includuje header klasy Board, żeby można było użyć w tej klasie
#include "board.h"


class Game
{  
//public - sprawia, że metody i zmienne są widoczne na zewnątrz klasy
public:
    // konstruktor, wywoływany zawsze PO utworzeniu instancji klasy
    Game();

    void run();

//private - zmienne i metody widoczne tylko w ciele klasy. w mainie nie można wywołać game.m_board;
private:
    Board m_board; // przedrostek m_ jest często stosowany, żeby podkreślić, że dana zmienna
    //jest memberem klasy, czyli prywatną zmienną


};

#endif // GAME_H
