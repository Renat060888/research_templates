#pragma once

// project
#include "network_client.h"

class NetworkClientZeroMQ : public ANetworkClient {

public:
    NetworkClientZeroMQ();
    virtual ~NetworkClientZeroMQ();

    // system
    virtual bool init( const SConnectionSettings & _settings  ) override;
    virtual void runNetworkCallbacks() override;

    // data sending
    virtual bool sendDataAsync( const std::string & _data ) override;
    virtual bool sendDataAsync( const void * _data, int _len ) override;

    // only for synchronous protocols ( HTTP, REQ-RES in ZeroMQ, etc. )
    virtual bool sendData( const std::string & _data ) override;
    virtual bool sendData( const void * _data, int _len ) override;

private:

};
