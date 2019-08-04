/***************************************
 * This is the cpp file
 * ************************************/

#include "Ant.hpp"
#include "LangtonsAnt.hpp"
#include <iostream>

using std::cout;
using std::endl;

/**************************************
 *       LangtonsAnt::LangtonsAnt
 *
 * This is the default constructor,
 * which sets all of the array elements
 * to a white (blank) space.
 *
 * ***********************************/
LangtonsAnt::LangtonsAnt()
{
	cout << "Simulation Created" << endl; 	
}

/*************************************
 *      LangtonsAnt::runSim
 *
 * This function runs the Langton's
 * Ant simulation
 *
 * **********************************/
void LangtonsAnt::runSim(Ant ant1, int simBoardRow, int simBoardCol, int iterations)
{
	//Dynamic 2d Array Creation/Memory Allocation
	simBoard = new char*[simBoardRow];
	for (int i = 0; i < simBoardRow; i++)
		simBoard[i] = new char[simBoardCol];
	
	// Print board and starting ant
	cout << "Starting Board:" << endl;
	for (int i = 0; i < simBoardRow; i++)
	{
		for (int j = 0; j < simBoardCol; j++)
		{
			if ((ant1.getAntRow() == (i + 1)) && (ant1.getAntCol() == (j + 1)))
			{
				simBoard[i][j] = '*';// Place * on board where ant starts
			}
			else
			{
			simBoard[i][j] = ' '; // Set every element to " "
			}
			cout << simBoard[i][j];
				if (j == (simBoardCol - 1))
					cout << endl;	
		}
	}
	cout << endl;
	
	// Run simulation for n iterations
	for (int n = 0; n < iterations; n++)
	{
		cout << "Iteration #: " << (n + 1) << endl;
		// Edge cases
		if (((ant1.getAntRow() == 1) && (ant1.getAntOrient() == 0)) 
		|| ((ant1.getAntRow() == simBoardRow) && (ant1.getAntOrient() == 2)) 
		|| ((ant1.getAntCol() == 1) && (ant1.getAntOrient() == 3))
		|| ((ant1.getAntCol() == simBoardCol) && (ant1.getAntOrient() == 1)))
		{
			ant1.edgeTurnAnt();//Full turn
			if (simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] == ' ')
				simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] = '#';
			else if (simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] == '#')
				simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] = ' ';
		}
		// If space is white or starting ant
		else if ((simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] == ' ') 
			|| (simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] == '*'))  
		{
			ant1.rightTurnAnt();//Right turn
			simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] = '#';
		}
		// If space is black
		else if (simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] == '#')
		{
			ant1.leftTurnAnt();//Left turn
			simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] = ' ';
		}
		// Move ant forward one space (based on orientation)
		ant1.moveAntForward();// Delete this line if the ant needs to
					// not move during first iteration
	
		char temporary;// Temparary var to hold value of space
				// so that we can display ant on board
		
		// Store real value (white/black) in temp
		temporary = simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1]; 
		
		// Assign * to space to display ant on board
		simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] = '*';
		
		// Re-display new board (for each iteration)
		for (int i = 0; i < simBoardRow; i++)
		{
			for (int j = 0; j < simBoardCol; j++)
			{
				cout << simBoard[i][j];
				if (j == (simBoardCol - 1))
				{
					cout << endl;
				}
			}	
		}
	
		cout << endl;// Adds space between boards 
			     // (for each iteration)
		
		// Reassign true value (white/black) to space
		// (which is stored in temp)
		simBoard[ant1.getAntRow() - 1][ant1.getAntCol() - 1] = temporary;
		
		//ant1.moveAntForward(); Uncomment this if the ant 
		//needs to not move during first iteration
	}
	//Delete simBoardArray	
	for (int i = 0; i < simBoardRow; i++)
		delete [] simBoard[i];
	delete [] simBoard;	
}
