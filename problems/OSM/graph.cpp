#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <unordered_map>
#include "bmp.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;

struct Node {
    double lat, lon;
};

struct Way {
    std::vector<long long> node_refs;
    bool is_highway = false;
    std::string name; // To store the road name if available
};

struct Edge {
    long long node1, node2;
    std::string label;
};

std::map<long long, Node> nodes;
std::vector<Way> ways;
std::unordered_map<long long, std::unordered_map<long long, std::string>> graph;  // Adjacency list

double min_lat = 1e9, max_lat = -1e9;
double min_lon = 1e9, max_lon = -1e9;

void parse_osm(const char* filename) {
    XMLDocument doc;
    if (doc.LoadFile(filename) != XML_SUCCESS)
        throw std::runtime_error("Failed to read OSM file");

    XMLElement* root = doc.RootElement();
    for (XMLElement* elem = root->FirstChildElement(); elem; elem = elem->NextSiblingElement()) {
        std::string tagName = elem->Name();
        if (tagName == "node") {
            long long id = std::stoll(elem->Attribute("id"));
            double lat = std::stod(elem->Attribute("lat"));
            double lon = std::stod(elem->Attribute("lon"));
            nodes[id] = {lat, lon};
            min_lat = std::min(min_lat, lat);
            max_lat = std::max(max_lat, lat);
            min_lon = std::min(min_lon, lon);
            max_lon = std::max(max_lon, lon);
        } else if (tagName == "way") {
            Way way;
            bool is_hw = false;
            for (XMLElement* child = elem->FirstChildElement(); child; child = child->NextSiblingElement()) {
                std::string childName = child->Name();
                if (childName == "nd") {
                    long long ref = std::stoll(child->Attribute("ref"));
                    way.node_refs.push_back(ref);
                } else if (childName == "tag") {
                    const char* k = child->Attribute("k");
                    const char* v = child->Attribute("v");
                    if (k && std::string(k) == "highway") {
                        is_hw = true;
                    }
                    if (k && std::string(k) == "name") {
                        way.name = v ? v : "";
                    }
                }
            }
            way.is_highway = is_hw;
            ways.push_back(way);

            // Add edges to the graph (undirected)
            for (size_t i = 1; i < way.node_refs.size(); ++i) {
                long long node1 = way.node_refs[i - 1];
                long long node2 = way.node_refs[i];
                if (!way.name.empty()) {
                    graph[node1][node2] = way.name;
                    graph[node2][node1] = way.name;  // Since roads are usually bidirectional
                }
            }
        }
    }
}

int scale(double value, double minv, double maxv, int size) {
    return static_cast<int>((value - minv) / (maxv - minv) * (size - 1));
}


void print_graph() {
    for (const auto& node : graph) {
        std::cout << "Node" << nodes[node.first].lat << " " << nodes[node.first].lon <<"\n";
        for (const auto& edge : node.second) {
            std::cout << "Edge: " << node.first << " <-> " << edge.first << " (Road: " << edge.second << ")\n";
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input.osm> \n";
        return 1;
    }

    const char* input_file = argv[1];

    parse_osm(input_file);

    // Print the graph with edge labels
    print_graph();

    return 0;
}
