#include <stdio.h>

int
main (void)
{
double initial_balance = 500;
double monthly_min = 35;
double APR = 18;
double DPR = APR/36500;
int month = 9;
int cycle;
double interest;
double balance=initial_balance;
double payment;
int days;
double total;
printf("Cycle\tMonth\tIntrst  Payment Balance\n");
while (balance>=35){
  if (month==12)
    month = 12;
  else
    month = month%12;
  if (month==4 || month==6 || month==9 || month==11)
    days = 30;
  else if (month==2)
    days = 28;
  else
    days = 31;
  interest = DPR * days * balance;
  payment = monthly_min;
  balance = balance - payment + interest;
  printf("%4d\t%4d\t$%.2lf\t$%.2lf\t$%.2lf\n", cycle, month, interest, payment, balance);
  cycle++;
  month++;
}
if (month==12)
  month = 12;
else
  month = month%12;
if (month==4 || month==6 || month==9 || month==11)
  days = 30;
else if (month==2)
  days = 28;
else
  days = 31;
interest = DPR * days * balance;
payment = interest + balance;
balance = balance + interest - payment;
printf("%4d\t%4d\t$%.2lf\t$%.2lf\t$%.2lf\n", cycle, month, interest, payment, balance);
total = cycle * monthly_min + payment;
cycle++;
printf("After %d months, you paid $%.2lf on an initial balance of %.2lf\n",cycle, total, initial_balance);
}
