#pragma once

#include <functional>
#include <string>

#include <httplib.h>

namespace Chroma {
    class Server {
    public:
        enum RouteType {
            GET,
            POST
        };
        Server() {}

        void startServer(std::string ipAddress, int port);
        void createRoute(std::string path, RouteType type, std::function<void(const httplib::Request& req, httplib::Response& res)> callback);
        void setLogging(bool logging);

    protected:
        httplib::Server server;
        bool enableLogging;
    };
}