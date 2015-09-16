#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	int i{1};
	cout << i << endl;
	vector<int> iv {1,2,3,4,5} ;
	
	for (auto i : iv) {
		cout << i << endl;
	}

	string s{"hello, world"};
	cout << s << endl;
	auto xxx = [](string s) {
		for (auto i : s) {
			cout << i << " ";
		}
		cout << endl;
	};
	xxx(s);

    map<int, string> imap{ {1,"a"}, {2, "b"}};
    for (auto i : imap) {
        cout << i.first << " is " << i.second << endl;
    } 

	return 0;
}
