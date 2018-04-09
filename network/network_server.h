#pragma once

// std
#include <string>
#include <vector>
#include <thread>

class AServerRequest {
public:
    AServerRequest(){}
    virtual ~AServerRequest(){}

    const std::string & readRequest(){ return m_request; }
    virtual bool sendResponse( const std::string & _data ) = 0;

protected:
    std::string m_request;
    void * m_serverHandle; // TODO: do :)
};

class INetworkServerObserver {
public:
    virtual ~INetworkServerObserver(){}
    virtual void networkEvent( AServerRequest * _request ) = 0;
};

struct SConnectionSettings {
    int port;
    int pollTimeout;
    bool asyncPoll;
};

class ANetworkServer {

public:
    ANetworkServer();
    virtual ~ANetworkServer();

    // system
    virtual bool init( const SConnectionSettings & _settings  ) = 0;
    virtual void runNetworkCallbacks() = 0;
    const std::string & getLastError();

    // data receipt
    bool addObserver( INetworkServerObserver * _observer );
    bool removeObserver( INetworkServerObserver * _observer );

protected:
    void threadNetworkCallbacks();

private:
    std::string m_lastError;
    std::vector<INetworkServerObserver *> m_observers;
    std::thread m_threadNetworkCallbacks;
    bool m_shutdown;
};





