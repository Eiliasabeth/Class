#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

#include <string>
using namespace std;

//Creates class InvestmentCalculator
class InvestmentCalculator {
	//Public functions for the program
	public:
		InvestmentCalculator();
		void SetInitBal(double m_initBal);
		double GetInitBal() const;
		void SetMonthlyDeposit(double m_monthlyDeposit);
		double GetMonthlyDeposit() const;
		void SetInterestRate(double m_interestRate);
		double GetInterestRate() const;
		void SetNumYears(int m_numYears);
		int GetNumYears() const;

		void InitialDisplay(double m_initBal, double m_interestRate, int m_numYears, double m_monthlyDeposit);
		string FormatLine(int t_width, char t_char);
		void DisplayHeaeder();
		double CalcBalWithoutDeposit(double m_initBal, double m_interestRate, int m_numYears);
		double CalcBalWithDeposit(double m_initBal, double m_interestRate, int m_numYears, double m_monthlyDeposit);

	//Private variables 
	private:
		double m_initBal;
		double m_interestRate;
		double m_monthlyDeposit;
		int m_numYears;
		string userInvestment;

};

#endif
