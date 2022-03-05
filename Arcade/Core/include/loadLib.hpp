/*
** EPITECH PROJECT, 2021
** loadLib
** File description:
** Arcade
*/

#ifndef LOADLIB_HPP
#define LOADLIB_HPP

#include <string>
#include <dlfcn.h>
#include <iostream>
#include "Core.hpp"

class loadLib
{
public:
    loadLib();
    ~loadLib();

    void    load(std::string path);
    void    closeLib();
    void *  getLibFunc(std::string name);
    bool    LibType(std::string name);
private:
    void *handler;
};

#endif
