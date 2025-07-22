#include <iostream>

#include <Server.hpp>

int main() {
    Chroma::Server server;
    server.createRoute("/", Chroma::Server::RouteType::GET, [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello World!", "text/plain");
    });
    server.startServer("127.0.0.1", 8080);
}