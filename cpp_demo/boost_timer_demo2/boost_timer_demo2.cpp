#include <iostream>
#include <chrono>
#include <thread>
#include <boost/asio.hpp>

#include <boost/asio/high_resolution_timer.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/system_timer.hpp>

using namespace std;

class printer {
    private:
        boost::asio::steady_timer timer_;
        int count_;
        void print() {
            if (count_ < 10) {
                cout << count_ << endl;
                ++count_;

                timer_.expires_from_now(chrono::milliseconds(500));
                timer_.async_wait(bind(&printer::print, this));
            } else {
                cout << "Final count is " << count_ << endl;
                delete this;
            }
        }

        printer(boost::asio::io_service &io) : timer_(io, chrono::milliseconds(500)), count_(0) {
            timer_.async_wait(bind(&printer::print, this));
        }
        ~printer() {}

    public:
        static printer* Create(boost::asio::io_service &io) {
            return new printer(io);
        }
};

int main() {
    boost::asio::io_service io;
    printer::Create(io);
    printer::Create(io);
    printer::Create(io);
    printer::Create(io);
    io.run();
    cin.get();
    return 0;
}
