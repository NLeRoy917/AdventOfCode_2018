#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

bool inVector(int num,vector<int> sum_store) {

	bool is_in_vect = 0; 

	for(int i = 0; i < sum_store.size(); i++) {
		if (num == sum_store[i]) {
			is_in_vect = 1;
		}
	}

	return is_in_vect;
}





int main() {

	// Variable and vector definitions
	string filename = "input.txt";
	int cnt = 0;
	vector<int> sum_store = {0};
	vector<int> shift_list;
	int sum = 0;
	int shift;
	bool not_found = 1;
	int final_frequency = 0;

	//Declare an input file stream
	ifstream inFile;
	inFile.open("./" + filename);

	// Check that the file was properaly opened
	if (!inFile) {
		cerr << "Unable to open file: " + filename;
		exit(1);
	}
	
	// Store the contents into a vector
	while(inFile >> shift) {
		shift_list.push_back(shift);
	}

	// Close the file for good
	inFile.close();

	//Part 1
	for (int i = 0; i < shift_list.size(); i++) {
		sum = sum + shift_list[i];
	}
	
	// Part One printing
	cout << "Part One:\n" << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Number of lines in file: " << shift_list.size() << endl;
	cout << "Total Sum: " << sum << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;
	
	// part 2
	sum = 0; // reinitialze sum
	cnt = 0;


	while(not_found) {
		
		cout << "# of passes " << cnt << endl;		
		cout << "Sum Store Size: " << sum_store.size() << endl;	

		for(int i = 0; i < shift_list.size(); i++) {

			// Calculate the values
			shift = shift_list[i];
			sum = sum + shift;

			// Check if it is found
			if (inVector(sum,sum_store)) {
				not_found = 0;
				final_frequency = sum;
				break;
			}
			// Store the newest sum in the vector
			sum_store.push_back(sum);
		}

		cnt++;
	
	}

	cout << "Final Frequency: " << final_frequency << endl;


	return 0;
}

