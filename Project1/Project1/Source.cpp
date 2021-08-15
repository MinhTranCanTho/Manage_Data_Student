#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <math.h>
#include "Login_System.h"
#include "Register_Account.h"
#include <vector>
#include "ManageDataStudent.h"
#include "Delay_Function.h"

using namespace std;

int Login_System();
void Register_Account();
void Manage_Data_Students();

int main() {
	string ans,word;
	fstream FILE;
	int result;
	FILE.open("Management_Account_Teacher.csv", ios::app);
	FILE << "-" << "," << "-" << "\n";
	FILE << "-" << "," << "-" << "\n";
	FILE.close();
	do {
		system("cls");
		cout << "**************WELCOME TO MY PROGRAM**************";
		cout << "\nDo you have any account ?";
		cout << "\nIf yes, please enter 1";
		cout << "\nIf no, please enter 2";
		cout << "\nIf you want to exit, please enter 3";
		cout << "\nYour answer is ";
		cin >> ans;
		if (ans == "1") {
			system("cls");
			result = Login_System();
			Delay(2);
			if (result == 1) {
				system("cls");
				Manage_Data_Students();
			}
			else {
				// Nothing to do
			}
		}
		else if (ans == "2") {
			system("cls");
			Register_Account();
			Delay(3);
		}
		else {
			// Nothing to do
		}
	} while (ans != "3");
}