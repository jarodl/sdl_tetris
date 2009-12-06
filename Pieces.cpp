#include "Pieces.h"

// public
Pieces::Pieces()
{
	srand(time(0));
}

Pieces::Pieces( string filename )
{
	// seed the random generator
	srand(time(0));
	read(filename);	
}

// grabs a random Piece
const Piece & Pieces::grab() const
{
	return( pieces.at(rand() % pieces.size()) );
}

void Pieces::read( string filename )
{
	ifstream fin( filename.c_str() );
	Piece curBlk;

	string rowscols;
	string squares;
	char piece;
	int rows, cols;

	while( !fin.eof() )
	{
		// get the rows and cols
		getline(fin, rowscols);
		istringstream ss(rowscols);
		ss >> rows >> cols;

		// create a new Piece
		curBlk.resize(rows, cols);

		// insert each square into the Piece
		getline(fin, squares);
		istringstream sqrs(squares);

		for (int i = 0; i < curBlk.rows(); i++) {
			for (int j = 0; j < curBlk.cols(); j++) {
				sqrs >> piece;
				if ( piece == AXIS )
					curBlk.setAxis(j);
				curBlk.insert(i, j, piece);
			}
		}
		
		// add the Piece to pieces vector
		pieces.push_back(curBlk);
	}
}