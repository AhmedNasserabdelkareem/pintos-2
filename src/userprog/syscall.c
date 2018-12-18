#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include <src/devices/shutdown.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "process.h"
//TODO NASSER GET ARGUEMENTS AND MAP IT TO ESP TO USE IT.
static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  //MBY AHMED NASSER
  //IMPLEMENT SWITCH TO CHOOSE SYSTEM CALL DEPEND ON CODES
  // WE need To check Arguements and Mapping them using esp
  //TODO HESHAM
  switch (*(int *) f->esp){
    case  SYS_HALT : {
      if(check_arguemnts()) {
        Call_Halt();
      }
      break;
    }
    case  SYS_EXIT :{
      if (check_arguemnts()) {
        //Call_EXIT();
      }
      break;
    }
    case  SYS_EXEC :{
      if (check_arguemnts()) {
        //Call_EXEC();
      }
      break;
    }
  }
  printf ("system call!\n");
  thread_exit ();
}
//MBY NASSER
void Call_Halt (void){
  shutdown_power_off();
};

void Call_EXIT (int status){
  printf ("%s: exit(%d)\n",thread_current()->name,status);
  //WE NEED TO CLOSE USER PROGRAM SO WE NEED TO GET OPENING THREADS WORKING NOW

  thread_exit();
};
//TODO NASSER CHECK THIS WE NEED TO EDIT PARAMETERS FOR THIS FUNCTION IN PROCESS.C
//Implement this functionality, by extending process_execute()
// so that instead of simply taking a program file name as its argument,
// it divides it into words at spaces. The first word is the program name,
// the second word is the first argument, and so on.
// That is, process_execute("grep foo bar") should run grep passing two arguments foo and bar.
pid_t Call_EXEC (const char *cmd_line){
  return process_execute(cmd_line);
};
boolean check_arguemnts (){

}
