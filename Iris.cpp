#include "LSP/Server.hpp"
#include <string>

int main(int argc, char** argv)
{
    switch(argc)
    {
        case 2:
            if(std::string(argv[1]) == "stream")
                Iris::LSP::Process();
        break;
    }
}