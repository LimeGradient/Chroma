#include <Server.hpp>

#include <Defs.hpp>

namespace Chroma {
    void Server::startServer(std::string ipAddress, int port) {
        log::info("Server listening on port {}", port);
        server.listen(ipAddress, port);
    }

    void Server::createRoute(std::string path, Server::RouteType type, std::function<void(const httplib::Request& req, httplib::Response& res)> callback) {
        switch (type) {
            case GET: {
                server.Get(path, callback);
                break;
            }
            case POST: {
                server.Post(path, callback);
                break;
            }
            default:
                break;
        }
    }

    void Server::setLogging(bool logging) {
        this->enableLogging = logging;
        if (logging) {
            server.set_logger([](const httplib::Request& req, const httplib::Response& res) {
                log::info("Request: {}\nPath: {}\nBody: {}\nResponse: {}", req.method, req.path, req.body, res.body);
            });
        } else {
            return;
        }
    }
}