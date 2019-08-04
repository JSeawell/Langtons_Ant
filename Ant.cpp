/***************************************
 * 
 * Name: Jake Seawell
 * Date: 09/21/18
 * Description: This is the class
 * implementation file for a class
 * called Ant, which represents the
 * ant in Langton's Ant simulation.
 *
 * ***********************************/

#include "Ant.hpp"

/*************************************
 *              Ant::Ant
 *
 * This is the default constructor,
 * which sets the Ant's position to
 * (row,col) = (1,1), and the 
 * orientation to right (1).
 *
 * **********************************/
Ant::Ant()
{
	placeAnt(1,1,1);
}

/***********************************
 *          Ant::getAntRow
 *
 * This function gets the Ant's row
 *
 * ********************************/
int Ant::getAntRow()
{
	return antRow;
}

/**********************************
 *        Ant::getAntCol
 *
 *********************************/
int Ant::getAntCol()
{
	return antCol;
}

/**********************************
 *       Ant::getAntOrient
 *
 * This function gets the Ant's
 * orientation/direction.
 *
 * *******************************/
int Ant::getAntOrient()
{
	return antOrient;
}

/***********************************
 *           Ant::placeAnt
 *
 * This function places the ant
 * into a certain location on the
 * sim board.
 *
 * ********************************/
void Ant::placeAnt(int r, int c, int o)
{
	antRow = r;
	antCol = c;
	antOrient = o;
}

/***********************************
 *        Ant::rightTurnAnt
 *
 * This function causes the ant
 * to make a right (90 deg) turn.
 *
 * ********************************/
void Ant::rightTurnAnt()
{
	antOrient = ((antOrient + 1) % 4);
}

/**********************************
 *      Ant::leftTurnAnt
 *
 * This function causes the ant
 * to make a left turn.
 *
 * *******************************/
void Ant::leftTurnAnt()
{
	antOrient = ((antOrient + 3) % 4);
}

/*********************************
 *     Ant::edgeTurnAnt
 *
 * This function causes the ant
 * to make a full 180 deg turn,
 * which it will do when it hits
 * one of the edges of the 
 * simulation board.
 *
 * ******************************/
void Ant::edgeTurnAnt()
{
	antOrient = ((antOrient + 2) % 4);
}

/********************************
 *    Ant::moveAntForward
 *
 * This function moves the ant
 * forward one space (depending
 * on the orientation).
 *
 * ****************************/
void Ant::moveAntForward()
{
	if (antOrient == 1)
		antCol = antCol + 1;
	if (antOrient == 2)
		antRow = antRow + 1;
	if (antOrient == 3)
		antCol = antCol - 1;
	if (antOrient == 0)
		antRow = antRow - 1;
}
