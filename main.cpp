#include <iostream>
#include "Board.h"

int main()
{
    Board game;

    while (!game.HasWinner())
    {
        game.DisplayBoard();

        int fromRow;
        int fromCol;
        int toRow;
        int toCol;

        std::cout << "\nSelect Piece\n";

        std::cout << "Row : ";
        std::cin >> fromRow;

        std::cout << "Column : ";
        std::cin >> fromCol;

        std::cout << "\nMove To\n";

        std::cout << "Row : ";
        std::cin >> toRow;

        std::cout << "Column : ";
        std::cin >> toCol;

        fromRow--;
        fromCol--;
        toRow--;
        toCol--;

        if (!game.MovePiece(fromRow, fromCol, toRow, toCol))
        {
            std::cout << "\nInvalid Move!\n";
        }
    }

    return 0;
}