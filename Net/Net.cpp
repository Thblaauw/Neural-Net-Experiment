#pragma once

#include "Net.h"

#include <cassert>

Net::Net(const std::vector<unsigned> &topology) {
	unsigned num_layers = topology.size();
	for (unsigned layer_num = 0; layer_num < num_layers; ++layer_num) {
		m_layer.push_back(Layer());
		unsigned output_num = layer_num == topology.size() - 1 ? 0 : topology[layer_num + 1];
		//after the creation of the layer, the neurons have to be individually created
		for (unsigned neuron_num = 0; neuron_num <= topology[layer_num]; ++neuron_num) {
			m_layer.back().push_back(Neuron(output_num));
		}
	}
}

void Net::feed_forward(const std::vector<double> &input_vals) {
	assert(input_vals.size() == m_layer[0].size() - 1);
	//assign (latch) the input values into the input neurons

	for (unsigned i = 0; i < input_vals.size(); ++i) {
		m_layer[0][i].set_output_value(input_vals[i]);
	}

	//forward propagate
	for (unsigned layer_num = 1; layer_num < m_layer.size(); ++layer_num) {
		for (unsigned n = 0; n < m_layer[layer_num].size() - 1; ++n) {
			m_layer[layer_num][n].feed_forward(prev_layers);
		}
	}
}
