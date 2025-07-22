#include <RPCServer.hpp>

#include <Defs.hpp>

namespace Chroma {
    bool RPCServer::startServer(Server* _server) {
        log::info("RPC Server running");
        server.bind("startServer", [_server](std::string ip, int port) {
            std::thread([_server, ip, port]() {
                _server->startServer(ip, port);
            }).detach();
            return true;
        });

        server.bind("pingServer", []() {
            log::info("pong!");
        });
        server.run();
        return true;
    }
}