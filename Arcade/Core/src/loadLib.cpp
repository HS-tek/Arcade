/*
** EPITECH PROJECT, 2021
** loadLib
** File description:
** Arcade
*/

#include "../include/loadLib.hpp"

loadLib::loadLib() {}

loadLib::~loadLib()
{
}

void loadLib::load(std::string path)
{
    this->handler = dlopen(path.c_str(), RTLD_LAZY);
    if (this->handler == nullptr) {
        std::cerr << dlerror() << std::endl;
        exit(84);
    }
}

void loadLib::closeLib()
{
    dlclose(this->handler);
}

void *loadLib::getLibFunc(std::string name)
{
    void *func = dlsym(this->handler, name.c_str());
    return func;
}

bool loadLib::LibType(std::string name)
{
    return getLibFunc("create" + name) != nullptr;
}