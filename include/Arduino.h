#ifndef Arduino_h
#define Arduino_h

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "WString.h"
#include "HeatingInterval.h"

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define DEC 1

typedef unsigned char uint8_t;
typedef uint8_t boolean;
typedef uint8_t byte;

void pinMode(uint8_t a, uint8_t b);
void digitalWrite(uint8_t a, uint8_t b);
int digitalRead(uint8_t a);
int analogRead(uint8_t a);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);

void delay(unsigned long);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);

int abs(int i);

struct SerialPrint
{
/*  void print(std::string str);
  void println(std::string str);
  void println(char* e, int dataType);
  void println(unsigned char e, int dataType);
  void println(RadiantHeat::Enums::HeatingInterval::Enum e, int dataType);
//  void println(std::string str, int dataType);*/
//    size_t print(const String &);
    size_t print(const char[]) { }
    size_t print(char) { }
    size_t print(unsigned char, int = DEC) { }
    size_t print(int, int = DEC) { }
    size_t print(unsigned int, int = DEC) { }
    size_t print(long, int = DEC) { }
    size_t print(unsigned long, int = DEC) { }
    size_t print(double, int = 2) { }

//    size_t println(const String &s);
    size_t println(const char[]) { }
    size_t println(char) { }
    size_t println(unsigned char, int = DEC) { }
    size_t println(int, int = DEC) { }
    size_t println(unsigned int, int = DEC) { }
    size_t println(long, int = DEC) { }
    size_t println(unsigned long, int = DEC) { }
    size_t println(double, int = 2) { }
//    size_t println(const Printable&);
    size_t println(void) { }
};
extern SerialPrint Serial;


#endif
