#include <stdio.h>
#include "SimulationCore_3Body.h"
#include "Vector2.h"
#include <string>
#include "MathHelper.h"
using namespace std;

int main(int argc, char* argv[])
{
	double timeStep = 0.00015;

	Vector2<double> pos(2, -3.41);
	Vector2<double> vel(1.18, -3);

	SimulationCore_3Body simulation(timeStep);
	simulation.mainLoop(pos, vel);

	printf("Press ENTER/RETURN key to end...");
	while (getchar() != '\n')


	return 0;
}


//#include<stdlib.h>
//#include<stdio.h>
//#include <math.h>
//
///* This is option is used to set the mode. if an illegal value is input, the program
//will default to normal mode. 1=fast,2=normal,3=fine */
//#define Mode 2
//
///* This is option can be used to enable/disable the debug option. When enabled, the program
//ouputs the energy of the test mass at each step to a file called debug.out */
//#define Debug 1
//
///****EXTERNAL FUNCTION PROTOTYPES***/
//
///*Prototype of the energy calculating function*/
//double Energy(double Pos_Mass, double Neg_Mass, double *x, double *y, int n, double X_Velocity, double Y_Velocity);
//
///*Prototype of the position calculating function*/
//void Position(double *x, double *y, double Pos_Mass, double Neg_Mass, int n, double X_Velocity,
//	double Y_Velocity, double *X_Acceleration, double *Y_Acceleration, double dt);
//
///*Prototype of the velocity calculating function*/
//void Velocity(double *x, double *y, double Pos_Mass, double Neg_Mass, int n,
//	double *X_Velocity, double *Y_Velocity, double *X_Acceleration, double *Y_Acceleration, double dt);
//
//int main(int argc, char* argv[])
//{
//	printf("\n");
//
//	/***********************************
//	*** Variable Declaration Section ***
//	***********************************/
//
//	/*The value of the time step and number of steps (+1, for the inital value) to take */
//	double dt;
//	int N;
//
//	/* These variables are the masses of M- and M+ and the intial positions of the test mass,
//	as well as the initial distances to M+ and M-*/
//	double Neg_Mass, Pos_Mass, X_Initial, Y_Initial, Initial_Dist_To_MPos, Initial_Dist_To_MNeg;
//
//	/*The test masses position  and  velocities and  in x and y,its total energy at
//	time t and its initial energy, and the runtime of the simulation. Initialy we dont know how
//	many position values there will be as the time step and number of steps may be redefined*/
//	double *x = NULL;
//	double *y = NULL;
//	double X_Velocity, Y_Velocity, Total_Energy, Initial_Energy, time;
//
//	/* The components of the test Mass's acceleration and its total Energy. The [0] element
//	of each represents its value at time t, the [1] element is its value at time t+dt*/
//	double X_Acceleration[2], Y_Acceleration[2];
//
//	/* Miscellaneous  variables, n is used in the for loop and validation for validating
//	the inputs and outputs of the program */
//	int n, validation = 0;
//
//	/* File variables, output is the file to which the trajectory and time is written to.
//	debug contains the energy of the test mass at each step */
//	FILE* output;
//	fopen_s(&output, "1016325_proj1.out", "w");
//	FILE* debug;
//	fopen_s(&debug, "1016325_proj1_Energy.out", "w");
//
//
//	/****************************
//	******VALIDATION SECTION*****
//	****************************/
//	/* This if statement checks that the right amount of inputs have been provided */
//	if (argc != 7)
//	{
//		printf("************************ ERROR! ***********************\n");
//		printf("**     Wrong amount of comand line inputs.           **\n");
//		printf("**     Please run again with the correct amount (6). **\n");
//		printf("*******************************************************\n");
//		//validation = 1;
//	}
//
//	/* The following checks only occur if the number of inputs is correct as otherwise
//	the user will be presented with a segmentation fault which could lead to confusion. */
//	else
//	{
//		/* This if staterment scans in the users input values and checks to make sure that
//		the user has not accidently input letters or special characters. */
//		if ((sscanf_s(argv[1], "%lf", &Neg_Mass) != 1) || (sscanf_s(argv[2], "%lf", &Pos_Mass) != 1)
//			|| (sscanf_s(argv[3], "%lf", &X_Initial) != 1) || (sscanf_s(argv[4], "%lf", &Y_Initial) != 1) ||
//			(sscanf_s(argv[5], "%lf", &X_Velocity) != 1) || (sscanf_s(argv[6], "%lf", &Y_Velocity) != 1))
//		{
//			printf("************************* ERROR! ************************\n");
//			printf("** Input values must be numbers. Please run again with **\n");
//			printf("** with six numerical inputs.                          **\n");
//			printf("*********************************************************\n");
//			//validation = 1;
//		}
//
//		/* This if statement checks to make sure that the user has not input masses as a negative  */
//		if (Neg_Mass<0 || Pos_Mass<0)
//		{
//			printf("*********************** ERROR! **********************\n");
//			printf("**  Cannot have negative mass values for M+ or M-  **\n");
//			printf("*****************************************************\n");
//			//validation = 1;
//		}
//	}
//
//	/* This if statement checks to  that the output files have been successfully  created */
//	if (output == (FILE*)NULL)
//	{
//		printf("**************************ERROR*********************\n");
//		printf("** Cannot create output file 1016325_proj1.out!   **\n");
//		printf("** Make sure that you have to correct permissions **\n");
//		printf("** to write to this directory                     **\n");
//		printf("****************************************************\n");
//		validation = 1;
//	}
//	if (debug == (FILE*)NULL)
//	{
//		printf("**************************ERROR*********************\n");
//		printf("** Cannot create output file debug.out!           **\n");
//		printf("** Make sure that you have to correct permissions **\n");
//		printf("** to write to this directory                     **\n");
//		printf("****************************************************\n");
//		validation = 1;
//	}
//
//
//	/******************************
//	**********MAIN PROGRAM*********
//	******************************/
//
//	if (validation == 0)
//	{
//
//		Neg_Mass = 10;
//		Pos_Mass = 10;
//		X_Initial = 5;
//		Y_Initial = -3.41;
//		X_Velocity = 0.18;
//		Y_Velocity = 2;
//
//		/* The program first checks the mode selected in the preprocessor statements and sets the associated time step.
//		It also prints the mode selected to inform the user of the mode being used. */
//		if (Mode == 1) dt = 0.0015, N = 20001, printf("Mode=Fast (dt=%lg Seconds)\n\n", dt);
//
//		if (Mode == 2) dt = 0.00015, N = 200001, printf("Mode=Normal (dt=%lg Seconds)\n\n", dt);
//
//		if (Mode == 3) dt = 0.000015, N = 2000001, printf("Mode=Fine (dt=%lg Seconds)\n\n", dt);
//
//		/* If an illegal value for Mode has been set, the program will deafault to Mode 2 */
//		if (Mode != 1 && Mode != 2 && Mode != 3) dt = 0.00015, N = 200001, printf("Mode=Normal (dt=%lg Seconds)\n\n", dt);
//
//
//		/* Now that dt and N have been set , we can build the arrays needed to store the x and y values */
//		x = (double*)malloc(N*sizeof(double));
//		y = (double*)malloc(N*sizeof(double));
//
//		/*Input the initial positions to the arrays */
//		x[0] = X_Initial;
//		y[0] = Y_Initial;
//
//		
//
//
//		/*** This for loop is the main body of the simulation ***/
//		for (n = 0; n <= N; n++)
//		{
//			/*We first check the runtime and exit if it is greater than 30s */
//			time = (n)*dt;
//			if (time>30)
//			{
//				/*set to 30 for run time print out */
//				time = 30;
//				break;
//			}
//
//			/* Now call on the external Energy function to calculate the Total energy at step n */
//			Total_Energy = Energy(Pos_Mass, Neg_Mass, x, y, n, X_Velocity, Y_Velocity);
//			if (n == 0) Initial_Energy = Total_Energy;
//
//			/* Debug option, if enabled it prints the energy at each step to a debug file */
//			if (Debug == 1) fprintf(debug, "%lf %lf\n", time, Total_Energy);
//
//
//			/***** We then calculate the Position at time t+dt using the Velocity-Verlet scheme by calling
//			on the external position function *****/
//			Position(x, y, Pos_Mass, Neg_Mass, n, X_Velocity, Y_Velocity, X_Acceleration, Y_Acceleration, dt);
//
//			/***** We then calculate the Velocity at time t+dt using the Velocity-Verlet scheme by calling
//			on the external velocity function *****/
//			Velocity(x, y, Pos_Mass, Neg_Mass, n, &X_Velocity, &Y_Velocity, X_Acceleration, Y_Acceleration, dt);
//
//
//			/**** These if statements detect if a collision  has occurred. if the energy has deviated by
//			a significant amount from the initial value, then this indicates a collision  has either occurred
//			or is imminent  ****/
//
//			/* This if statement checks for a collision  at M+ */
//			if (fabs(Total_Energy - Initial_Energy)>0.5 && x[n]>0)
//			{
//				printf("Test mass has collided with M+.\n\n");
//				break;
//			}
//			/* This statement checks for a collision  at M- */
//			if (fabs(Total_Energy - Initial_Energy)>0.5 && x[n]<0)
//			{
//				printf("Test mass has collided with M-. \n\n");
//				break;
//			}
//
//			/*The results for the position for this iteration are then printed to the ouput file */
//			fprintf(output, "%lf %lf %lf \n", time, x[n], y[n]);
//		}
//	}
//	/* These if statements check to make sure that the output files have been successfully written to */
//	if (output == (FILE*)NULL)
//	{
//		printf("**************************ERROR******************************\n");
//		printf("** Cannot create output file 1016325_proj1.out!            **\n");
//		printf("** Make sure there is sufficient free disk space available.**\n");
//		printf("*************************************************************\n");
//		validation = 1;
//	}
//	if (debug == (FILE*)NULL)
//	{
//		printf("**************************ERROR******************************\n");
//		printf("** Cannot create output file debug.out!                    **\n");
//		printf("** Make sure there is sufficient free disk space available.**\n");
//		printf("*************************************************************\n");
//		validation = 1;
//	}
//	/* The output files are then closed */
//	fclose(output);
//	fclose(debug);
//
//	/* The memory allocated to x and y earlier is now freed */
////	free(x);
////	free(y);
//
//	/* This if statement is the exit point for validation failure */
//	if (validation == 1)
//	{
//		printf("\n");
//		printf("EXITING...\n\n");
//		return(EXIT_FAILURE);
//	}
//	/**** This is the exit point of the program ****/
//	else
//	{
//		printf("Simulation Complete. Run time=%lg Seconds\n\n", time);
//		return(EXIT_SUCCESS);
//	}
//}
//
//
///******************************************************
//**********EXTERNAL ENERGY CALCULATING FUNCTION*********
//*******************************************************/
//
///* The function takes 4 inputs, the masses of the fixed masses, the x and y
//positions of the test mass , the masses velocity and the current step n. */
//double Energy(double Pos_Mass, double Neg_Mass, double *x, double *y, int n, double X_Velocity, double Y_Velocity)
//{
//	/* The Potential, Kinetic and total energy of the test mass at step n. As well as the
//	X and Y components of its velocity and the distance from it to the two masses. */
//	double PE, KE, E_Total, Dist_To_Pos_Mass, Dist_To_Neg_Mass, Velocity;
//
//	/* We Use Pythagoras to get the distances to the masses and the total velocity */
//	Dist_To_Pos_Mass = sqrt(pow((x[n] - 1), 2) + pow(y[n], 2));
//	Dist_To_Neg_Mass = sqrt(pow((x[n] + 1), 2) + pow(y[n], 2));
//	Velocity = sqrt(pow(X_Velocity, 2) + pow(Y_Velocity, 2));
//
//	/* The energy is then calculated  using the eqns for kinetic and gravitational energy */
//	KE = 0.5*Velocity*Velocity;
//	PE = -(Neg_Mass / Dist_To_Neg_Mass) - (Pos_Mass / (Dist_To_Pos_Mass));
//	E_Total = KE + PE;
//
//	return(E_Total);
//}
//
///********************************************************
//**********EXTERNAL POSITION CALCULATING FUNCTION*********
//*********************************************************/
//
///*This function takes 8 inputs, pointers to the x and y variables, the mass's, the step n, and
//the compoents of the test mass's velocity as well as the time step. It does not return a function,
//instead, by passing pointers to x and y, the values of x[n+1] and y[n+1] are calclated directly here */
//
//void Position(double *x, double *y, double Pos_Mass, double Neg_Mass, int n, double X_Velocity,
//	double Y_Velocity, double *X_Acceleration, double *Y_Acceleration, double dt)
//{
//	/* These variables are variables used to simplify the calculation of the accelerations.
//	The first two variables are self explanatory, the second two replace the denominators
//	for M- and M+ in the eqn of motion for the test mass.*/
//	double X_Dist_To_Neg_Mass, X_Dist_To_Pos_Mass, Neg_Mass_Denom, Pos_Mass_Denom;
//
//	/*Firstly the X distances to the two masses are calculated */
//	X_Dist_To_Neg_Mass = x[n] + 1;
//	X_Dist_To_Pos_Mass = x[n] - 1;
//
//	/* These values are equal to 1/(R^3) with R equal to sqrt(x^2+y^2) */
//	Neg_Mass_Denom = pow((X_Dist_To_Neg_Mass*X_Dist_To_Neg_Mass + (y[n] * y[n])), -1.5);
//	Pos_Mass_Denom = pow((X_Dist_To_Pos_Mass*X_Dist_To_Pos_Mass + (y[n] * y[n])), -1.5);
//
//	/*The X and Y acceleration of the test mass is then calculated using the eqn of motion */
//	X_Acceleration[0] = -((Pos_Mass*X_Dist_To_Pos_Mass*Pos_Mass_Denom) + (Neg_Mass*X_Dist_To_Neg_Mass*Neg_Mass_Denom));
//	Y_Acceleration[0] = -((Pos_Mass*y[n] * Pos_Mass_Denom) + (Neg_Mass*y[n] * Neg_Mass_Denom));
//
//	/***** We then calculate the Position at  time t+dt using the Velocity-Verlet scheme *****/
//	x[n + 1] = x[n] + (X_Velocity*dt) + (0.5*X_Acceleration[0] * dt*dt);
//	y[n + 1] = y[n] + (Y_Velocity*dt) + (0.5*Y_Acceleration[0] * dt*dt);
//
//}
//
///********************************************************
//**********EXTERNAL VELOCITY CALCULATING FUNCTION*********
//*********************************************************/
//
///*This function takes 1o inputs, pointers to the x and y variables, the mass's, the step n,
//pointers to the components of the test mass's velocity and pointers to the components of its
//acceleration as well as the timestep. */
//
//void Velocity(double *x, double *y, double Pos_Mass, double Neg_Mass, int n, double *X_Velocity,
//	double *Y_Velocity, double *X_Acceleration, double *Y_Acceleration, double dt)
//{
//	/**** The Variables are calculated at a time t+dt *****/
//	double X_Dist_To_Neg_Mass = x[n + 1] + 1;
//	double X_Dist_To_Pos_Mass = x[n + 1] - 1;
//	double Neg_Mass_Denom = pow((X_Dist_To_Neg_Mass*X_Dist_To_Neg_Mass + (y[n + 1] * y[n + 1])), -1.5);
//	double Pos_Mass_Denom = pow((X_Dist_To_Pos_Mass*X_Dist_To_Pos_Mass + (y[n + 1] * y[n + 1])), -1.5);
//
//	/* The acceleration at time t+dt is calculated */
//	X_Acceleration[1] = -((Pos_Mass*X_Dist_To_Pos_Mass*Pos_Mass_Denom) + (Neg_Mass*X_Dist_To_Neg_Mass*Neg_Mass_Denom));
//	Y_Acceleration[1] = -((Pos_Mass*y[n + 1] * Pos_Mass_Denom) + (Neg_Mass*y[n + 1] * Neg_Mass_Denom));
//
//	//SAVE THIS AND USE IN POS FUNCT? THIS WAY DONT HAVE TO RECALC. WOULD NEED TO HANDLE INITIAL THOUGH
//	//IE, JUST ONE ACCLERATION X,Y VAR 
//
//
//	/***** We then calculate the Velocity at  time t+dt using the Velocity-Verlet scheme *****/
//	*X_Velocity += (0.5*dt*(X_Acceleration[0] + X_Acceleration[1]));
//	*Y_Velocity += (0.5*dt*(Y_Acceleration[0] + Y_Acceleration[1]));
//}
