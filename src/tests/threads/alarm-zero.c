/* Tests timer_sleep(0), which should return immediately. */

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"

void
test_alarm_zero (void) 
{
  printf("Ho ten: Duong Van Hao\n");
  printf("MSSV:   20213906");
  timer_sleep (0);
  pass ();
}
