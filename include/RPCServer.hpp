#pragma once

#include <rpc/server.h>

#include <Server.hpp>

namespace Chroma {
    class RPCServer {
    public:
        RPCServer() : server(8080) {}

        bool startServer(Server* server);

    protected:
        rpc::server server;
    };
}