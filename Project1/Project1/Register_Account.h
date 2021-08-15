#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

void Register_Account(){
	//Variable
	string user_name, pass;
	fstream file;
	vector<string> row;
	int cnt = 0;
	//---------------------------
	cout << "**********REGISTER ACCOUNT**********";
	cout << "\nUser Name: ";
	cin >> user_name;
	cout << "\nPassword: ";
	cin >> pass;
	// Check whether this account is existed or not.
	file.open("Management_Account_Teacher.csv", ios::in);
	if (file.is_open()) {
		string word, str;		
		while (getline(file, str)) {
			row.clear();
			stringstream s(str);
			while (getline(s, word, ',')) {
				row.push_back(word);
			}
			for (int i = 0; i < row.size(); i++) {
				if (user_name == row[i]) {
					cnt++;
				}
				else {
					// Nothing to do.
				}
			}
		}
		if (cnt != 0) {
			system("cls");
			cout << "\nWarning! This account is existed, please try again.";
		}
		else {
			file.close();
			file.open("Management_Account_Teacher.csv", ios::app);
			if (file.is_open()) {
				file << user_name << "," << pass << "\n";
			}
			file.close();
			system("cls");
			cout << "\nAccount is created successfully";
		}
	}
	file.close();
}
