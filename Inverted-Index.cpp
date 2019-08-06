#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <regex>

using namespace std;

const char* inFl = "./input.txt";
const char* outFl = "./output.txt";

ifstream in(inFl);
ofstream out(outFl);

int main(){
	string line = "", word = "";
	int lineNum = 0, wordNum = 0;
	map<string,vector<pair<int,int>>> invIndex;
	//Regex to strip punctuation from words
	regex rx("[\\.?,!-+*/;:]+");
	//\\.,-+/*?!;:
	//Read in from file
	while(getline(in, line)){
		stringstream stream(line);
		lineNum++;
		while(stream >> word){
			wordNum++;
			//Remove punctuation
			word = regex_replace(word, rx,"");
			//Format word to lower case
			for(int i = 0; i <= word.length(); i++)
				word[i]= tolower(word[i]);
			//Add words and indexes to vectors in map
			if(word.length() > 0)
				invIndex[word].push_back(make_pair(lineNum, wordNum));
		}
		wordNum = 0;
	}
	for(auto const& term : invIndex){
		out << term.first << " " << term.second.size() << "[";
		for(auto const& indx : term.second)
			out << "(" << indx.first << "," << indx.second << ")";
		out << "]" << endl;
	}
	return 0;
}



