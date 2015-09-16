#include <iostream>
#include <boost/asio.hpp>

void print(const boost::system::error_code&) {
    std::cout << "Hello World!\n";
}

int main() {
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(15));

    timer.async_wait(&print);
    io.run();

    return 0;
}
