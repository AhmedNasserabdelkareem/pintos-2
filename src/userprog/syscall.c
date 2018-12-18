#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include <src/devices/shutdown.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

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
  switch ((int)f){
    case  SYS_HALT : {
      if(check_arguemnts()) {
        Call_Halt();
      }
      break;
    }
    case  SYS_EXIT :{
      if (check_arguemnts()) {
        Call_EXIT();
      }
      break;
    }
    case  SYS_EXEC :{
      if (check_arguemnts()) {
        Call_EXEC();
      }
      break;
    }
  }
  printf ("system call!\n");
  thread_exit ();
}
void Call_Halt (){
  shutdown_power_off();
};

void Call_EXIT (){
};
void Call_EXEC (){
};
boolean check_arguemnts (){

}
