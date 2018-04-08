#pragma once

// std
#include <string>
#include <vector>

class INetworkClientObserver {
public:
    virtual ~INetworkClientObserver(){}
    virtual void networkEvent( const std::string & _data ) = 0;
    virtual void networkEvent( const void * _data, int _len ) = 0;
};

struct SConnectionSettings {
    std::string host;
    int port;
    int pollTimeout;
};

class ANetworkClient {

public:
    ANetworkClient();
    virtual ~ANetworkClient();

    // system
    virtual bool init( const SConnectionSettings & _settings  ) = 0;
    virtual void runNetworkCallbacks() = 0;
    const std::string & getLastError();

    // data receipt
    bool addObserver( INetworkClientObserver * _observer );
    bool removeObserver( INetworkClientObserver * _observer );

    // data sending
    virtual bool sendDataAsync( const std::string & _data ) = 0;
    virtual bool sendDataAsync( const void * _data, int _len ) = 0;

    // only for synchronous protocols ( HTTP, REQ-RES in ZeroMQ, etc. )
    virtual bool sendData( const std::string & _data ) = 0;
    virtual bool sendData( const void * _data, int _len ) = 0;

protected:


private:
    std::string m_lastError;
    std::vector<INetworkClientObserver *> m_observers;
};





