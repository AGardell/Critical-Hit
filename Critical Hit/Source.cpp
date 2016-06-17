//Taken from Challenge #271 on Reddit's Daily Programmer:
/*Critical hits work a bit differently in this RPG. If you roll the maximum value on a die, 
you get to roll the die again and add both dice rolls to get your final score. 
Critical hits can stack indefinitely -- a second max value means you get a third roll, and so on.
With enough luck, any number of points is possible.*/

#include <iostream>

double Calculate(double& d, double& h) {
	double prob = 1;
	double finalRoll;
	while (h >= d) {
		prob *= (1.0 / d);
		h -= d;
	}

	if (h == 1 || h == 0) {
		return prob;
	}
	else {
		finalRoll = (d - h) + 1;
		prob *= (finalRoll / d);
	}

	return prob;
	
	
}

int main() {

	double sides = 0.0;
	double health = 0.0;
	char again;

	do {
		std::cout << "How many side on your die? ";
		std::cin >> sides;

		std::cout << "\nHow much health does the enemy have? ";
		std::cin >> health;

		std::cout << "\nOutput: " << Calculate(sides, health) << std::endl;
		std::cout << "\nAgain? [Y][N]";
		std::cin >> again;
	} while (again != 'N');

	return 0;
}