#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
	struct Stats s;
	s.average = 0;
	s.min = 0;
	s.max = 0;
	float average = 0;
	if(setlength > 0)
	{
		average = s.min = s.max = *numberset;

		for(int i=1; i<=setlength-1; i++)
		{
			average = average + numberset[i];
			if(s.min > numberset[i])
				s.min = numberset[i];
			if(s.max < numberset[i])
				s.max = numberset[i];
		}
		s.average = average / setlength;
		printf("minimum value in numberset array is : %d",s.min);
		printf("maximum value in numberset array is : %d",s.max);
		printf("average value in numberset array is : %d",s.average);
	}
	else
	{
	    s.average = NAN;
		s.min = NAN;
		s.max = NAN;	
	}
	return s;

}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(void) {
	emailAlertCallCount++;
}
void ledAlerter(void) {
	ledAlertCallCount++;
}

check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats){
	if (computedStats.max > maxThreshold) {
		alerters[0]();
		alerters[1]();
}
