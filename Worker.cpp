//////////////////////////////////////////////////////////////////////////
// FileName:    Worker.cpp
// Description: Defines the member functions provided in the interface Worker.h.
// Author:      Smruti Tatavarthy
// Project:     Homework2(Programming in C++)
// Reference:   Programming in C++ - Dietel & Dietel(9th Edition)
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Worker.h" // include definition of class Worker
using namespace std;



void Worker::calculatepay()
{
	int paycode = 0;
	double salary = 0;
	double hour_salary = 0;
	double hours = 0;
	double sales = 0;
	double pieces = 0;
	double wage = 0;
	double M_salary = 0;
	double C_salary = 0;
	double H_salary = 0;
	double P_salary = 0;
	double sum=0;
	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;

	do
	{
		cout << "\n Enter paycode or (-1 to end): ";	//input from the user
		cin >> paycode;

		switch (paycode)
		{
		case 1:
			cout << " Manager Selected " << endl;				//switch case for manager
			cout << " Enter the Weekly Salary:  ";
			cin >> M_salary;
			M_salary = Worker::Manager(M_salary,sum);			//calling method manager for calculating his pay
			break;

		case 2:
			cout << "\n Hourly Workers Selected " << endl;		//switch case for hourly workers
			cout << " Enter the Hourly Salary : " ;
			cin >> hour_salary;
			cout << " Enter the number of hours worked : ";
			cin >> hours;
			H_salary = Worker::HourlyWorkers(hour_salary, hours, sum1);//calling method to calculate pay for hourly workers
			break;

		case 3:
			cout << "\n Commission Workers Selected" << endl;  //switch case for commission workers
			cout << " Enter the gross weekly sales : " ;
			cin >> sales;
			C_salary = Worker::CommissionWorkers(sales,sum2);		//calling method to calculate pay for commission workers
			break;

		case 4:
			cout << "\n Piece Workers Selected" <<endl;		//switch case for Piece workers
			cout << " Enter the number of pieces : ";
			cin >> pieces;
			cout << " Enter the wage per piece: ";
			cin>> wage;
			P_salary = Worker::PieceWorkers(pieces, wage, sum3);		//calling method to calculate pay for piece workers
			break;

		default: cout << " Enter -1 to exit\n";
			break;
		}

	} while (paycode != -1);

	displayManager(M_salary);
	displayHourly(H_salary);
	displayCommissionWorkers(C_salary);
	displayPieceWorker(P_salary);

}

void Worker::displayManager(double M_salary)		//bar chart display method for manager
{

	int n = 100;
	M_salary = int(M_salary / n);
	cout << " Managers";

	for (int i = 0; i < M_salary; i++)
	{
		cout << " *";
	}
}

void Worker::displayHourly(double H_salary)			// bar chart display method for hourly workers
{
	int n = 100;
	H_salary = int(H_salary / n);
	cout << "\n Hourly Workers";

	for (int i = 0; i < H_salary; i++)
	{
		cout << " *";
	}
}

void Worker::displayCommissionWorkers(double C_salary)		// bar chart display method for Commission workers
{
	int n = 100;
	C_salary = int(C_salary / n);
	cout << "\n CommissionWorkers Workers";

	for (int i = 0; i < C_salary; i++)
	{
		cout << " *";
	}
}

void Worker::displayPieceWorker(double P_salary)		// bar chart display method for Piece workers
{
	int n = 100;
	P_salary = int(P_salary / n);
	cout << "\n PieceWorker Workers";

	for (int i = 0; i < P_salary; i++)
	{
		cout << " *";
	}
}


double Worker::Manager(double salary, double &sum)		//method to calculate pay for managers
	{
	
		sum= sum + salary;// to compute the total salary for all managers
		cout << " Managers pay is " <<salary << endl;
		return sum;
	}

double Worker::HourlyWorkers(double hour_salary, double hours, double &sum1)		//method to calculate pay for managers
	{
		double salary = 0;
		
		if (hours <= 40)	//salary if no of hours is < 40
		{
			salary = hour_salary*hours;
			sum1 = sum1 + salary;	// to compute the total salary for all Hourly Workers
			cout << " Hourly Workers pay is " << salary << endl;
		}
		else
		{
			salary = (40 * hour_salary) + ((hours - 40)* 1.5* hour_salary);	//salary if no of hours > 40 (1.5 times the remaining hours)
			sum1 = sum1 + salary;
			cout << " Hourly Workers pay is " <<salary << endl;
		}
		return sum1;

	}

double Worker::CommissionWorkers(double sales,double &sum2)		//method for calculating salary for Commission Workers
	{
		double salary = 250 + (5.7*sales / 100);	//computation considering 5.7% of sales
		sum2 = sum2 + salary;	// to compute the total salary for all Commission Workers
		cout << " CommisionWorker's pay is " << salary << endl;
		return sum2;
	}

double Worker::PieceWorkers(double pieces, double wage, double &sum3)		//method for calculating salary for Piece Workers
	{
	double salary = pieces*wage;
	sum3 = sum3 + salary;		// to compute the total salary for all Commission Workers
		cout << " PieceWorkers pay is " << salary << endl;
		return sum3;
	}



