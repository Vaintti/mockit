#include <iostream>
#include <fstream>
#include <list>
using namespace std;

list<string> file_to_list(string filename) {
	ifstream inputstream;
	string line;
	list<string> names;
	inputstream.open(filename);
	if (inputstream.is_open()) {
		while(getline(inputstream, line)){
			names.push_back(line);
		}

		inputstream.close();
	}
	return names;
}

int main() {
	list<string> firstnames = file_to_list("firstnames.txt");
	list<string> lastnames = file_to_list("lastnames.txt");
	
	list<string>::iterator fn_it;
	list<string>::iterator ln_it;
	string firstname, lastname, line;
	ofstream outputstream ("output.txt");
	for (fn_it = firstnames.begin(); fn_it != firstnames.end(); ++fn_it) {
		for (ln_it = lastnames.begin(); ln_it != lastnames.end(); ++ln_it) {
			outputstream << fn_it->data() << '\t' << ln_it->data() << '\n';
		}
	}
	
	return 0;
}