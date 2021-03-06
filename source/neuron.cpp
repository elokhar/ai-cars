#include "neuron.h"
#include <cmath>

Neuron::Neuron()
{
}

void Neuron::setInputsCount(int inputs_count)
{
	this->inputs_count = inputs_count;
}

int Neuron::getInputsCount()
{
	return inputs_count;
}

void Neuron::setInputs(double * inputs)
{
	this->inputs = inputs;
}

void Neuron::setWeights(double * weights)
{
	//this->weights = weights;
	this->weights = new double[inputs_count + 1];
	for (int i = 0; i < inputs_count + 1; i++)
	{
		this->weights[i] = weights[i];
	}
}

double Neuron::getOutput()
{
	return output;
}

void Neuron::activate()
{
	double sum = 0;
	for (int i = 0; i < inputs_count; i++)
	{
		sum += inputs[i] * weights[i];
	}
	sum += 10 * weights[inputs_count]; //add bias

	output = activationFunction(sum);
}

void Neuron::mutate(int weight_index, double weight_modification)
{
	weights[weight_index] = weights[weight_index] * weight_modification;
}

double Neuron::activationFunction(double t)
{
	double result = 1 / (1 + exp(-t));
	return result;
}
