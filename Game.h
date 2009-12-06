#ifndef GAME_H
#define GAME_H

#include "IO.h"
#include "Board.h"
#include "Piece.h"
#include "Pieces.h"

#define BOARD_ROWS 30 // in array
#define BOARD_COLS 10

#define PADDING 1 // in pixels
#define BLOCK_H 15
#define BLOCK_W 15
#define BOARD_W (BLOCK_W*BOARD_COLS)
#define BOARD_H (BLOCK_H*BOARD_ROWS)
#define BORDER_W 10

#define BORDER_COLOR 0xffffffff
#define BLOCK_COLOR 0xffffffff
#define PIECE_COLOR 0xffffffff

#define WAIT_TIME 200 // in milliseconds

class Game
{
public:
	Game();
	~Game();
	void startGame();

private:
	IO *io;
	Board *board;
	Pieces *pieces;
	Piece curPiece;
	Piece nextPiece;
	int cur_x, cur_y;

	void drawScene();
	void drawBoard();
	void drawPiece();
	void drawNextPiece();
	int startXInPixels();
	int startYInPixels();
	void resetBlockPos();
	void createNewPiece();
};

#endif
