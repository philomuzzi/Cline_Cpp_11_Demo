#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    int i{23};
    auto d{23.3};
    auto s{"hello, "};
    string ss{"world"};
    cout << i << d << endl;
    cout << s << ss << endl;

    vector<int> iv{12, 34, 211, 3445};
    for (auto ii : iv)
        cout << ii << endl;

    return 0;
}