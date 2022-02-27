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
    float sum = 0;
    float max = 0;
    float min = 0 ;
    max = *(numberset+0);
    min = *(numberset+0);
    for(loopCntr_u16 = 0; loopCntr_u16 < setlength; loopCntr_u16++)
    {
      if(*(numberset+loopCntr_u16) > max)
      {
          max = *(numberset+loopCntr_u16);
      }
      if(*(numberset+loopCntr_u16) < min)
      {
          min = *(numberset+loopCntr_u16);
      }
        sum = sum + *(numberset+loopCntr_u16);
    }
    if( setlength != 0 )
    {
     s.average = sum/setlength;
     s.max = max;
     s.min = min;
    }
    else
    {
     s.average = 0;
     s.max = 0;
     s.min = 0;
    }
    
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
