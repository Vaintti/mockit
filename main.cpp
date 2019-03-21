#include <iostream>
#include <fstream>
#include <list>
using namespace std;

int line_count(string filename) {
	// Init variables
	string line;
	int count = 0;
	// Open file
	ifstream inputstream (filename);
	// Loop through lines
	while(getline(inputstream, line)) {
		count++;
	}
	// Close file
	inputstream.close();
	return count;
}

list<int> generate_random_indexes(int count, int max) {
	list<int> output;
	for (int i = 0; i < count; ++i) {
		output.push_back(rand() % max);
	}
	return output;
}

list<string> generate_names(int count) {
	list<string> output;
	int firstnames_count = line_count("firstnames.txt");
	int lastnames_count = line_count("lastnames.txt");
	list<int> firstname_indexes = generate_random_indexes(count, max(firstnames_count, 0));
	list<int> lastname_indexes = generate_random_indexes(count, max(lastnames_count, 0));

	while (firstname_indexes.size() > 0) {
		string firstname, lastname;
		int firstname_index = firstname_indexes.back();
		int lastname_index = lastname_indexes.back();
		firstname_indexes.pop_back();
		lastname_indexes.pop_back();

		// Get firstname
		ifstream filestream ("firstnames.txt");
		string line;
		int index = 0;
		while (getline(filestream, line)) {
			if (index == firstname_index) {
				firstname = line;
				break;
			}
			index++;
		}
		filestream.close();

		// Get lastname
		filestream.open("lastnames.txt");
		index = 0;
		while (getline(filestream, line)) {
			if (index == lastname_index) {
				lastname = line;
				break;
			}
			index++;
		}
		filestream.close();

		output.push_back(firstname + '\t' + lastname);
	}

	return output;
}

int main(int argc, char *argv[]) {
	int count = strtol(argv[1], nullptr, 0);
	list<string> output;
	
	output = generate_names(count);

	ofstream outputstream ("output.txt");
	for (list<string>::iterator i = output.begin(); i != output.end(); ++i) {
		outputstream << i->data();
		list<string>::iterator i_copy = i;
		i_copy++;
		if (i_copy != output.end()) {
			outputstream << '\n';
		}
	}

	return 0;
}
