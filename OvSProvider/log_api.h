
#ifndef LOG_API
#define LOG_API

void userspace_err_log(char*);
void userspace_warn_log(char*);
void userspace_info_log(char*);
void userspace_emer_log(char*);
void userspace_dbg_log(char*);

void datapath_err_log(char*);
void datapath_warn_log(char*);
void datapath_info_log(char*);
void datapath_emer_log(char*);
void datapath_dbg_log(char*);

#endif

