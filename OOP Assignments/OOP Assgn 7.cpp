#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <conio.h>
#include <map>
using namespace std;

void createMap(map<string, int> &population) {
	population.insert(pair<string, int> ("Bihar", 104099452));
	population.insert(pair<string, int> ("Maharashtra", 112374333));
	population.insert(pair<string, int> ("Rajasthan", 68548437));
}

int main() {
	map<string, int> population;
	createMap(population);
	bool repeat=true;
	int choice;
	while(repeat) {
		cout<<endl;
		cout<<"****** MENU ******"<<endl;
		cout<<"1. Insert Date"<<endl;
		cout<<"2. Display Data"<<endl;
		cout<<"3. Search Date"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<endl;

		cout<<"Enter your choice"<<endl;
		cin>>choice;

		switch (choice) {
			case 1: {
				string state;
				int pop;
				cout << "Enter name of state: ";
				cin >> state;
				cout << "Enter population: ";
				cin >> pop;
				population.insert(pair<string, int> (state, pop));
				cout << "\nData saved successfully!" << endl;
				break;
			}

			case 2: {
				cout << "# Population Data #" << endl;
				map<string, int> :: iterator itr;
				for (itr = population.begin(); itr != population.end(); itr++){
					cout << "[] " << itr->first << " : " << itr->second << endl;
				}
				break;
			}

			case 3: {
				string state;
				cout << "Enter state to search: ";
				cin >> state;
				cout << "\n[] " << state << " : " << population[state] << endl;
				break;
			}

			case 0: {
				cout << "# Exit from Database" << endl;
				break;
			}
		}
	}
	
    getch();
	return 0;
}