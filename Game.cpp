#include "Game.h"

// public
Game::Game()
{
	io = new IO();
	board = new Board( BOARD_ROWS, BOARD_COLS );
	pieces = new Pieces("blocks.txt");

	curPiece = pieces->grab();
	nextPiece = pieces->grab();
	resetBlockPos();
}

Game::~Game()
{
	delete io;
	io = NULL;
	delete board;
	board = NULL;
	delete pieces;
	pieces = NULL;
}

void Game::startGame()
{
	unsigned long startTime = SDL_GetTicks();
	Piece tmpPiece;
    bool playing = true;

	while (playing)
	{
		io->clearScreen();
		drawScene();
		io->updateScreen();

		int key = io->pollKey();

		switch (key)
		{
		case (SDLK_RIGHT):
			if ( board->isPossibleMove(cur_x + 1, cur_y, curPiece) )
				cur_x += 1;
			break;

		case (SDLK_LEFT):
			if ( board->isPossibleMove(cur_x - 1, cur_y, curPiece) )
				cur_x -= 1;
			break;

		case (SDLK_DOWN):
			while ( board->isPossibleMove(cur_x, cur_y + 1, curPiece) )
				cur_y += 1;
			break;

		case (SDLK_SPACE):
			tmpPiece = curPiece;
			tmpPiece.rotate();
			if ( board->isPossibleMove(cur_x, cur_y, tmpPiece) )
				curPiece.rotate();
			break;

               case (SDLK_ESCAPE):
                        playing = false;
                        break;
		}
		
		unsigned long endTime = SDL_GetTicks();

		if ( ( endTime - startTime ) > WAIT_TIME )
		{
			if ( board->isPossibleMove(cur_x, cur_y + 1, curPiece) )
				cur_y += 1;
			else
			{
				board->storePiece( cur_x, cur_y, curPiece );

				board->clearPossibleLines();

				if ( board->isGameOver() )
				{
					io->getKey();
					exit(0);
				}

				createNewPiece();
			}
			startTime = SDL_GetTicks();
		}
		
	}
}

// private
void Game::drawScene()
{
	drawPiece();
	drawNextPiece();
	drawBoard();
}

void Game::drawBoard()
{
	// draw borders
	io->drawRect( startXInPixels()-BORDER_W,
		startYInPixels(), BORDER_W, BOARD_H, BORDER_COLOR);
	io->drawRect( startXInPixels()+BOARD_W,
		startYInPixels(), BORDER_W, BOARD_H, BORDER_COLOR);

	// draw blocks stored in board
	for ( int i = 0; i < board->getWidth(); i++ )
		for ( int j = 0; j < board->getHeight(); j++ )
			if ( board->isFilled( i, j ) )
				io->drawRect( startXInPixels()+(BLOCK_W*i), 
				startYInPixels()+(BLOCK_H*j), BLOCK_W, BLOCK_H, BLOCK_COLOR );
}

void Game::drawPiece()
{
	for ( int i = 0; i < curPiece.cols(); i++ )
		for ( int j = 0; j < curPiece.rows(); j++ )
			if ( curPiece[i][j] != FREE )
				io->drawRect( startXInPixels()+(BLOCK_W*cur_x)+(i*BLOCK_W),
				startYInPixels()+(BLOCK_H*cur_y)+(j*BLOCK_H),
				BLOCK_W, BLOCK_H, PIECE_COLOR);
}

void Game::drawNextPiece()
{
	for ( int i = 0; i < nextPiece.cols(); i++ )
		for ( int j = 0; j < nextPiece.rows(); j++ )
			if ( nextPiece[i][j] != FREE )
				io->drawRect( startXInPixels()+BOARD_W+(BLOCK_W*i)+BORDER_W,
				startYInPixels()+(BOARD_H/3)+(BLOCK_H*j),
				BLOCK_W, BLOCK_H, PIECE_COLOR);
}

int Game::startXInPixels()
{
	return ((io->getScreenWidth()-BOARD_W)/2);
}

int Game::startYInPixels()
{
	return (io->getScreenHeight()-BOARD_H);
}

void Game::resetBlockPos()
{
	cur_x = ( board->getWidth()/2 ) - (curPiece.cols()/2);
	cur_y = 0;
}

void Game::createNewPiece()
{
	curPiece = nextPiece;
	nextPiece = pieces->grab();
	resetBlockPos();
}
