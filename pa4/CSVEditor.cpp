#include "CSVEditor.hpp"

CSVEditor::CSVEditor(string& inputPath, string& rosterPath, string& outputPath, regex expr, int m) {
    //IMPLEMENT
	input.open(inputPath);
	roster.open(rosterPath);
	output.open(outputPath);
	regexPattern = expr;
	hashTable = new HashTable<string>(m);
}

CSVEditor::~CSVEditor(){
	//IMPLEMENT
	input.close();
	roster.close();
	output.close();

}
void CSVEditor::readCSVToTable() {
	//IMPLEMENT
	if(input.is_open()){
		string line;
		while(getline(input,line)){
			smatch match;
			regex_search(line,match,regexPattern);
			stringstream change(match.str(1));
			int k = 0;
			change>>k;
			hashTable->insert(k,match.str(2));
		}
	}
}
void CSVEditor::writeCSVToFile() {
	if(roster.is_open()){
	string line;	
		while(getline(roster,line)){
			smatch match;
			regex_search(line,match,regexPattern);
			stringstream change(match.str(1));
			int k = 0;
			change >> k;
			line.append(hashTable->search(k));
			output << line << endl;
		}	
	}
}
std::tuple<int, int, double> CSVEditor::getStats(){
	//IMPLEMENT;
	int min = hashTable->minChainLen();
	int max = hashTable->maxChainLen();
	double avg = hashTable->averageChainLen();
	return std::make_tuple(min, max, avg);
}