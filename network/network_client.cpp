
// project
#include "network_client.h"

struct SNetworkPackage {
    int64_t id;
    std::string dataString;
    void * dataBinary;
    int len;

    std::string serialize();
    void * serialize( int & _len );
};

ANetworkClient::ANetworkClient(){


}

ANetworkClient::~ANetworkClient(){

}

const std::string & ANetworkClient::getLastError(){
    return m_lastError;
}

bool ANetworkClient::addObserver( INetworkClientObserver * _observer ){

    // TODO: check for duplicate

    m_observers.push_back( _observer );
    return true;
}

bool ANetworkClient::removeObserver( INetworkClientObserver * _observer ){

    // TODO: do :)

    return true;
}
