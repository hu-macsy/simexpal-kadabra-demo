#include <iostream>

#include <networkit/auxiliary/Timer.hpp>
#include <networkit/centrality/KadabraBetweenness.hpp>
#include <networkit/graph/Graph.hpp>
#include <networkit/io/NetworkitBinaryReader.hpp>

int main(int argc, char *argv[]) {
    Aux::Log::Settings::setLogLevel(Aux::Log::LogLevel::error);
    auto g = NetworKit::NetworkitBinaryReader().read(argv[1]).toUnweighted();
    Aux::Timer timer;
    NetworKit::KadabraBetweenness kb(g, 0.01, 0.1, argv[2][6]);
    timer.start();
    kb.run();
    timer.stop();
    double secs = timer.elapsedMilliseconds();
    std::cout << "time: " << secs / 1000. << std::endl;
    return 0;
}
