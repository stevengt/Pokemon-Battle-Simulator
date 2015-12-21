

#include "sio_client.h"

#include <functional>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#ifdef WIN32
#define HIGHLIGHT(__O__) std::cout<<__O__<<std::endl
#define EM(__O__) std::cout<<__O__<<std::endl

#include <stdio.h>
#include <tchar.h>
#define MAIN_FUNC int _tmain(int argc, _TCHAR* argv[])
#else
#define HIGHLIGHT(__O__) std::cout<<"\e[1;31m"<<__O__<<"\e[0m"<<std::endl
#define EM(__O__) std::cout<<"\e[1;30;1m"<<__O__<<"\e[0m"<<std::endl

#define MAIN_FUNC int main(int argc ,const char* args[])
#endif


#include "ofApp.h"

using namespace sio;
using namespace std;


class connection_listener
{
    sio::client &handler;
    ofApp *mainApp;
public:

    connection_listener(sio::client& h, ofApp *mainApp):
    handler(h)
    {
        this->mainApp = mainApp;
    }


    void on_connected()
    {
        mainApp->_lock.lock();
        mainApp->_cond.notify_all();
        mainApp->connect_finish = true;
        mainApp->_lock.unlock();
    }
    void on_close(client::close_reason const& reason)
    {
        std::cout<<"sio closed "<<std::endl;
        exit(0);
    }

    void on_fail()
    {
        std::cout<<"sio failed "<<std::endl;
        exit(0);
    }
};