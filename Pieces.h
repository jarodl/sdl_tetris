#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Piece.h"
using namespace std;

static const char AXIS = '2';

class Pieces
{
public:
	Pieces();
	Pieces( std::string filename );
	const Piece & grab() const;
	void read( std::string filename );

private:
	std::vector< Piece > pieces;
};

#endif