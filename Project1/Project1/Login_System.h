#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

int Login_System() {
	// Variable
	string user_name, pass;
	fstream file;
	vector<string> row;
	int cnt = 0;
	//----------------------
	cout << "************LOGIN SYSTEM************";
	cout << "\nUser Name: ";
	cin >> user_name;
	cout << "\nPassword: ";
	cin >> pass;
	// Check whether this account is correct or not.
	file.open("Management_Account_Teacher.csv", ios::in);
	if (file.is_open()) {
		string word, line;
		while (getline(file, line)) {
			row.clear();
			stringstream str(line);
			while (getline(str, word, ',')) {
				row.push_back(word);
			}
			for (int i = 0; i < row.size(); i++) {
				if (row[i] == user_name)
					cnt++;
				else if (row[i] == pass)
					break;
				else
					cnt = 0;
			}
			if (cnt == 1)
				break;
			else {
				// Nothing to do
			}
		}
	}
	file.close();
	if (cnt == 0) {
		system("cls");
		cout << "Login Failed, please try again.";
		return 0;
	}
	else {
		system("cls");
		cout << "Login Successful";
		return 1;
	}
}
