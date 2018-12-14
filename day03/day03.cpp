#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

	vector<int> ID_Store;
	string filename = "./input_day03.txt";
	
	int fabric[1000][1000];
	vector<int> row_store;
	vector<int> col_store;
	vector<int> size_r_store;
	vector<int> size_c_store;
	
	int ID;
	int row;
	int col;
	int str_length;
	int size_r;
	int size_c;
	
	// initialize the fabric
	for(int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			fabric[i][j] = 0;
		}
	}
	
	
	ifstream inFile(filename);
	
	if(!inFile) {
		cout << "File could not be opened: " << filename << endl;
		exit(1);
	}


	string ID_s, garbage_at, loc, size;

	while (inFile >> ID_s >> garbage_at >> loc >> size) {
		ID = stoi(ID_s.substr(1,ID_s.length()));
		ID_Store.push_back(ID);
		
		row = stoi(loc.substr(0,loc.find(",")));
		str_length = loc.length() - (loc.find(",") + 1);
		col = stoi(loc.substr(loc.find(",")+1,str_length-1));
		
		row_store.push_back(row);
		col_store.push_back(col);
		
		
		size_r = stoi(size.substr(0,loc.find("x")));
		str_length = size.length() - (size.find("x") + 1);
		size_c = stoi(size.substr(size.find("x")+1,str_length));
		
		size_r_store.push_back(size_r);
		size_c_store.push_back(size_c);
		
	}
	
	for(int i = 0; i < ID_Store.size(); i++) {
		for(int j = row_store[i]; j < size_r_store[i] + row_store[i]; j++) {
			for(int k = col_store[i]; k < size_c_store[i] + col_store[i]; k++) {
				fabric[j][k]++;
			}
		}
	}
	
	int sq_inches = 0;
	
	for(int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if(fabric[i][j] > 1) {
				sq_inches++;
			}
		}
	}
	
	int sum;
	
	for(int i = 0; i < ID_Store.size(); i++) {
		sum = 0;
		for(int j = row_store[i]; j < size_r_store[i] + row_store[i]; j++) {
			for(int k = col_store[i]; k < size_c_store[i] + col_store[i]; k++) {
				if (fabric[j][k] == 1) {
					sum++;
				}
				
			}
		}
		if (sum == size_r_store[i]*size_c_store[i]) {
			cout << "Un-overlapped fabric!  " << ID_Store[i] << endl;
			break;
		}
	
	}
	
	
	
	cout << sq_inches << endl;
	


	return 0;
}

