/********************************************
 * 
 * Name: Jake Seawell
 * Date: 09/21/18
 * Description: This is the header/class
 * specification file for a class called
 * LangtonsAnt, which represents a board
 * for running Langton's Ant simulation.
 *
 * *****************************************/

#ifndef LANGTONSANT_HPP //include guards
#define LANGTONSANT_HPP

#include "Ant.hpp"

//LangtonAnt Class Declaration
class LangtonsAnt
{
	private:
        	int simBoardRow;//Row size variable
		int simBoardCol;//Col size variable
        	char** simBoard;//Pointer to pointer of characters
    	public:
        	//Constructor:
		LangtonsAnt();
		
		//Run Simulation Function:
		void runSim(Ant ant1, int simBoardRow, int simBoardCol, int iterations);
};

#endif //include guard

