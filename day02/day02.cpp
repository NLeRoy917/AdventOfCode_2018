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

int num_differences(string string1, string string2) {

	int diff = 0;

	for(int i = 0; i < string1.length(); i++) {
			if (string1[i] != string2[i]) {
				diff++;
			}
		
	}

	return diff;
}

int findDiffIndex(string string1, string string2) {
	int index;

	for (int i = 0; i < string1.length(); i++) {
		if (string1[i] != string2[i]) {
			index = i;
			break;
		}
	}

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
    
    cout << "-=-=-=| Part 1 |=-=-=-" << endl;
    cout << "Calculating check sum..." << endl;
    // Run calculations on IDs
    for(int i = 0; i < num_IDs; i++) {
	   // cout << "No. ID's Processed: " << i << "\r";
	    // Extract ID
	    ID = ID_store[i];
	    //cout << "ID: " << ID << " | ";
	    
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
	//cout << endl << "2_count: " << count_2 << ", 3_count: " << count_3 << endl;

    }

    int check_sum = count_3 * count_2;    
    cout << "Check Sum: " << check_sum << endl;

    
    cout << "-=-=-=| Part 2 |=-=-=-" << endl;
    cout << "Looking for differences in IDs..." << endl;
    int break_flag = 0;
    int diff;
    int index;
    string spaces;

    for(int i = 0; i < num_IDs; i++) {
	    for(int j = i + 1; j < num_IDs; j++) {
		    diff = num_differences(ID_store[i],ID_store[j]);
		   // cout  << ID_store[i] << " |  " << ID_store[j] << " | Diff: " << diff << endl;
		    if (diff == 1) {
			    index = findDiffIndex(ID_store[i], ID_store[j]);
			    for(int x = 0; x < index; x++) {
				    spaces = spaces + " ";
			    }
			    cout << "Difference Found!" << endl;
			    cout << "          " << spaces << "|" << endl;
			    cout << "          " << spaces << "v" << endl;
			    cout << "String 1: " << ID_store[i] << endl;
			    cout << "String 2: " << ID_store[j] << endl;
		    	    break_flag = 1;
			    break;
		    }
	    }
	    if (break_flag) {
		    break;
	    }
    }



    return 0;
}

