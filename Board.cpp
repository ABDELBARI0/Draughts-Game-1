#include "Board.h"
#include <iostream>

Board::Board()
{
    currentPlayer = 'r';
    InitializeBoard();
}

void Board::InitializeBoard()
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            board[row][col] = '.';
        }
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if ((row + col) % 2 == 1)
            {
                board[row][col] = 'w';
            }
        }
    }

    for (int row = 5; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if ((row + col) % 2 == 1)
            {
                board[row][col] = 'r';
            }
        }
    }
}

void Board::DisplayBoard() const
{
    std::cout << "\n";

    std::cout << "    1 2 3 4 5 6 7 8\n";
    std::cout << "   -----------------\n";

    for (int row = 0; row < 8; row++)
    {
        std::cout << row + 1 << " | ";

        for (int col = 0; col < 8; col++)
        {
            std::cout << board[row][col] << ' ';
        }

        std::cout << '\n';
    }

    std::cout << "\nCurrent Player : " << currentPlayer << "\n";
}

char Board::GetCurrentPlayer() const
{
    return currentPlayer;
}

void Board::SwitchPlayer()
{
    if (currentPlayer == 'r')
        currentPlayer = 'w';
    else
        currentPlayer = 'r';
}

bool Board::IsInsideBoard(int row, int col) const
{
    return row >= 0 &&
        row < 8 &&
        col >= 0 &&
        col < 8;
}

bool Board::IsPlayerPiece(int row, int col) const
{
    if (!IsInsideBoard(row, col))
        return false;

    char piece = board[row][col];

    if (currentPlayer == 'r')
        return piece == 'r' || piece == 'R';

    return piece == 'w' || piece == 'W';
}

bool Board::MovePiece(int fromRow,
    int fromCol,
    int toRow,
    int toCol)
{
    if (!IsInsideBoard(fromRow, fromCol))
        return false;

    if (!IsInsideBoard(toRow, toCol))
        return false;

    if (!IsPlayerPiece(fromRow, fromCol))
        return false;

    if (board[toRow][toCol] != '.')
        return false;

    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = '.';

    PromoteKings();

    SwitchPlayer();

    return true;
}

void Board::PromoteKings()
{
    for (int col = 0; col < 8; col++)
    {
        if (board[0][col] == 'r')
            board[0][col] = 'R';

        if (board[7][col] == 'w')
            board[7][col] = 'W';
    }
}

bool Board::HasWinner() const
{
    int red = 0;
    int white = 0;

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (board[row][col] == 'r' || board[row][col] == 'R')
                red++;

            if (board[row][col] == 'w' || board[row][col] == 'W')
                white++;
        }
    }

    if (red == 0)
    {
        std::cout << "\nWhite Wins!\n";
        return true;
    }

    if (white == 0)
    {
        std::cout << "\nRed Wins!\n";
        return true;
    }

    return false;
}