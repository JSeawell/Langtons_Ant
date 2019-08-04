/***************************************
 *
 * Name: Jake Seawell
 * Date: 09/21/18
 * Description: This is the header/class
 * specification file for a class called
 * Ant, which represents the Ant in 
 * Langton's Ant simulation.
 *
 * *************************************/

#ifndef ANT_HPP //include guards
#define ANT_HPP

//Ant Class Definition
class Ant
{
	private:
		int antRow; //starting row
		int antCol; //starting col
		int antOrient; //starting direction/orientation
	public:
		Ant(); //constructor
		int getAntRow(); //get row
		int getAntCol(); //get col
		int getAntOrient(); //get direction
		void placeAnt(int r, int c, int o); //place ant
		void rightTurnAnt(); //right turn
		void leftTurnAnt(); //left turn
		void edgeTurnAnt(); //full turn
		void moveAntForward(); //move forward
};
#endif //include guard
