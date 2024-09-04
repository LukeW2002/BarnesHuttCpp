#include "../include/simulation.hpp"
#include "../include/debug.hpp"
#include "../include/constants.hpp"
#include <iostream>
#include <stdexcept>
#include <argp.h>

struct arguments {
    int width;
    int height;
    int numPoints;
    double G;
    double delta;
    double dt;
};

static struct argp_option options[] = {
    {"width", 'w', "WIDTH", 0, "Screen width"},
    {"height", 'h', "HEIGHT", 0, "Screen height"},
    {"numPoints", 'n', "NUM_POINTS", 0, "Number of points"},
    {"G", 'g', "G", 0, "Gravitational constant"},
    {"delta", 'd', "DELTA", 0, "Delta value"},
    {"dt", 't', "DT", 0, "Time step"},
    {0}
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = (struct arguments *)state->input;
    switch (key) {
        case 'w': arguments->width = std::stoi(arg); break;
        case 'h': arguments->height = std::stoi(arg); break;
        case 'n': arguments->numPoints = std::stoi(arg); break;
        case 'g': arguments->G = std::stod(arg); break;
        case 'd': arguments->delta = std::stod(arg); break;
        case 't': arguments->dt = std::stod(arg); break;
        default: return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = { options, parse_opt, 0, 0 };

int main(int argc, char* argv[]){
	try {
		LOG_INFO("Starting Nbody simulation");
		struct arguments arguments;
    arguments.width = Constants::width;
    arguments.height = Constants::height;
    arguments.numPoints = Constants::defaultNumPoints;
    arguments.G = Constants::G;
    arguments.delta = Constants::delta;
    arguments.dt = Constants::dt;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    int width = arguments.width;
    int height = arguments.height;
    int numPoints = arguments.numPoints;
    double G = arguments.G;
    double delta = arguments.delta;
    double dt = arguments.dt;
		
		LOG_INFO("Initializing simulation with dimensions %dx%d and %d points", width, height, numPoints);

		Simulation sim(width, height, numPoints);
    sim.run();

    LOG_INFO("Simulation completed successfully");

		return 0;
	}
	catch(const std::exception& e){
		LOG_ERROR("An error Occured: %s", e.what());
		std::cerr << "An error occured: " << e.what() << std::endl;
		return 1;
	}
}

