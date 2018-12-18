#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include <jmorecfg.h>
#include <src/lib/user/syscall.h>

void syscall_init (void);
void Call_Halt(void);
void Call_EXIT(int status);
pid_t Call_EXEC(const char *cmd_line);
boolean check_arguemnts(void);


#endif /* userprog/syscall.h */
