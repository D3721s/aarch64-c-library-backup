#include "tlog.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    tlog_log *log = NULL;

    /* init and output log message */
    tlog_init("example.log", 1024 * 1024, 8, 0, TLOG_SCREEN_COLOR);
    tlog_setlevel(TLOG_DEBUG);
    tlog(TLOG_DEBUG, "This is a debug message.\n");
    tlog(TLOG_INFO, "This is a log message.\n");
    tlog(TLOG_NOTICE, "This is a notice message.\n");
    tlog(TLOG_WARN, "This is a warn message.\n");
    tlog(TLOG_ERROR, "This is a error message.\n");
    tlog(TLOG_FATAL, "This is a fatal message.\n");

    /* c++ cout style log */
    tlog_info << "This is a c++ style log.\n";
    
    /* open another log file, and output message*/
    log = tlog_open("another.log", 1024 * 1024, 8, 0, TLOG_SEGMENT);
    tlog_printf(log, "This is a separate log stream\n");
    /* c++ style log */
    tlog_out(log) << "This is a separate c++ log stream\n"; 
    
    /* close log stream */
    tlog_close(log);

    /* flush pending message, and exit tlog */
    tlog_exit();
    return 0;
}
