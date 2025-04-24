#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include <cmath>
#include "bmp.hpp"

struct Node {
    double lat;
    double lon;
};

std::map<std::string, Node> nodes;
std::vector<std::vector<std::string>> ways;

constexpr int WIDTH = 5000;
constexpr int HEIGHT = 5000;

// Draw a line using Bresenham's algorithm
void draw_line(BMP& bmp, int x1, int y1, int x2, int y2, const color& c) {
    int dx = std::abs(x2 - x1);
    int dy = -std::abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;

    while (true) {
        bmp.set_pixel(x1, y1, c.r, c.g, c.b);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

// Convert lat/lon to x/y using calculated scale
void latlon_to_xy(double lat, double lon, int& x, int& y,
                  double min_lat, double min_lon,
                  double scale_x, double scale_y) {
    x = static_cast<int>((lon - min_lon) * scale_x);
    y = HEIGHT - static_cast<int>((lat - min_lat) * scale_y); // invert Y for BMP
}

void parse_osm(const std::string& filename,
               double& min_lat, double& max_lat,
               double& min_lon, double& max_lon) {
    std::ifstream in(filename);
    std::string line;

    min_lat = std::numeric_limits<double>::max();
    max_lat = std::numeric_limits<double>::lowest();
    min_lon = std::numeric_limits<double>::max();
    max_lon = std::numeric_limits<double>::lowest();

    std::vector<std::string> current_way;

    while (std::getline(in, line)) {
        if (line.find("<node") != std::string::npos && line.find("/>") != std::string::npos) {
            size_t id_pos = line.find("id=\"");
            size_t lat_pos = line.find("lat=\"");
            size_t lon_pos = line.find("lon=\"");

            if (id_pos == std::string::npos || lat_pos == std::string::npos || lon_pos == std::string::npos) continue;

            std::string id = line.substr(id_pos + 4, line.find("\"", id_pos + 4) - (id_pos + 4));
            double lat = std::stod(line.substr(lat_pos + 5, line.find("\"", lat_pos + 5) - (lat_pos + 5)));
            double lon = std::stod(line.substr(lon_pos + 5, line.find("\"", lon_pos + 5) - (lon_pos + 5)));

            min_lat = std::min(min_lat, lat);
            max_lat = std::max(max_lat, lat);
            min_lon = std::min(min_lon, lon);
            max_lon = std::max(max_lon, lon);

            nodes[id] = {lat, lon};
        } else if (line.find("<way") != std::string::npos) {
            current_way.clear();
        } else if (line.find("<nd") != std::string::npos) {
            size_t ref_pos = line.find("ref=\"");
            if (ref_pos != std::string::npos) {
                std::string ref = line.substr(ref_pos + 5, line.find("\"", ref_pos + 5) - (ref_pos + 5));
                current_way.push_back(ref);
            }
        } else if (line.find("</way>") != std::string::npos) {
            if (current_way.size() >= 2) {
                ways.push_back(current_way);
            }
        }
    }
}


int main(int argc, char* argv[]) {
    std::string input_file;
    std::string output_file;

    if (argc != 3) {
        std::cout << "Usage: highways <input> <ouput> \n" ;
        return -1;
    }
    
    input_file =argv[1];
    output_file = argv[2];
    
    std::cout << "Using input file: " << input_file << std::endl;
    std::cout << "Using output file: " << output_file << std::endl;
    double min_lat, max_lat, min_lon, max_lon;

    parse_osm(input_file, min_lat, max_lat, min_lon, max_lon);

    double lon_range = max_lon - min_lon;
    double lat_range = max_lat - min_lat;
    if (lon_range == 0) lon_range = 1e-6;
    if (lat_range == 0) lat_range = 1e-6;

    double scale_x = WIDTH / lon_range;
    double scale_y = HEIGHT / lat_range;

    BMP bmp(WIDTH, HEIGHT);
    color black(0, 0, 0);

    for (const auto& way : ways) {
        for (size_t i = 1; i < way.size(); ++i) {
            if (!nodes.count(way[i - 1]) || !nodes.count(way[i])) continue;
            const Node& n1 = nodes[way[i - 1]];
            const Node& n2 = nodes[way[i]];
            int x1, y1, x2, y2;
            latlon_to_xy(n1.lat, n1.lon, x1, y1, min_lat, min_lon, scale_x, scale_y);
            latlon_to_xy(n2.lat, n2.lon, x2, y2, min_lat, min_lon, scale_x, scale_y);
            draw_line(bmp, x1, y1, x2, y2, black);
        }
    }

    bmp.write(output_file);
    std::cout << "Map saved to " << output_file << std::endl;
    return 0;
}
