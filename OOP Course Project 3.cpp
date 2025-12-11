#include <iostream>
#include <string>
using namespace std;


class Employee {
private:
	int number;
	string name;
	string education;
public:
	Employee() {
		number = 0;
		name = "";
		education = "";
	}

	Employee(int n, string nm, string edu) {
		number = n;
		name = nm;
		education = edu;
	}
	~Employee() {}

	int getNumber() { return number; }
	string getName() { return name; }
	string getEducation() { return education; }

	void setNumber(int n) { number = n; }
	void setName(string nm) { name = nm; }
	void setEducation(string edu) { education = edu; }

	void print() {
		cout << "Number: " << number << endl;
		cout << "Name: " << name << endl;
		cout << "Education: " << education << endl;
	}

};


class Trainee : public Employee {
private:
	int hours3months;
	double HourlyRate;
public:
	Trainee() : Employee() {
		hours3months = 0;
		HourlyRate = 0;
	}

	Trainee(int n, string nm, string edu, int h, double baseRate)
		:Employee(n, nm, edu) {
		hours3months = h;
		if (edu == "secondary")
			HourlyRate = baseRate * 0.85;
		else
			HourlyRate = baseRate;
	}


	~Trainee() {}

	int getHours3months() { return hours3months; }
	double getHourlyRate() { return HourlyRate;}

	void setHours3months(int h) { hours3months = h; }
	void setHourlyRate(double r) { HourlyRate = r; }

	friend double monthPayment(Trainee t);

	void print() {
		Employee::print();
		cout << "Hours for 3 months: " << hours3months << endl;
		cout << "Hourly rate: " << HourlyRate << endl;
		cout << "Montly salary: " << monthPayment(*this) << endl;
	}
};


double monthPayment(Trainee t) {
	return (t.hours3months * t.HourlyRate) / 3.0;
}


int main() {
	int N;
	cout << "Enter number of trainees (N<=20): ";
	cin >> N;
	if (N > 20) N = 20;

	Trainee arr[20];

	for (int i = 0; i < N; i++) {
		int num;
		string name;
		int eduChoice;
		string edu;
		int hours;
		double baseRate;

		cout << "\nTrainee " << i + 1 << endl;

		cout << "Number: ";
		cin >> num;

		cout << "Nmae (One Word): ";
		cin >> name;

		cout << "Education (1-higher , 2-secondary)";
		cin >> eduChoice;
		if (eduChoice == 1) edu = "higher";
		else edu = "secondary";

		cout << "Hours for last 3 monthss: ";
		cin >> hours;

		cout << "Base hourly rate for higher education: ";
		cin >> baseRate;


		Trainee t(num, name, edu, hours, baseRate);
		arr[i] = t;
	}

	cout << "\nAll Trainees:\n ";
	for (int i = 0; i < N; i++) {
		cout << "\nTrainee " << i + 1 << ":\n";
		arr[i].print();
	}	

	cout << "\nTrainees with higher education (name and salary):\n";
	for (int i = 0; i < N; i++) {
		if (arr[i].getEducation() == "higher") {
			cout << "Name: " << arr[i].getName() << ", Monthly salary: " << monthPayment(arr[i]) << endl;
		}
	}


	if (N > 0) {
		int indexMax = 0;
		double maxSalary = monthPayment(arr[0]);
		for (int i = 1; i < N; i++) {
			double s = monthPayment(arr[i]);
			if (s > maxSalary) {
				maxSalary = s;
				indexMax = i;
			}
		}

		cout << "\nTrainee with highest Monthly Salary:\n";
		cout << "Name: " << arr[indexMax].getName() << ", Monthly salary: " << maxSalary << endl;
	}

	return 0;
}