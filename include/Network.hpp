#ifndef NETWORK_HPP_
# define NETWORK_HPP_

#include <fann.h>
#include <string>

class   Network
{
public:
    Network();
    Network(unsigned int num_input, unsigned int num_output,
        unsigned int num_layers = 3, unsigned int num_neurons_hidden = 3);
    Network(Network const &);
    ~Network();
    void    save(std::string);
    void    load(std::string);
    void    trainOnFile(std::string name, unsigned int max_epochs = 500000,
        unsigned int epochs_between_reports = 1000, float desired_error = 0.001);
    struct  fann *getANN(void) const;
    float   test(std::string);
private:
    struct  fann *ann;
};

#endif // NETWORK_HPP_
