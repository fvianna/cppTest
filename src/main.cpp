#include <iostream>
#include <filesystem>

// Generated by CMake
#include "config.hpp"

int main()
{
    std::string input;
    std::cout << "Fala, galera!" << std::endl;
    std::cin >> input;

    std::filesystem::path p{"/"};
    const double value = std::stod(input);
    std::cout << "Número fornecido: " << value << std::endl;
    std::cout << "Versão brasileira " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
}