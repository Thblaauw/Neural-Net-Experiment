#pragma once

#include <vector>
#include <cstdlib>

struct Connection {
	double weight;
	double delta_weight;
};

class Neuron {
public:
	Neuron(unsigned output_num);

private:
	static double random_weight(void) { return rand() / double(RAND_MAX); }
	double m_output_val;
	std::vector<Connection> m_output_weights;
};
 
typedef std::vector<Neuron> Layer;

class Net{
private:
	Net(const std::vector<unsigned> &topology);
	void feed_forward(const std::vector<double> &input_vals);
	void back_propagation(const std::vector<double> &target_vals);
	void get_results(std::vector<double> &results_vals) const;

public:

	std::vector<Layer> m_layer; // m_layer[layer_num][neuron_num]
};