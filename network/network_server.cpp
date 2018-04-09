
// project
#include "network_server.h"

ANetworkServer::ANetworkServer() :
    m_shutdown(false){


}

ANetworkServer::~ANetworkServer(){

    m_shutdown = true;
}

void ANetworkServer::threadNetworkCallbacks(){

    while( ! m_shutdown ){
        runNetworkCallbacks();
    }
}

const std::string & ANetworkServer::getLastError(){
    return m_lastError;
}

bool ANetworkServer::addObserver( INetworkServerObserver * _observer ){

    // TODO: check for duplicate

    m_observers.push_back( _observer );
    return true;
}

bool ANetworkServer::removeObserver( INetworkServerObserver * _observer ){

    // TODO: do :)

    return true;
}
