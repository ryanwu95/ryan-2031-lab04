#include <stdio.h>
#include <wiringPi.h>
#include <time.h> 
#include "ifttt.h"

void init(){
    wiringPiSetup () ;
    pinMode(0, INPUT);
    pinMode(1,OUTPUT);
    pinMode(2,OUTPUT);
}
int main(int argc, char *argv[])
{
    init();
while(1) {
printf("Waiting for reset\n");

while(digitalRead(0) == 0){
     digitalWrite(2,LOW);
    digitalWrite(1,HIGH);
    printf("Waiting for event\n");
    delay(1000);
    digitalWrite(1,LOW);
     delay(500);
}

while(digitalRead(0) == 1) {
    time_t rawtime;
    struct tm * timeinfo;
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    delay(1000);
    digitalWrite(2,LOW);
    delay(500);
    printf("Alarm\n");
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/214010078", "pi", "hello world", "call the police");
}

}
/*NOTREACHED*/
return 0 ;
}


