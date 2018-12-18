#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include <jmorecfg.h>

void syscall_init (void);
void Call_Halt();
void Call_EXIT();
void Call_EXEC();
boolean check_arguemnts(void);


#endif /* userprog/syscall.h */
