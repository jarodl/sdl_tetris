#ifndef PIECE_H
#define PIECE_H

#include <vector>

static const char SQR_EMPTY = '0';
static const char SQR_FULL = '1';
static const char SQR_AXIS = '2';
static const int DEF_ROWS = 5;
static const int DEF_COLS = 5;

class Piece
{
public:
	// Constructor
	Piece();
	Piece( int rows, int cols );

	// Copy items from one Piece to another
	void copy( const Piece & from, Piece & to );
	void resize( int rows, int cols );

	const std::vector< char > & operator[]( int row ) const;
	std::vector< char > & operator[]( int row );

	int rows() const;
	int cols() const;
	int getAxis() const;
	void setAxis( int col );

	const char getValue(int x, int y) const;

	void empty();
	void fill(char fill);
	
	void rotate();
	void insert(int x, int y, char bit);

private:
	std::vector< std::vector< char > > squares;
	int axis;
};

#endif