#include<fstream>
#include<regex>
#include<iostream>
using namespace std;

int main(int ac, char **av) {
	ifstream f(av[1]); string s;
	for(char c; f >> noskipws >> c;) s += c;
	const char *c[] = {"if", "for", "while"};
	regex e{R"head(\n(\w+\s+.*\(.*\))\s*\{)head"};
	for(smatch m; regex_search(s, m, e); s = m.suffix())
		cout << m[1].str() << endl;
}
