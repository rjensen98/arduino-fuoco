/*
  time.c - low level time and date functions
  Copyright (c) Michael Margolis 2009

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  6  Jan 2010 - initial release
  12 Feb 2010 - fixed leap year calculation error
  1  Nov 2010 - fixed setTime bug (thanks to Korman for this)
*/


#include "Time.h"

static tmElements_t tm;          // a cache of time elements
static time_t       cacheTime;   // the time the cache was updated
static time_t       syncInterval = 300;  // time sync will be attempted after this many seconds

int hour() { // the hour now
  return hour(now());
}

int hour(time_t t) { // the hour for the given time
  return tm.Hour;
}

int hourFormat12() { // the hour now in 12 hour format
  return hourFormat12(now());
}

int hourFormat12(time_t t) { // the hour for the given time in 12 hour format
  if( tm.Hour == 0 )
    return 12; // 12 midnight
  else if( tm.Hour  > 12)
    return tm.Hour - 12 ;
  else
    return tm.Hour ;
}

uint8_t isAM() { // returns true if time now is AM
  return !isPM(now());
}

uint8_t isAM(time_t t) { // returns true if given time is AM
  return !isPM(t);
}

uint8_t isPM() { // returns true if PM
  return isPM(now());
}

uint8_t isPM(time_t t) { // returns true if PM
  return (hour(t) >= 12);
}

int minute() {
  return minute(now());
}

int minute(time_t t) { // the minute for the given time
  return tm.Minute;
}

int second() {
  return second(now());
}

int second(time_t t) {  // the second for the given time
  return tm.Second;
}

int day(){
  return(day(now()));
}

int day(time_t t) { // the day for the given time (0-6)
  return tm.Day;
}

int weekday() {   // Sunday is day 1
  return  weekday(now());
}

int weekday(time_t t) {
  return tm.Wday;
}

int month(){
  return month(now());
}

int month(time_t t) {  // the month for the given time
  return tm.Month;
}

int year() {  // as in Processing, the full four digit year: (2009, 2010 etc)
  return year(now());
}

int year(time_t t) { // the year for the given time
  return tmYearToCalendar(tm.Year);
}

/*============================================================================*/
/* functions to convert to and from system time */
/* These are for interfacing with time serivces and are not normally needed in a sketch */

// leap year calulator expects year argument as years offset from 1970
#define LEAP_YEAR(Y)     ( ((1970+Y)>0) && !((1970+Y)%4) && ( ((1970+Y)%100) || !((1970+Y)%400) ) )

static  const uint8_t monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31}; // API starts months from 1, this array starts from 0

time_t makeTime(tmElements_t &tm){
// assemble time elements into time_t
// note year argument is offset from 1970 (see macros in time.h to convert to other formats)
// previous version used full four digit year (or digits since 2000),i.e. 2009 was 2009 or 9

  int i;
  time_t seconds;

  // seconds from 1970 till 1 jan 00:00:00 of the given year
  seconds= tm.Year*(SECS_PER_DAY * 365);
  for (i = 0; i < tm.Year; i++) {
    if (LEAP_YEAR(i)) {
      seconds +=  SECS_PER_DAY;   // add extra days for leap years
    }
  }

  // add days for this year, months start from 1
  for (i = 1; i < tm.Month; i++) {
    if ( (i == 2) && LEAP_YEAR(tm.Year)) {
      seconds += SECS_PER_DAY * 29;
    } else {
      seconds += SECS_PER_DAY * monthDays[i-1];  //monthDay array starts from 0
    }
  }
  seconds+= (tm.Day-1) * SECS_PER_DAY;
  seconds+= tm.Hour * SECS_PER_HOUR;
  seconds+= tm.Minute * SECS_PER_MIN;
  seconds+= tm.Second;
  return seconds;
}
/*=====================================================*/
/* Low level system time functions  */

static time_t sysTime = 0;

time_t now(){
  return sysTime;
}

void setTime(time_t t){
  sysTime = t;
}

void  setTime(int hr,int min,int sec,int dy, int mnth, int yr){
 // year can be given as full four digit year or two digts (2010 or 10 for 2010);
 //it is converted to years since 1970
  if( yr > 99)
      yr = yr - 1970;
  else
      yr += 30;
  tm.Year = yr;
  tm.Month = mnth;
  tm.Day = dy;
  tm.Hour = hr;
  tm.Minute = min;
  tm.Second = sec;
  setTime(makeTime(tm));
  tm.Wday = dayOfWeek(now());  // added 2014-12-04 by Ryan Jensen
}

void adjustTime(long adjustment){
  sysTime += adjustment;
}
