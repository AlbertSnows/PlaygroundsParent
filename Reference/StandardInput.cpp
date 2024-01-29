#include <string>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
void read_input() {
	vector<string> lines;
	string line;
	while (getline(cin, line) && !line.empty()) {
		lines.push_back(line);
	}
}