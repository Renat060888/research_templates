
// project
#include "network_client.h"

ANetworkClient::ANetworkClient() :
    m_shutdown(false){


}

ANetworkClient::~ANetworkClient(){

    m_shutdown = true;
}

void ANetworkClient::threadNetworkCallbacks(){

    while( ! m_shutdown ){
        runNetworkCallbacks();
    }
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
