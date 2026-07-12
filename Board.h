#pragma once

class Board
{
private:
    char board[8][8];
    char currentPlayer;

public:

    Board();

    void InitializeBoard();
    void DisplayBoard() const;

    char GetCurrentPlayer() const;
    void SwitchPlayer();

    bool IsInsideBoard(int row, int col) const;

    bool IsPlayerPiece(int row, int col) const;

    bool MovePiece(int fromRow,
        int fromCol,
        int toRow,
        int toCol);

    void PromoteKings();

    bool HasWinner() const;
};