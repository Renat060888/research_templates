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

struct SNetworkPackage {
    int64_t id;
    std::string dataString;
    void * dataBinary;
    int len;

    std::string serialize();
    void * serialize( int & _len );
};

class ANetworkClient {

public:
    ANetworkClient();
    virtual ~ANetworkClient();
    virtual bool init( const SConnectionSettings & _settings  ) = 0;
    const std::string & getLastError();

    virtual void runNetworkCallbacks() = 0;

    bool addObserver( INetworkClientObserver * _observer );
    bool removeObserver( INetworkClientObserver * _observer );

    virtual bool sendDataAsync( const std::string & _data ) = 0;
    virtual bool sendDataAsync( const void * _data, int _len ) = 0;

    virtual bool sendData( const std::string & _data ) = 0;
    virtual bool sendData( const void * _data, int _len ) = 0;

protected:


private:
    std::string m_lastError;
    std::vector<INetworkClientObserver *> m_observers;
};





