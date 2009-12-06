#include "Board.h"

// public
Board::Board()
{
	Board::rows = DEF_ROWS;
	Board::cols = DEF_COLS;
	initBoard();
}

Board::Board( int r, int c )
{
	Board::rows = r;
	Board::cols = c;
	initBoard();
}

bool Board::isPossibleMove( int x, int y, Piece piece )
{
	for ( int i = 0; i < piece.cols(); i++ ) {
		for ( int j = 0; j < piece.rows(); j++ ) {
			if ( piece[i][j] != FREE ) {
				if ( i + x < 0 || i + x > cols - 1 )
					return false;
				if ( j + y < 0 || j + y > rows - 1 )
					return false;
				if ( board[i+x][j+y] != FREE )
					return false;
			}
		}
	}

	return true;
}
bool Board::isGameOver()
{
	for ( int i = 0; i < cols; i++ )
		if ( board[i][1] != FREE )
			return true;
	return false;
}

bool Board::isFilled( int x, int y )
{
	return ( board[x][y] != FREE );
}

void Board::storePiece( int x, int y, Piece piece )
{
	for ( int i = 0; i < piece.cols(); i++ )
		for ( int j = 0; j < piece.rows(); j++ )
			if ( piece[i][j] != FREE )
				board[x+i][y+j] = FULL;
}

void Board::clearPossibleLines()
{
	for ( int i = 0; i < rows; i++ )
		if ( lineIsFull( i ) )
			deleteLine( i );
}

int Board::getWidth()
{
	return cols;
}

int Board::getHeight()
{
	return rows;
}

const vector< char > & Board::operator[]( int col ) const
{
	return board[ col ];
}

vector< char > & Board::operator []( int col )
{
	return board[ col ];
}

// private

void Board::initBoard()
{
	board.resize(cols);
	for ( int i = 0; i < cols; i++ ) {
		board[i].resize(rows);
		for ( int j = 0; j < rows; j++ ) {
			board[i][j] = FREE;
		}
	}
}

void Board::deleteLine( int y )
{
	for (int i = 0; i < cols; i++ )
		for ( int j = y; j > 0; j-- )
			board[i][j] = board[i][j - 1];
}

bool Board::lineIsFull( int y )
{
	for ( int i = 0; i < cols; i++ )
		if ( board[i][y] == FREE )
			return false;
	return true;
}