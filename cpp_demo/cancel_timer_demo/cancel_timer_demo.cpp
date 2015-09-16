#include <iostream>
#include <boost/asio.hpp>

using namespace std;

void print(const boost::system::error_code& err) {
    if (err) {
        cout << "timer is canceled!" << endl;
        return;
    }

    cout << "hello boost!" << endl;
}

int main() {
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));
    timer.async_wait(&print);

    boost::asio::deadline_timer timer2(io, boost::posix_time::seconds(2));
    timer2.async_wait(&print);

    boost::asio::deadline_timer timer3(io, boost::posix_time::seconds(3));
    timer3.wait();
    timer.cancel();

    io.run();
    return 0;
}
