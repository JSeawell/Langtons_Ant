/*****************************************
 *  
 *   Name: Jake Seawell
 *   Date: 09/20/18
 *   Description:
 *   This is the main file for running the
 *   Langton's Ant simulation
 *        
 *   *****************************************/

#include "Ant.hpp"
#include "LangtonsAnt.hpp"
#include "choiceFunction.hpp"
#include "intVal.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

main()
{
	//Menu Function
	cout << endl;
    	int runOrNaw = choiceFunction("::Menu::", "Run Simulation", "Quit");
	cout << endl;

	//Menu "Run" Option:
	if (runOrNaw == 1)
    	{
        	int simBoardRow = 1;//variable initialization
		int simBoardCol = 1;
        	int startRow = 0;
        	int startCol = 0;
        	int startDir = 1;
		int numIter = 1;
            
	//Prompt user for game specs
        	
		//Board Rows and Columns
		cout << "Please enter the size of the simulation board"; 
		cout << "(row, then column)" << endl;
		cout << "Row:" << endl;
        	simBoardRow =  minMaxValidation(integerValidation(),4,100);//User enters row and column
		cout << endl;
		cout << "Column:" << endl;
		simBoardCol =  minMaxValidation(integerValidation(),4,100); 
		cout << endl;
		
		//Starting position (Ant)
    		int randOrNaw = choiceFunction("Ant Position", "Randomize", "Enter manually");
		
		while (randOrNaw == 0)
		{
			cout << "'Quit' is not a valid option here.";
			cout << "Please enter option '1' or '2':" << endl;
			randOrNaw = minMaxValidation(integerValidation(), 1,2);
		} 

		if (randOrNaw == 1)
		{
			startRow = minMaxRand(1,simBoardRow);
			cout << "Randow row selected:" << startRow << endl;
			startCol = minMaxRand(1,simBoardCol);
			cout << "Random column selected:" << startCol << endl;
			cout << endl; 	
		}
		else if (randOrNaw == 2)
		{
			cout << "Please enter the starting position of the ant";
			cout << "(row, then column)." << endl;
			cout << "Row:" << endl;
			startRow =  minMaxValidation(integerValidation(),1,simBoardRow);
			cout << endl;
			cout << "Column:" << endl;
        		startCol =  minMaxValidation(integerValidation(),1,simBoardCol);
       			cout << endl;
		}

		//Starting Direction/Orientation
		cout << "Please enter the starting direction of the ant:";
		cout << " 0 = up, 1 = right, 2 = down, 3 = left." << endl;
		startDir =  minMaxValidation(integerValidation(),0,3);
		cout << endl; 
	
		//Iterations
		cout << "Please enter the number of iterations to run." << endl;
        	numIter	=  minMaxValidation(integerValidation(),1,1500);
        	cout << endl;

		//Create Simulation Board
		LangtonsAnt antBoard1;
 		
		//Create Ant
		Ant ant1;
	
		// Place Ant on simulation board
		ant1.placeAnt(startRow,startCol,startDir);
	
		//Run simulation
		antBoard1.runSim(ant1, simBoardRow, simBoardCol, numIter);
	}
	
	//Menu Quit Option:
	else
	//Quit
	cout << "Program ended." << endl;
	return 0;
}
