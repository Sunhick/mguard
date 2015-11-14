/****************************************************
 *  memory guard header file
 *
 * Author : Sunil bn <sunhick@gmail.com>
 *****************************************************/
#ifndef EFENCE_H
#define EFENCE_H

#include "logger.h"

#include <string>
#include <iostream>

static const std::string version = "0.1.0";

static const std::string version_info[] =
  R"(
Memory fence v0.1.0
Copyright(c) 2015 Sunil <sunhick@gmail.com>
)";

void operator delete(void* ptr) noexcept;
void* operator new(size_t size, const char* file, size_t line, const char* func);
void  _delete(const char* file, size_t line, const char* func);
void operator delete(void* ptr) noexcept;

void en_debug_log(bool enable);

#define EN_DEBUG_LOG(enable) en_debug_log(enable)

#define new  new(__FILE__, __LINE__, __func__)
#define delete _delete(__FILE__, __LINE__, __func__), delete

#endif
