
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

}

bool ANetworkClient::addObserver( INetworkClientObserver * _observer ){


}

bool ANetworkClient::removeObserver( INetworkClientObserver * _observer ){



}
