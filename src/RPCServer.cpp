#include <RPCServer.hpp>

namespace Chroma {
    bool RPCServer::startServer(Server* _server, int port) {
        server.bind("startServer", [_server](std::string ip, int port) {
            _server->startServer(ip, port);
        });

        server = rpc::server(port);
        return true;
    }
}