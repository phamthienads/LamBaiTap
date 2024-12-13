//reading a csv file and look for values

#include <iostream>
#include <fstream>    // You need this for file I/0
#include <string>
using namespace std;

int main() {
	ifstream reader;   // create an input file stream
	//try to open the file, if not found throw an error
	try {
		reader.open("Restaurants.csv");   
		if (!reader) throw logic_error("File not found");
	}
	catch(exception &e)
	{
		cerr << "Exception: " << e.what() << endl;
		return -1;
	}
// variable to hold values read- name of restaurant, type of food an location
	string rname;
	string food_type;
	string location;
	string query;   // what the user wants to search for
	bool r_search = 1;   //does the user want to search

	bool found = 0;      //flag if a match is found
	//loop while r_search is true

	while (r_search) {
		cout << "What type of food do you want? ";    // ask for user input
		
		getline(cin, query);

		 
		//if (isblank(query[0]))     // remove a blank space from the front
		//query.erase(0, 1);


		// while (!(isblank(query[0])))   //remove all blank spaces from the front
		//	query.erase(0, 1);
		


// loop until we reach the end of the file
		while (!reader.eof())
		{
			// comma delimited, get values
			getline(reader, rname, ',');
			getline(reader, food_type, ',');
			getline(reader, location);
			//Do we have a match? if so print restaurant info
			if (food_type == query) {
				found = 1;
				cout << rname << " in " << location << " is a(n) " << food_type << " restaurant\n";
			}
		}
		// if we didn't find any, print a message
		if (found == 0) cout << "Sorry, no " << query << " restaurants found\n";
		//invite the user to search again
		cout << "Would you like to search again? 1 for yes, 0 for no:  ";
		getline(cin, query);  //staying with getline so don't have to worry about clearing buffer
		r_search = stoi(query);  //need to convert to int  we just re-used query variable because it was handy
		
		//reset everything so we can search again
		reader.clear();   //clear any reader flags
		reader.seekg(0, ios::beg);  // reset to beginning of file
		found = 0;       // reset found
	}

	reader.close();    // close file
	cout << "\nSee you later!\n";
	
	ofstream writer; // Create an output file stream to write data
	writer.open("Restaurants.csv", ios::app); // Open the file in append mode

	if (!writer) {
		cerr << "Unable to open file for writing." << endl;
		return -1;
	}

	bool add_more = true; // Variable to check if the user wants to add more data
	while (add_more) {
		cout << "Enter restaurant name: ";
		getline(cin, rname);
		cout << "Enter type of food: ";
		getline(cin, food_type);
		cout << "Enter location: ";
		getline(cin, location);

		// Create a line to write to the file
		writer << rname << "," << food_type << "," << location << endl;

		cout << "Do you want to add another restaurant? 1 for yes, 0 for no: ";
		getline(cin, query);
		add_more = stoi(query);
	}

	writer.close(); // Close the file after writing

	return 0;


}