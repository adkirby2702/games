//FILE NAME : maxpass.cpp//
// Alex Kirby//
//Program plays a game where a distance is given by the user and the user has to input and angle and a velocity to try and hit that distance.
//********************************************
#include <iostream>
#include <math.h> 
using namespace std;

//function declaration/prototype

//function that gets the distance from the user
double gettargetdistance();

//function that gets the angle from the user
double getlauncherangle();

// function that converts to radians
double degreestoradians(double);

// function that gets velocity from the user
double getmissilevelocity();

//function that calculates the new distance
double calcwinningrange(double,double,double);

//function that finds the difference in the two distances to see if it is close enough
double calcmissiledistance(double,double);

//prints summary of the data
void printsummary(double,int,double,double,double,double);


int main()
{
	//promt user to enter numbers
	cout <<"Enter a distance"<<endl;

	//declare variables
	double distance;
	double angle;
	double radian;
	double velocity;
	double range;
	double newdistance;
	int tries=1;
	double thesin;
	//call distance function to get distance
	distance = gettargetdistance();

	//call launcher function to get angle from the user
	angle = getlauncherangle(); 

	//call radian function to convert he degrees to radians
	radian = degreestoradians(angle);

	//call velocity function to get velocity from the user
	velocity = getmissilevelocity();

	//call function to calculate the  missile distance
	range = calcwinningrange(velocity,radian,thesin);

	//call function to see how far the missile was from the actual distance
        newdistance = calcmissiledistance(range,distance);

	//if the missile misses. The new distance has to be less than than 1% higher than the distance and greater than one percent less. 
	while (range  > distance + distance *1 ||  range < distance * .99 )
	{
		//repeat if it is a miss
		printsummary(distance,tries,angle,velocity,range,newdistance);
                tries = tries + 1;
                if (tries == 6)//if the user tries 5 times they lose
                {
                        cout <<" You lose" <<endl;
                        return EXIT_FAILURE;
                }

	        angle = getlauncherangle();
        	radian = degreestoradians(angle);
        	velocity = getmissilevelocity();
        	range = calcwinningrange(velocity, radian,thesin);
        	newdistance = calcmissiledistance(range,distance);
	}

	//if it is in the right range, player wins
	if (range <= distance + distance*.01 || range >= distance*.99 )
	{
		printsummary(distance,tries,angle,velocity,range,newdistance); 
		cout <<"You win!"<<endl;
	}
	return 0;
}


double gettargetdistance()
{	//get distance from user
	double distance;
	cin >> distance;
	while(cin.fail())//validate 
	{
		cin.clear();
		cin.ignore(100,'\n');
		//user tries again until the input is valid
		cout << "bad input try again" <<endl;
		cin >> distance;
	}
	//return distance to main
	return distance;
}


double getlauncherangle()
{
	// get the launcher angle from the user
	double angle;
	cout << "Enter the angle for the launcher" <<endl;
	cin >> angle;
	while(cin.fail())//validate 
	{
		cin.clear();
		cin.ignore(100,'\n');
		//user tries again until the input is valid
		cout << "bad input try again" <<endl;
		cin >> angle;
	}
	// return the angle to main
	return angle; 
}


double degreestoradians(double angle)
{
	// Convert the angle into radians
	double radians = (angle * 3.14159265) / 180.0;
	return radians;
}


double getmissilevelocity()
{
	//get velocity from user
	double velocity;
	cout << "Enter the velocity" <<endl;
	cin >> velocity;
	while(cin.fail())//validate 
	{
		cin.clear();
		cin.ignore(100,'\n');
		//user tries again until the input is valid
		cout << "bad input try again" <<endl;
		cin >> velocity;
	}
	//return velocity to main
	return velocity;
}


double calcwinningrange(double velocity ,double radian,double thesin)
{
	//calculates the new distance the user inputted
	double newdist =(velocity * velocity *  sin(2*radian)) / 32.2; 
	//return newdistance to main
	return newdist;
}


double calcmissiledistance(double newdist, double distance)
{
	//calculate how close the user's missile came
	double newnew = newdist - distance;
	//make sure the number is positive.
	if (newnew <0)
	{
		newnew = newnew * -1;
	}
	cout << newnew <<endl;
	//return that distance to main
	return newnew;
}
void printsummary(double distance, int tries, double angle, double velocity,double range, double newdistance )
{
	cout <<"****************************************************" <<endl;
	cout <<"Distance: "<< distance <<endl; // output distance
	cout << "Attempt: " << tries << endl; // output attempt number
	cout <<"Angle: " << angle << endl;// angle input by the user
	cout <<"Velocity: " << velocity << endl;// velocity entered by the user
	cout <<"New distance: "<< range <<endl;// new distance calculated
	cout <<"Distance from target: " << newdistance <<endl;// Distance from the target
	cout <<"****************************************************" <<endl; 
}
