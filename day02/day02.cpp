#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

int letter2Index(char letter) {
	
	int index;

	// Calculate the index value
	index = int(letter);
	index = index - 97; // convert away from acsii code

	return index;
}




int main() {
    
    // Local declarations
    int count_3 = 0;
    bool flag_3;
    int count_2 = 0;
    bool flag_2;
    string ID;
    vector<string> ID_store;
    int cnt;
    char letter;
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e',
	                 'f', 'g', 'h', 'i', 'j',
			 'k', 'l', 'm', 'n', 'o',
			 'p', 'q', 'r', 's', 't',
			 'u', 'v', 'w', 'x', 'y',
			 'z'};

    int letter_count[26] = {0, 0, 0, 0, 0, 0,
	                    0, 0, 0, 0, 0, 0,
		  	    0, 0, 0, 0, 0, 0,
			    0, 0, 0, 0, 0, 0,
			    0, 0};
    int num_IDs = 0;
    string filename = "./input_day2.txt";
    	
    // Read and Extract contents of file
    ifstream inFile;
    inFile.open("./" + filename);
    if (!inFile) {
	    cerr << "Unable to open file: " + filename << endl;
	    exit(1); // call the system to stop
    }
	
    while (inFile >> ID) {
	ID_store.push_back(ID);
	num_IDs++;
    }

    inFile.close();

    // Run calculations on IDs
    for(int i = 0; i < num_IDs; i++) {
	    
	    // Extract ID
	    ID = ID_store[i];
	    cout << "ID: " << ID << " | ";
	    
	    //for each letter in alphabet
	    for(int j = 0; j < 26; j++) {
		letter = alphabet[j];

		//for each character in ID
		for(int k = 0; k < ID.length(); k++) {
			
			if (ID[k] == letter) {
				letter_count[j] = letter_count[j] + 1;
			}
		
		}
	
	    }
		
	    for(int m = 0; m < 26; m++) {
		cnt = letter_count[m];

    		if (cnt == 2 && !(flag_2)) {
			count_2++;
			flag_2 = 1;
		}
		if (cnt == 3 && !(flag_3)) {
			count_3++;
			flag_3 = 1;
		}
		
	    }
	
	for(int n = 0; n < 26; n++) {
		letter_count[n] = 0;
	}
	flag_2 = 0;
	flag_3 = 0;
	cout << "2_count: " << count_2 << ", 3_count: " << count_3 << endl;

    }

    int check_sum = count_3 * count_2;    
    cout << "Check Sum: " << check_sum << endl;


    return 0;
}

