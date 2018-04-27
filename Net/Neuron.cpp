#pragma once 

#include "Net.h"

Neuron::Neuron(unsigned output_num) {
	for (unsigned c = 0; c < output_num; ++c) {
		m_output_weights.push_back(Connection());
		m_output_weights.back().weight = random_weight();
	}
}