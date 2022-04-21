#pragma once

#include <stdio.h>

enum { SKRIVARN_TRACE, SKRIVARN_INFO, SKRIVARN_WARN, SKRIVARN_ERROR, SKRIVARN_FATAL };

#define SKRIVARN_ENABLED

#ifdef SKRIVARN_ENABLED

#define skrivarn_trace(format) __skrivarn_log_impl(SKRIVARN_TRACE, __FILE__, __FUNCTION__, __LINE__, format)
#define skrivarn_tracef(format, ...) __skrivarn_log_impl(SKRIVARN_TRACE, __FILE__, __FUNCTION__, __LINE__, format, __VA_ARGS__)

#define skrivarn_info(format) __skrivarn_log_impl(SKRIVARN_INFO, __FILE__, __FUNCTION__, __LINE__, format)
#define skrivarn_infof(format, ...) __skrivarn_log_impl(SKRIVARN_INFO, __FILE__, __FUNCTION__, __LINE__, format, __VA_ARGS__)

#define skrivarn_warn(format) __skrivarn_log_impl(SKRIVARN_WARN, __FILE__, __FUNCTION__, __LINE__, format)
#define skrivarn_warnf(format, ...) __skrivarn_log_impl(SKRIVARN_WARN, __FILE__, __FUNCTION__, __LINE__, format, __VA_ARGS__)

#define skrivarn_error(format) __skrivarn_log_impl(SKRIVARN_ERROR, __FILE__, __FUNCTION__, __LINE__, format)
#define skrivarn_errorf(format, ...) __skrivarn_log_impl(SKRIVARN_ERROR, __FILE__, __FUNCTION__, __LINE__, format, __VA_ARGS__)

#else

#define skrivarn_trace(format)
#define skrivarn_tracef(format, ...)

#define skrivarn_info(format)
#define skrivarn_infof(format, ...)

#define skrivarn_warn(format)
#define skrivarn_warnf(format, ...)

#define skrivarn_error(format)
#define skrivarn_errorf(format, ...)

#endif

void __skrivarn_log_impl(int level, const char *file_name, const char *func_name, int line, const char *format, ...);
