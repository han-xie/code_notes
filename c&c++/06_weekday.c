/* This program shows the weekday of a certain date.
 * It is a small program I wrote in the cource of "C Programming" in 2010.
 * 
 * COMPILATION: gcc -o 06_weekday 06_weekday.c
 */

#include<stdio.h>
int main()
{
	int year,month,day,year_i,sum=0,i;
	printf("Please input the date in the following form:'YEAR.MONTH.DAY'\n");
	scanf("%d.%d.%d",&year,&month,&day);
	switch(month)
	{   case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:if(day>31){printf("The date does not exist,please check.\n");goto end;}else break;
		case 4:
		case 6:
		case 9:
		case 11:if(day>30){printf("The date does not exist,please check.\n");goto end;}else break;
	     case 2:{   if((year%400==0)||(year%100!=0&&year%4==0))
		                         {if(day>29){printf("The date does not exist,please check.\n");goto end;}
							  else break;
		                         }
					    else if(day>28){printf("The date does not exist,please check.\n");goto end;}
					           else break;
				}
		default:{printf("The date does not exist,please check.\n");goto end;}
	}		
	if(year>2010)
	{     for(year_i=2010;year_i<year;year_i++)
		    {   if((year_i%400==0)||(year_i%100!=0&&year_i%4==0))sum+=366;
			    else sum+=365;
		     }
	        /*循环体，计算出此年份1月1日与2010年1月1日相差多少天*/
	     if(month==1)sum+=(day-1);
		if(month==2)sum+=(31+day-1);
		if(month>2)
			{ if((year_i%400==0)||(year_i%100!=0&&year_i%4==0))sum+=(31+29);
				else sum+=(31+28);
			}
		switch(month)
		{    case 3:sum+=(day-1);break;
			case 4:sum+=(31+day-1);break;
			case 5:sum+=(31+30+day-1);break;
			case 6:sum+=(31+30+31+day-1);break;
			case 7:sum+=(31+30+31+30+day-1);break;
			case 8:sum+=(31+30+31+30+31+day-1);break;
			case 9:sum+=(31+30+31+30+31+31+day-1);break;
			case 10:sum+=(31+30+31+30+31+31+30+day-1);break;
			case 11:sum+=(31+30+31+30+31+31+30+31+day-1);break;
			case 12:sum+=(31+30+31+30+31+31+30+31+30+day-1);break;
		}
		/*计算月份差值*/
		i=sum%7;
	}/*完成2010年之后的时间是星期几计算*/
	if(year==2010)
	{        switch(month)
		{
			 case 1:sum+=(day-1);break;
			 case 2:sum+=(31+day-1);break;
			 case 3:sum+=(31+28+day-1);break;
			 case 4:sum+=(31+28+31+day-1);break;
			 case 5:sum+=(31+28+31+30+day-1);break;
			 case 6:sum+=(31+28+31+30+31+day-1);break;
			 case 7:sum+=(31+28+31+30+31+30+day-1);break;
			 case 8:sum+=(31+28+31+30+31+30+31+day-1);break;
			 case 9:sum+=(31+28+31+30+31+30+31+31+day-1);break;
			 case 10:sum+=(31+28+31+30+31+30+31+31+30+day-1);break;
			 case 11:sum+=(31+28+31+30+31+30+31+31+30+31+day-1);break;
			 case 12:sum+=(31+28+31+30+31+30+31+31+30+31+30+day-1);break;
		}
	     i=sum%7;
	}
	/*完成2010年各日期是星期几的计算*/
	if(year<2010)
	{  for(year_i=2009;year_i>year;year_i--)
		{if((year_i%400==0)||(year_i%100!=0&&year_i%4==0))sum+=366;
			else sum+=365;
		}
		switch(month)
		{
			case 12:sum+=(31-day+1);break;
			case 11:sum+=(31+30-day+1);break;
			case 10:sum+=(31+30+31-day+1);break;
			case 9:sum+=(31+30+31+30-day+1);break;
			case 8:sum+=(31+30+31+30+31-day+1);break;
			case 7:sum+=(31+30+31+30+31+31-day+1);break;
			case 6:sum+=(31+30+31+30+31+31+30-day+1);break;
			case 5:sum+=(31+30+31+30+31+31+30+31-day+1);break;
			case 4:sum+=(31+30+31+30+31+31+30+31+30-day+1);break;
			case 3:sum+=(31+30+31+30+31+31+30+31+30+31-day+1);break;
		}
		if(month==2||month==1)
		{sum+=(31+30+31+30+31+31+30+31+30+31);
			if((year_i%400==0)||(year_i%100!=0&&year_i%4==0))goto run;
			else goto ping;
			run:switch(month)
					{case 2:sum+=(29-day+1);break;
						case 1:sum+=(29+31-day+1);break;
					}
				goto stop;
			ping:switch(month)
					{case 2:sum+=(28-day+1);break;
						case 1:sum+=(28+31-day+1);break;
					}
				goto stop;
		     stop:;
		}
		i=sum%7;
		i=7-i;
		i=i%7;
	}
	     switch(i)
	     {
		case 0:printf("Friday");break;
		case 1:printf("Saturday");break;
		case 2:printf("Sunday");break;
		case 3:printf("Monday");break;
		case 4:printf("Tuesday");break;
	     case 5:printf("Wednesday");break;
	     case 6:printf("Thursday");break;
		}
		/*最终输出部分*/
		putchar('\n');
	end:	return 1;

}
