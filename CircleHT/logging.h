#pragma once

#include <iostream>

#ifdef _DEBUG
#define TRACE_DEBUG(a, ...) do{printf("D, %s(%d), %s", __FILE__, __LINE__, a);printf(__VA_ARGS__);printf("\n");}while(0)
#else
#define TRACE_DEBUG(a, ...) do {} while (false)
#endif