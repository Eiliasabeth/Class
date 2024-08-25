#include <iostream>
#include <iomanip>
using namespace std;

#include "Investment Calculator.h"

InvestmentCalculator::InvestmentCalculator() : userInvestment("userInvestment"), m_initBal(0.00), m_interestRate(0.00), m_numYears(0), m_monthlyDeposit(0.00) {
}

//Sets initial balance
void InvestmentCalculator::SetInitBal(double m_initBal) {
	this->m_initBal = m_initBal;
}

//Gets initial for use when called
double InvestmentCalculator::GetInitBal() const{
	return m_initBal;
}

//Sets monthly deposit
void InvestmentCalculator::SetMonthlyDeposit(double m_monthlyDeposit) {
	this->m_monthlyDeposit = m_monthlyDeposit;
}

//Gets monthly deposit when called
double InvestmentCalculator::GetMonthlyDeposit() const{
	return m_monthlyDeposit;
}

//Sets interest rate
void InvestmentCalculator::SetInterestRate(double m_interestRate) {
	this->m_interestRate = m_interestRate;
}

//Gets interes rate when called
double InvestmentCalculator::GetInterestRate() const {
	return m_interestRate;
}

//Sets number of years
void InvestmentCalculator::SetNumYears(int m_numYears) {
	this->m_numYears = m_numYears;
}

//Gets number of years when called
int InvestmentCalculator::GetNumYears() const {
	return m_numYears;
}

//Outputs a line of n length of a chosen character symbol
string InvestmentCalculator::FormatLine(int t_width, char t_char) {
	string charString;
	int i;

	if (t_width >= 0) {
		for (i = 0; i < t_width; ++i) {
			charString += t_char;
		}
	}
	return charString;
}

//Outputs the inital display and prompts for user input
void InvestmentCalculator::InitialDisplay(double m_initBal, double m_interestRate, int m_numYears, double m_monthlyDeposit) {
	double initialAmt = 0.00;
	double monthlyDeposit = 0.00;
	int yearlyInterest = 0;
	int numYears = 0;

	//Creates a display for the user
	cout << FormatLine(32, '*') << endl;
	cout << FormatLine(10, '*') << " Data Input " << FormatLine(10, '*') << endl;
	
	//Promts the user for the initial amount to be invested and takes the input
	cout << "Initial Investment Amount:" << endl;
	cin >> initialAmt;

	//Checks for valid input and prompts for a new input if needed
	if (initialAmt < 0) {
		while (initialAmt < 0) {
			cout << "Invalid input. Please enter a non-negative input.";
			cin >> initialAmt;
		}
	}
	SetInitBal(initialAmt);						//Sets the user input to initialAmt

	//Prompts the user for the monthly deposit to be made and takes the input
	cout << "Monthly Deposit:" << endl;
	cin >> monthlyDeposit;

	//Checks for valid input and prompts for new input if needed
	if (monthlyDeposit < 0) {
		while (monthlyDeposit < 0) {
			cout << "Invaild input. Please enter a non-negative input.";
			cin >> monthlyDeposit;
		}
	}
	SetMonthlyDeposit(monthlyDeposit);			//Sets the user input to monthlyDeposit

	//Prompts user for annual interest and takes the input
	cout << "Annual Interest:" << endl;
	cin >> yearlyInterest;

	//Checks for valid input and prompts for new input if needed
	if (yearlyInterest < 0) {
		while (yearlyInterest < 0) {
			cout << "Invaild input. Please enter a non-negative input.";
			cin >> yearlyInterest;
		}
	}
	SetInterestRate(yearlyInterest);			//Sets the user input to yearlyInterest

	//Prompts the user for the number of years and takes input
	cout << "Number of Years:" << endl;
	cin >> numYears;

	//Checks for vallid input and prompts if needed for new input
	if (numYears < 0) {
		while (numYears < 0) {
			cout << "Invaild input. Please enter a non-negative input.";
			cin >> numYears;
		}
	}
	SetNumYears(numYears);						//Sets the user input to numYears

	system("pause");							//System waits for user to hit any key to continue running
}

//Displays the types of information to be displayed to create columns 
void InvestmentCalculator::DisplayHeaeder() {
	std::cout << std::right << std::setw(10);
	cout << "Year";
	cout << "	" << "Year End Balance";
	cout << "	  " << "Year End Earned Interest" << endl;
	cout << FormatLine(75, '~') << endl;
}

//Outputs the details for each column
void printDetails(int currYear, double endBal, double yearlyInterest) {
	cout << fixed << showpoint << setprecision(2);
	std::cout << std::right << std::setw(6) << currYear;
	std::cout << std::left << std::setw(2);
	cout << "		" << "$" << endBal;
	std::cout << std::right << std::setw(28);
	cout << "		" << "$" << yearlyInterest << endl;
}

//Calculates yearly balance and intrest for each year without a deposit each month
double InvestmentCalculator::CalcBalWithoutDeposit(double m_initBal, double m_interestRate, int m_numYears) {
	int i;
	int currYear;
	int numMonths = m_numYears * 12;				//Calculates number of months based on number of years
	double monthlyInterest = 0.0;
	double yearlyInterest = 0.0;
	double endBal = m_initBal;

	//Formatting for display providing the title of table being created
	cout << endl << FormatLine(75, '~') << endl;
	cout << FormatLine(8, ' ') << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << FormatLine(75, '~') << endl;
	DisplayHeaeder();

	/*For loop to itterate through each month for n years,
	* monthlyIntrest is calculated based on the previous month's end balance,
	* totals up the interest for the year, adds the monthly intrest to the end balance,
	* calculates the current year */
	for (i = 1; i <= numMonths; ++i) {
		monthlyInterest = endBal * ((m_interestRate / 100) / 12);	
		yearlyInterest += monthlyInterest;
		endBal += monthlyInterest;
		currYear = i / 12;

		//Calls for the details to be printed each year of total values
		if ((i % 12) == 0) {
			printDetails(currYear, endBal, yearlyInterest);
			yearlyInterest = 0.0;					//Resests yearly intrest for the next set of itterations
		}
	}

	cout << endl;
	return endBal;
}

//Calculates end balance and intrest each year for an account with monthly deposits
double InvestmentCalculator::CalcBalWithDeposit(double m_initBal, double m_interestRate, int m_numYears, double m_monthlyDeposit) {
	int i;
	int currYear;
	int numMonths = m_numYears * 12;
	double monthlyInterest = 0.00;
	double yearlyInterest = 0.00;
	double endBal = m_initBal;

	//Formatting for display providing the title of table being created
	cout << endl << FormatLine(75, '~') << endl;
	cout << FormatLine(8, ' ') << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << FormatLine(75, '~') << endl;
	DisplayHeaeder();

	/*For loop to itterate through each month for n years,
	* monthlyIntrest is calculated based on the previous month's end balance,
	* totals up the interest for the year, adds the monthly intrest to the end balance,
	* calculates the current year */
	for (i = 1; i <= numMonths; ++i) {
		monthlyInterest = endBal * ((m_interestRate / 100) / 12);
		yearlyInterest += monthlyInterest;
		endBal += monthlyInterest + m_monthlyDeposit;
		currYear = i / 12;

		//Calls for the details to be printed each year of total values
		if ((i % 12) == 0) {
			printDetails(currYear, endBal, yearlyInterest);
			yearlyInterest = 0.0;					//Resests yearly intrest for the next set of itterations
		}
	}


	return endBal;
}
