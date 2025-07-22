#include <iostream>

#include <Server.hpp>
#include <RPCServer.hpp>

int main() {
    Chroma::RPCServer rpcServer;

    Chroma::Server server;
    server.createRoute("/", Chroma::Server::RouteType::GET, [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello World!", "text/plain");
    });

    server.setLogging(true);
    
    rpcServer.startServer(&server);
}