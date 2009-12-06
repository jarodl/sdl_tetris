#include "Piece.h"
using namespace std;

// Constructor
Piece::Piece() : squares( DEF_ROWS ), axis(0)
{
	for ( int i = 0; i < DEF_ROWS; i++)
		squares[i].resize( DEF_COLS );
}

Piece::Piece( int rows, int cols ) : squares( rows )
{
	for ( int i = 0; i < rows; i++)
		squares[i].resize( cols );
}

// Copy constructor
void Piece::copy( const Piece & from, Piece & to )
{
	to.resize(from.rows(), from.cols());
	to.setAxis(from.getAxis());

	for ( int i = 0; i < to.rows(); i++)
		to[i] = from[i];
}

void Piece::resize( int rows, int cols )
{
	squares.resize(rows);
	for ( int i = 0; i < (int)squares.size(); i++)
		squares[i].resize(cols);
}

const vector< char > & Piece::operator[]( int row ) const
{
	return squares[ row ];
}

vector< char > & Piece::operator []( int row )
{
	return squares[ row ];
}

int Piece::rows() const
{
	return ( squares.size() );
}

int Piece::cols() const
{
	return ( squares[0].size() );
}

int Piece::getAxis() const
{
	return ( axis );
}

void Piece::setAxis( int col )
{
	axis = col;
}

const char Piece::getValue(int x, int y) const
{
	return( squares[x][y] );
}

void Piece::empty()
{
	for ( int i = 0; i < (int)squares.size(); i++ )
		for ( int j = 0; j < (int)squares[0].size(); j++ )
			squares[i][j] = SQR_EMPTY;
}

void Piece::fill(char fill)
{
	for ( int i = 0; i < (int)squares.size(); i++ )
		for ( int j = 0; j < (int)squares[0].size(); j++ )
			squares[i][j] = fill;
}

void Piece::rotate()
{
	std::vector< std::vector< char > > tmp(rows(), cols());
	
	for (int i = 0; i < rows(); ++i )
		for ( int j = 0; j < cols(); ++j )
			tmp[i][j] = squares[rows() - j - 1][i];

	squares.swap(tmp);
}

void Piece::insert(int x, int y, char bit)
{
	squares[x][y] = bit;
}
