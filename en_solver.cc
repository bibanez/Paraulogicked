// Paraulògic Solver:
// It takes as input the letters of the day and outputs the according solution.

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const string DICT = "ca_netejat.txt";

// Pre:		File
// Post: 	Vector that contains all the words in a file separated by spaces.
vector<string> read(string file_name) {
	fstream file;
	file.open(file_name.c_str(), ios::in);
	vector<string> s;
	if (!file) {
		cout << "No s'ha trobat el fitxer" << endl;
	} else {
		string w;
		while (file >> w) s.push_back(w);
	}
	file.close();
	return s;
}

// Pre: 	String w and char c
// Post: 	Returns true if string w contains letter c. 
bool contains(const string w, const char c) {
	int n = w.size();
	int i = 0;
	while (w[i] != c and i < n) ++i;
	return i != n;
}

// Pre:		Two strings a, b
// Post:	Returns true if string a should go before string b.	
bool cmp(string a, string b) {
	return a.size() > b.size() or (a.size() == b.size() and a < b);
}

// Pre:		Dictionary dict, set of letters chars and central letter c
// Post:	Returns a vector that contains all the words that are a solution
// 			ordered by size and alphabetically.
vector<string> solver(const vector<string> &dict, string chars, char c) {
	vector<string> sol;
	int n = dict.size();
	for (int i = 0; i < n; ++i) {
		if (contains(dict[i], c)) {
			int m = dict[i].size();
			int j = 0;
			while (j < m and contains(chars, dict[i][j])) ++j;
			if (j == m) {
				sol.push_back(dict[i]);
			}
		}
	}
	
	sort(sol.begin(), sol.end(), cmp);
	
	return sol;
}

// Pre: 	Vector that contains any number of strings.
// Post:	Print all the elements of the vector separated by a `,`.
void print(const vector<string> &words) {
	int n = words.size();
	cout << "There are " << n << " words: " << endl;
	for (int i = 0; i < n; ++i) cout << i + 1 << ". " << words[i] << endl;
}

int main() {
	vector<string> dict = read(DICT);
	
	cout << "Letters: ";
	string chars;
	while (cin >> chars) {
		cout << "Solutions: ";
		print(solver(dict, chars, chars[0]));
		
		cout << "Letters: ";
	};

}
