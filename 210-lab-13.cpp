#include <iostream>
#include <algorithm> //for sort() and find()
#include <numeric> //for accumulate()
#include <array>
#include <string>
#include <fstream> //for reading file
#include <cstdlib> //for atof
using namespace std;

const int RUNNERS = 30;

void finTimes(array<double, RUNNERS>&);
void coutTimes(array<double, RUNNERS>&);

int main()
{
	array<double, RUNNERS> times; //creates array for runners' 100m dash times
	finTimes(times); //populates array from txt file

	cout << "1. # of times: " << times.size() << endl; //showcase variety of functions
	cout << "2. Values: " << endl;
	coutTimes(times); //output all times
	cout << "3. Front: " << times.front() << endl; //first in array
	cout << "4. Back: " << times.back() << endl; //last in array
	cout << "5. Empty?: " << (times.empty() == 0 ? "False" : "True") << endl; //check empty
	cout << "6. Max: " << *max_element(times.begin(), times.end()) << endl; //find max
	cout << "7. Min: " << *min_element(times.begin(), times.end()) << endl; //find min

	cout << "8. Find 11.12s: "; //finds target index + 1 to account for offset
	double target = 11.12;
	array<double, RUNNERS>::iterator it;
	it = find(times.begin(), times.end(), target);
	if (it != times.end()) {
		cout << it - times.begin() + 1 << endl;
	}
	else {
		cout << "Not found." << endl;
	}

	cout << "9. Sort: " << endl; //sorts times least to greatest
	sort(times.begin(), times.end());
	coutTimes(times);

	cout << "10. Reverse Sort: " << endl; //reverse sort greatest to least
	sort(times.rbegin(), times.rend());
	coutTimes(times);



}

void finTimes(array<double, RUNNERS>& times) {
	ifstream fin;
	fin.open("times.txt");
	string buf;

	if (fin.good()) {
		for (int i = 0; i < RUNNERS; i++) {
			getline(fin, buf); times[i] = atof(buf.c_str());
		}

		fin.close();
	}
	else {
		cout << "File not found." << endl;
	}

}

void coutTimes(array<double, RUNNERS>& times) {
	for (int i = 0; i < RUNNERS; i++) {
		cout << i + 1 << ". " << times[i] << "   ";

		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}
}