#include "skrivarn.h"
#include <stdarg.h>
#include <time.h>

#define ANSI_COLOR_FG(code) "\x1b[38;5;" code "m"

#define START "\x1b["
#define END "m"

#define SKRIVARN_TRACE_FG START "37" END

#define SKRIVARN_INFO_FG START "90" END
#define SKRIVARN_INFO_BG START "107" END

#define SKRIVARN_WARN_FG START "90" END
#define SKRIVARN_WARN_BG START "103" END

#define SKRIVARN_ERROR_BG START "101" END

#define SKRIVARN_FATAL_BG START "TODO" END

#define RESET "\x1b[0m"

static void *output = NULL;

static const char *loglevel_to_string(int level) {
    switch (level) {
        case SKRIVARN_TRACE:
            return SKRIVARN_TRACE_FG " TRACE " RESET " ";
        case SKRIVARN_INFO:
            return SKRIVARN_INFO_BG SKRIVARN_INFO_FG " INFO  " RESET " ";
        case SKRIVARN_WARN:
            return SKRIVARN_WARN_FG SKRIVARN_WARN_BG " WARN  " RESET " ";
        case SKRIVARN_ERROR:
            return SKRIVARN_ERROR_BG " ERROR " RESET " ";
        case SKRIVARN_FATAL:
            return SKRIVARN_FATAL_BG " FATAL " RESET " ";
    }
    return "NULL";
}

void __skrivarn_log_impl(int level, const char *file_name, const char *func_name, int line, const char *format, ...) {
    va_list args;
    va_start(args, format);

    time_t t = time(NULL);
    struct tm *tmp;

    tmp = localtime(&t);

    char buf[16];
    strftime(buf, 16, "%H:%M:%S", tmp);

    output = stdout;

    if (level == SKRIVARN_ERROR)
        output = stderr;

    fprintf(output, "\x1b[90m" "%s " "\x1b[0m", buf);
    fprintf(output,
            "%s"
            "\x1b[90m" "%s:%d" "\x1b[0m"
            "  ",
            loglevel_to_string(level),
            file_name,
            line);
    fprintf(output, "\x1b[37m");
    vfprintf(output, format, args);
    fprintf(output, "\x1b[0m\n");

    fflush(output);

    va_end(args);
}
