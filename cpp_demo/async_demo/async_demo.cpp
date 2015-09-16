#include <iostream>
#include <boost/asio.hpp>
#include <vector>

using namespace std;

void print(const boost::system::error_code&) {
    std::cout << "Hello World!\n";
}

int main() {
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(15));

    timer.async_wait(&print);
    io.run();

    // 还是要在定时器之后执行
    vector<int> iv{1,2,3,4,5};
    for (auto i : iv)
        cout << i << endl;

    return 0;
}
