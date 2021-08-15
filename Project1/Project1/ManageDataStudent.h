#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

void Manage_Data_Students() {
	//--------Variable-------
	int num_of_student, roll;
	int Liter, Maths, English, Physics, Chemistry;
	string NameOfStudent;
	fstream file;
	//-----------------------
	cout << "Have a nice day." << endl;
	cout << "How many students in your class ? ";
	cin >> num_of_student;
	file.open("Manage_Data_Students.csv", ios::app);
	if (file.is_open()) {
		cout << "\nRoll NameOfStudent Literature Maths English Physics Chemistry\n";
		file << "Roll" << ","
			<< "NameOfStudent" << ","
			<< "Literature" << ","
			<< "Maths" << ","
			<< "English" << ","
			<< "Physics" << ","
			<< "Chemistry" << "," << "\n";
		for (int i = 0; i < num_of_student; i++) {
			cin >> roll >> NameOfStudent >> Liter >> Maths
				>> English >> Physics >> Chemistry;
			// Write Data to file
			file << roll << ","
				<< NameOfStudent << ","
				<< Liter << ","
				<< Maths << ","
				<< English << ","
				<< Physics << ","
				<< Chemistry << "\n";
		}
	}
	file.close();
}
