
// project
#include "network_client_zeromq.h"

NetworkClientZeroMQ::NetworkClientZeroMQ(){

}

NetworkClientZeroMQ::~NetworkClientZeroMQ(){

}

// system
bool NetworkClientZeroMQ::init( const SConnectionSettings & _settings  ){


}
void NetworkClientZeroMQ::runNetworkCallbacks(){

}

// data sending
bool NetworkClientZeroMQ::sendDataAsync( const std::string & _data ){


}

bool NetworkClientZeroMQ::sendDataAsync( const void * _data, int _len ){

}

// only for synchronous protocols ( HTTP, REQ-RES in ZeroMQ, etc. )
bool NetworkClientZeroMQ::sendData( const std::string & _data ){


}

bool NetworkClientZeroMQ::sendData( const void * _data, int _len ){


}
