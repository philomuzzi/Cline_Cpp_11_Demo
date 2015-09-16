#include <iostream>
#include <boost/asio.hpp>

using namespace std;

typedef function<void (const boost::system::error_code&)> timer_callback;

void print(const boost::system::error_code&) {
    cout << "boost" << endl;
}

int main() {
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(1));
    timer_callback callback = [&](const boost::system::error_code& err) {
        print(err);
        timer.expires_at(timer.expires_at() + boost::posix_time::seconds(1));
        timer.async_wait(callback);
    };

    timer.async_wait(callback);
    io.run();

    return 0;
}
