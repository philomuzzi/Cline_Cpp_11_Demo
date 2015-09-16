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
        boost::asio::io_service io_;
        boost::asio::steady_timer timer_;
        int count_;
        void print() {
            if (count_ < 500) {
                cout << count_ << endl;
                ++count_;

                timer_.expires_from_now(chrono::milliseconds(50));
                timer_.async_wait(bind(&printer::print, this));
            } else {
                cout << "Final count is " << count_ << endl;
                delete this;
            }
        }

        void run() {
            timer_.expires_from_now(chrono::milliseconds(50));
            timer_.async_wait(bind(&printer::print, this));
            io_.run();
        }

        printer() : timer_(io_), count_(0) {}
        ~printer() {}

    public:
        static printer* Create() {
            return new printer;
        }

        void start() {
            thread t;
            t = thread(std::mem_fun(&printer::run), this);
            t.detach();
        }
};

void foo() {
    printer *p = printer::Create();
    p->start();
}

int main() {
    foo();
    cin.get();
    return 0;
}
