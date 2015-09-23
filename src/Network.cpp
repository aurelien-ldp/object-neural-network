#include "Network.hpp"

// Create the ANN with SIGMOID_SYMMETRIC function
Network::Network()
{
    ann = nullptr;
}

Network::Network(unsigned int num_input, unsigned int num_output,
    unsigned int num_layers, unsigned int num_neurons_hidden)
{
    this->ann = fann_create_standard(num_layers, num_input,
        num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(this->ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(this->ann, FANN_SIGMOID_SYMMETRIC);
}

Network::Network(Network const &net)
{
    if (this->ann)
        fann_destroy(this->ann);
    ann = net.getANN();
}

Network::~Network()
{
    if (this->ann)
        fann_destroy(this->ann);
}

void    Network::save(std::string name)
{
    fann_save(this->ann, name.c_str());
}

void    Network::load(std::string name)
{
    this->ann = fann_create_from_file(name.c_str());
}

void    Network::trainOnFile(std::string name, unsigned int max_epochs,
    unsigned int epochs_between_reports, float desired_error)
{
    fann_train_on_file(this->ann, name.c_str(), max_epochs,
        epochs_between_reports, desired_error);
}

struct  fann*   Network::getANN(void) const
{
    return (this->ann);
}

// Test with the file "filename" and return the Mean Square Error
float    Network::test(std::string filename)
{
    struct fann_train_data *data = fann_read_train_from_file(filename.c_str());
    fann_reset_MSE(ann);
    fann_test_data(ann, data);
    fann_destroy_train(data);
    return (fann_get_MSE(ann));
}
