#pragma once

#include <iostream>

#ifdef _DEBUG
#define DEBUG_LOG(str) do { std::cout << str << std::endl; } while (false)
#else
#define DEBUG_LOG(str) do {} while (false)
#endif