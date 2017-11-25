#include <memory>
#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WServer.h>
#include "include/HelloWorldApplication.hpp"

int main(int argc, char *argv[]) {
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& environment) {
        std::cout << "Deployment path\t: " << environment.deploymentPath() << std::endl;
        std::cout << "Internal path\t: " << environment.internalPath() << std::endl;
        std::cout << "Server port    \t: " << environment.server()->httpPort() << std::endl;
        return std::make_unique<HelloWorldApplication>(environment);
    });
}
