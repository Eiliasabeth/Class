#include <iostream>
#include "Investment Calculator.h"
#include <string>

using namespace std;


int main() {
	char userChoice;
	bool runProg = true;
	double m_initBal = 0.00;
	double m_interestRate = 0.00;
	double m_monthlyDeposit = 0.00;
	double yearlyInterest = 0.00;
	double endBal = 0.00;
	int m_numYears = 0;
	int currYear = 0;

	InvestmentCalculator userInvestment;

	//A while loop to continue the program as many times as the user wants
	while (runProg == true) {
		//Outputs the display to the user
		userInvestment.InitialDisplay(m_initBal, m_interestRate, m_numYears, m_monthlyDeposit);

		//Gets the user provided values saved into the program's variables
		m_initBal = userInvestment.GetInitBal();
		m_interestRate = userInvestment.GetInterestRate();
		m_numYears = userInvestment.GetNumYears();
		m_monthlyDeposit = userInvestment.GetMonthlyDeposit();
		
		//Calls to compute the given values with and without monthly deposits
		userInvestment.CalcBalWithoutDeposit(m_initBal, m_interestRate, m_numYears);
		userInvestment.CalcBalWithDeposit(m_initBal, m_interestRate, m_numYears, m_monthlyDeposit);

		//Promts user for input to either continue or end the program
		cout << endl << "If you want to exit enter 1. To enter new values, enter any other key." << endl;
		cin >> userChoice;

		if (userChoice == '1') {			//If user input is 1 then this exicutes
			runProg = false;				//Changes the boolean to false to end the while loop
		}
	}

	return 0;
}
