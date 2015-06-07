////////////////////////////////////////////////////////////////////////////////
// FileName:    Worker.cpp
// Description: Defines the member functions provided in the interface Worker.h.
// Author:      Smruti Tatavarthy
// Project:     Homework2(Programming in C++)
// Reference:   Programming in C++ - Dietel & Dietel(9th Edition)
///////////////////////////////////////////////////////////////////////////////

class Worker
{
public:
	void calculatepay();
	double Manager(double,double &);
	double HourlyWorkers(double, double, double &);
	double CommissionWorkers(double, double &);
	double PieceWorkers(double, double, double &);
private:
	void displayManager(double);
		void displayHourly(double);
		void displayCommissionWorkers(double);
		void displayPieceWorker(double);
	
};
