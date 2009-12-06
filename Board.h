#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H

#include "Pieces.h"

#define DEF_ROWS 30
#define DEF_COLS 10

static const char FREE = '0';
static const char FULL = '1';

class Board
{
public:
	Board();
	Board( int r, int c );

	bool isPossibleMove( int x, int y, Piece piece );
	bool isGameOver();
	bool isFilled( int x, int y );
	void storePiece( int x, int y, Piece piece );
	void clearPossibleLines();
	int getWidth();
	int getHeight();

	const std::vector< char > & operator[]( int col ) const;
	std::vector< char > & operator[]( int col );

private:
	int rows, cols;
	std::vector< std::vector< char > > board;

	void initBoard();
	void deleteLine( int y );
	bool lineIsFull( int y );
};

#endif
