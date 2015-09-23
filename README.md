# object-neural-network
Object oriented neural network library based on FANN
Basically this library is exactly the same as FANN with object implementation.

## Getting Started
You need the FANN library installed on your computer in order to use object-neural-network.

Basic test file to get you started:
```cpp
#include "Network.hpp"
#include <iostream>

int main()
{
    Network net(2, 1);

    net.trainOnFile("xor.data");
    std::cout << net.test("xor.data") << std::endl;
    net.save("test-network.net")
    return (EXIT_SUCCESS);
}
```

## What is implemented ?
- Constructor / Destructor (of Network)
- Train on data file
- Saving / Loading network
- Testing in data file
