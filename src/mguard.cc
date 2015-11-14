/****************************************************
 *  mguard implementation file
 *
 * Author : Sunil bn <sunhick@gmail.com>
 *****************************************************/
#include "include/mguard.h"

#include <sstream>

#ifdef new
#undef new
#endif

#ifdef delete
#undef delete
#endif

using namespace diagnostics;

std::shared_ptr<logger> log = logger::get_logger();

void en_debug_log(bool enable)
{
  log->enable_debug = enable;
}

void* operator new(size_t size, const char* file, size_t line, const char* func)
{
  std::stringstream fmt;
  fmt << "new'd " << size << " bytes from " << file << "::" << func << " at " << line;
  log->debug(fmt.str());
  return  malloc(size);// new(size);
}

void operator delete(void* ptr) noexcept
{
  free(ptr);
}

void  _delete(const char* file, size_t line, const char* func)
{
  std::stringstream fmt;
  fmt << "free'd " << " bytes from " << file << "::" << func << " at " << line;
  log->debug(fmt.str());  
}
