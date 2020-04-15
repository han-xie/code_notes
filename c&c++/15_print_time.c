/******************************************************************************
 * This is used to demonstrate how to calculate a human-readable Chinese
 * standard time.
 *
 * COMPILATION: gcc -o 15_print_time 15_print_time.c
 *
 * REFERENCE:
 * https://www.cnblogs.com/westfly/p/5139645.html
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>

/* calculate Chinese standard time */
void calc_cst_time(char *output)
{
  const int CST_TimeZone = 8;
  time_t raw_time;
  time ( &raw_time );
  /* Fast conversion from time_t to date */
  static const int kHoursInDay = 24;
  static const int kMinutesInHour = 60;
  static const int kDaysFromUnixTime = 2472632;
  static const int kDaysFromYear = 153;
  static const int kMagicUnkonwnFirst = 146097;
  static const int kMagicUnkonwnSec = 1461;
  int log_year, log_month, log_mday, log_hour, log_min, log_sec;
  log_sec  =  raw_time % kMinutesInHour;
  int i    = (raw_time/kMinutesInHour);
  log_min  = i % kMinutesInHour; //nn
  i /= kMinutesInHour;
  log_hour = (i + CST_TimeZone) % kHoursInDay; // hh
  log_mday = (i + CST_TimeZone) / kHoursInDay;
  int a = log_mday + kDaysFromUnixTime;
  int b = (a*4  + 3)/kMagicUnkonwnFirst;
  int c = (-b*kMagicUnkonwnFirst)/4 + a;
  int d =((c*4 + 3) / kMagicUnkonwnSec);
  int e = -d * kMagicUnkonwnSec;
  e = e/4 + c;
  int m = (5*e + 2)/kDaysFromYear;
  log_mday = -(kDaysFromYear * m + 2)/5 + e + 1;
  log_month = (-m/10)*12 + m + 2 + 1;
  log_year = b*100 + d  - 6700 + (m/10) + 1900;
  sprintf(output, "%04d-%02d-%02d %02d:%02d:%02d",
    log_year, log_month, log_mday, log_hour, log_min, log_sec);
}

int main() {
  char time[20];
  memset(time, 0x00, sizeof(char) * 20);
  calc_cst_time(time);
  puts(time);
}
