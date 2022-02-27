#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int loopCntr_u16 = 0;
    for(loopCntr_u16 = 0; loopCntr_u16 < setlength; loopCntr_u16++)
    {
      if(numberset[loopCntr_u16] > numberset[loopCntr_u16 + 1])
      {
          s.max = numberset[loopCntr_u16];
      }
      else
      {
          s.min = numberset[loopCntr_u16];
      }
    }
    s.average = (s.max + s.min)/2;
    
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
int emailAlerter = 0;
int ledAlerter = 0;
