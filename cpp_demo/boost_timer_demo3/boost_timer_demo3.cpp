#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(3));

    timer.wait();
    std::cout << "hello boost\n";

    return 0;
}
