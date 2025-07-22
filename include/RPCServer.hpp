#pragma once

#include <rpc/server.h>

#include <Server.hpp>

namespace Chroma {
    class RPCServer {
    public:

        bool startServer(Server* server, int port);

    protected:
        rpc::server server;
    };
}