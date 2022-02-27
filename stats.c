#include "stats.h"
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
alerter_funcptr emailAlerter = 0;
alerter_funcptr ledAlerter = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int loopCntr_u16 = 0;
    int sum = 0;
    for(loopCntr_u16 = 0; loopCntr_u16 < setlength; loopCntr_u16++)
    {
      if(*(numberset+loopCntr_u16) > *(numberset + (loopCntr_u16 + 1)))
      {
          s.max = *(numberset+loopCntr_u16);
      }
      else
      {
          s.min = *(numberset+loopCntr_u16);
      }
        sum = sum + *(numberset+loopCntr_u16);
    }


        s.average = (float)sum/setlength;
    
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
   if(computedStats.max > maxThreshold)
   {  
       emailAlertCallCount = 1;
       ledAlertCallCount = 1;
   }
}
