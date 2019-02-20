#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "OrangePi.h"
#include <wiringPi.h>

#ifdef CONFIG_ORANGEPI_PC2
int physToWpi[64] =
{
    -1,        // 0
    -1,  -1,   // 1, 2
    8,   -1,   // 3, 4
    9,   -1,   // 5, 6
    7,   15,   // 7, 8
    -1,  16,   // 9, 10
    0,    1,   //11, 12
    2,   -1,   //13, 14
    3,    4,   //15, 16
    -1,   5,   //17, 18
    12,  -1,   //19, 20
    13,   6,   //21, 22
    14,  10,   //23, 24
    -1,  11,   //25, 26
    30,  31,   //27, 28
    21,  -1,   //29, 30
    22,  26,   //31, 32
    23,  -1,   //33, 34
    24,  27,   //35, 36
    25,  28,   //37, 38
    -1,  29,   //39, 40
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
    -1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};

char *physNames[64] =
{
    NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "  GPIO.7", "TxD3    ",
 "      0v", "RxD3    ",
 "    RxD2", "GPIO.1  ",
 "    TxD2", "0v      ",
 "    CTS2", "GPIO.4  ",
 "    3.3v", "GPIO.5  ",
 "    MOSI", "0v      ",
 "    MISO", "RTS2    ",
 "    SCLK", "CE0     ",
 "      0v", "GPIO.11 ",
 "   SDA.1", "SCL.1   ",
 " GPIO.21", "0v      ",
 " GPIO.22", "RTS1    ",
 " GPIO.23", "0v      ",
 " GPIO.24", "CTS1    ",
 " GPIO.25", "TxD1    ",
 "      0v", "RxD1    ",
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
  "GPIO.17", "GPIO.18",
  "GPIO.19", "GPIO.20",
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_2G_IOT
char *physNames[64] =
{
    NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "  GPIO.7", "TxD2    ",
 "      0v", "RxD2    ",
 "    RxD1", "GPIO.1  ",
 "    TxD1", "0v      ",
 "    CTS1", "GPIO.4  ",
 "    3.3v", "GPIO.5  ",
 " SPI2_DI", "0v      ",
 "SPI2_DIO", "RTS1    ",
 "SPI2_CLK", "SPI2_CS0",
 "      0v", "SPI2_CS1",
 "   SDA.1", "SCL.1   ",
 " GPIO.21", "0v      ",
 " GPIO.22", "RTS2    ",
 " GPIO.23", "0v      ",
 " GPIO.24", "CTS2    ",
 " GPIO.25", "SCL.2   ",
 "      0v", "SDA.2   ",
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};

int physToWpi[64] =
{
    -1,        // 0
    -1,  -1,   // 1, 2
    8,   -1,   // 3, 4
    9,   -1,   // 5, 6
    7,   15,   // 7, 8
    -1,  16,   // 9, 10
    0,    1,   //11, 12
    2,   -1,   //13, 14
    3,    4,   //15, 16
    -1,   5,   //17, 18
    12,  -1,   //19, 20
    13,   6,   //21, 22
    14,  10,   //23, 24
    -1,  11,   //25, 26
    30,  31,   //27, 28
    21,  -1,   //29, 30
    22,  26,   //31, 32
    23,  -1,   //33, 34
    24,  27,   //35, 36
    25,  28,   //37, 38
    -1,  29,   //39, 40
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
    -1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};
#endif

#ifdef CONFIG_ORANGEPI_A64
char *physNames [64] =
{
  NULL,

 "    3.3v", "5v      ",
 "   SDA.1", "5V      ",
 "   SCL.1", "0v      ",
 "  GPIO.7", "S_TX    ",
 "      0v", "S_RX    ",
 "    RxD3", "GPIO.1  ",
 "    TxD3", "0v      ",
 "    CTS3", "GPIO.4  ",
 "    3.3v", "GPIO.5  ",
 "    MOSI", "0v      ",
 "    MISO", "RTS3    ",
 "    SCLK", "CE0     ",
 "      0v", "GPIO.11 ",
 "   SDA.2", "SCL.2   ",
 " GPIO.21", "0v      ",
 " GPIO.22", "RTS2    ",
 " GPIO.23", "0v      ",
 " GPIO.24", "CTS2    ",
 " GPIO.25", "TxD2    ",
 "      0v", "RxD2    ",
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
  "GPIO.17", "GPIO.18",
  "GPIO.19", "GPIO.20",
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};

int physToWpi [64] =
{
  -1,        // 0
  -1,  -1,   // 1, 2
   8,  -1,   // 3, 4
   9,  -1,   // 5, 6
   7,  15,   // 7, 8
  -1,  16,   // 9, 10
   0,   1,   //11, 12
   2,  -1,   //13, 14
   3,   4,   //15, 16
  -1,   5,   //17, 18
  12,  -1,   //19, 20
  13,   6,   //21, 22
  14,  10,   //23, 24
  -1,  11,   //25, 26
  30,  31,   //27, 28
  21,  -1,   //29, 30
  22,  26,   //31, 32
  23,  -1,   //33, 34
  24,  27,   //35, 36
  25,  28,   //37, 38
  -1,  29,   //39, 40
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
   -1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};
#endif

#ifdef CONFIG_ORANGEPI_H3
int physToWpi[64] =
{
	-1,		// 0
	-1, -1,	// 1, 2
	0, -1,  //3, 4
	1, -1,  //5, 6
	2, 3,  //7, 8
	-1, 4, //9,10
	5, 6, //11,12
	7, -1, //13,14
	8, 9, //15,16
	-1, 10, //17,18
	11, -1, //19,20
	12, 13, //21,22
	14, 15, //23, 24
	-1,  16,	// 25, 26

	17,	18,   //27, 28
	19,  -1,	//29, 30
	20,  21,	//31, 32
	22, -1, //33, 34
	23, 24, //35, 36
	25, 26, //37, 38
	-1, 27, //39, 40
	28, 29, //41, 42
	// Padding:

    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 56
	-1, -1, -1, -1, -1, -1, -1,	// ... 63
};

char *physNames[64] =
{
  NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "     PA6", "TxD3    ",
 "      0v", "RxD3    ",
 "    RxD2", "PD14    ",
 "    TxD2", "0v      ",
 "    CTS2", "PC04    ",
 "    3.3v", "PC07    ",
 "    MOSI", "0v      ",
 "    MISO", "RTS2    ",
 "    SCLK", "CE0     ",
 "      0v", "PA21    ",
 "   SDA.1", "SCL.1   ",
 "    PA07", "0v      ",
 "    PA08", "RTS1    ",
 "    PA09", "0v      ",
 "    PA10", "CTS1    ",
 "    PA20", "TxD1    ",
 "      0v", "RxD1    ",
 "    PA04", "PA05    ",
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
  	   NULL, NULL,
       NULL, NULL,
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_H3_ZEROPLUS2
int physToWpi [64] = //return wiringPI pin
{
  -1,       // 0
  -1, -1,   // 1, 2
   0, -1,  //3, 4
   1, -1,  //5, 6
   2, 3,  //7, 8
  -1, 4, //9,10
  5, 6, //11,12
  7, -1, //13,14
  8, 9, //15,16
  -1, 10, //17,18
  11, -1, //19,20
   12, 13, //21,22
  14, 15, //23, 24
  -1,  16,  // 25, 26

  -1, -1,   //27, 28
  -1, -1,  //29, 30
  -1, -1,  //31, 32
  -1, -1, //33, 34
  -1, -1, //35, 36
  -1, -1, //37, 38
  -1, -1, //39, 40
  -1, -1, //41, 42
// Padding:

  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
  -1, -1, -1, -1, -1, -1, -1,   // ... 63
};

char *physNames[64] =
{
      NULL,

  "    3.3v", "5v      ",
  "   SDA.0", "5v      ",
  "   SCL.0", "0v      ",
  "     PA6", "TxD2    ",
  "      0v", "RxD2    ",
  "   S-TWI", "PD11    ",
  "   S-SDA", "0v      ",
  "    CTS2", "SDA.1   ",
  "    3.3v", "SCL.1   ",
  "  MOSI.1", "0v      ",
  "  MISO.1", "RTS2    ",
  "  SCLK.1", "CS.1    ",
  "      0v", "PD14    ",

       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL,
};
#endif


#ifdef CONFIG_ORANGEPI_ZERO
int physToWpi [64] =
{
    -1,
    /* 24 Pin */
    -1, -1,   //1, 2
    0,  -1,   //3, 4
    1,  -1,   //5, 6
    2,   3, //7, 8
    -1,  4, //9, 10
    5,   6,   //11, 12
    7,  -1,  //13, 14
    8,   9,  //15, 16
    -1, 10,  //17, 18
    11, -1,   //19, 20
    12, 13,    //21, 22
    14, 15,   //23, 24
    
    /* 12 Pin */
    -1, -1,   //25, 26
    -1, -1,   //27, 28
    -1, 16,   //29, 30
    17, -1,   //31, 32
    -1, -1,   //33, 34
    -1, -1,   //35, 36
    
    /* UART0 Tx,Rx */
    18, 19,     //37, 38
    
    /* 39~63 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

char *physNames[64] =
{
      NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "  GPIO.2", "TxD1    ",
 "      0v", "RxD1    ",
 "    TxD2", "W1      ",
 "  GPIO.7", "0v      ",
 "  GPIO.8", "RTS1    ",
 "    3.3v", "CTS1    ",
 "    MOSI", "0v      ",
 "    MISO", "RxD2    ",
 "    SCLK", "CS      ",
    
      NULL, NULL,
      NULL, NULL,

       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_LITE2
int physToWpi [64] = 
{
	-1, 		  // 0
	-1, -1, 	  // 1, 2
	 0, -1,
	 1, -1, 	  
	 2,  3, 	  //7, 8
	-1,  4, 	  
	 5,  6, 	  //11, 12
	 7, -1, 	  
	 8,  9, 	  //15, 16
	-1, 10, 	  
	11, -1, 	  //19, 20
	12, 13, 	  
	14, 15, 	  //23, 24
	-1, 16, 	  // 25, 26
	
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
	-1, -1, -1, -1, -1, -1, -1,   // ... 63

};

char *physNames [64] = 
{
  	   NULL,

 "    3.3v", "5v      ",
 "   SDA.1", "5V      ",
 "   SCL.1", "0v      ",
 "    PWM1", "PD21    ",
 "      0v", "PD22    ",
 "    RxD3", "PC09    ",
 "    TxD3", "0v      ",
 "    CTS3", "PC08    ",
 "    3.3v", "PC07    ",
 "  MOSI.0", "0v      ",
 "  MISO.0", "RTS3    ",
 "  SCLK.0", "CE.0    ",
 "      0v", "PH03    ",

	   NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_3
int physToWpi [64] = 
{
	-1, 		  // 0
	-1, -1, 	  // 1, 2
	 0, -1,
	 1, -1, 	  
	 2,  3, 	  //7, 8
	-1,  4, 	  
	 5,  6, 	  //11, 12
	 7, -1, 	  
	 8,  9, 	  //15, 16
	-1, 10, 	  
	11, -1, 	  //19, 20
	12, 13, 	  
	14, 15, 	  //23, 24
	-1, 16, 	  // 25, 26
	
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
	-1, -1, -1, -1, -1, -1, -1,   // ... 63

};

char *physNames [64] = 
{
  	   NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "    PWM0", "PL02    ",
 "      0v", "PL03    ",
 "    RxD3", "PD18    ",
 "    TxD3", "0v      ",
 "    PL10", "PD15    ",
 "    3.3v", "PD16    ",
 "  MOSI.1", "0v      ",
 "  MISO.1", "PD21    ",
 "  SCLK.1", "CE.1    ",
 "      0v", "PL08    ",

	   NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL,
};
#endif


/*
 * ReadAll 
 */
void OrangePiReadAll(void)
{
    int pin;
	int tmp = wiringPiDebug;
    wiringPiDebug = FALSE;
#ifdef CONFIG_ORANGEPI_PC2
    printf (" +------+-----+----------+------+---+OrangePi PC2+---+---+------+---------+-----+--+\n");
#elif CONFIG_ORANGEPI_2G_IOT
    printf (" +-----+-----+----------+------+---+OrangePi 2G-IOT+---+---+------+---------+-----+--+\n");
#elif CONFIG_ORANGEPI_H3 || CONFIG_ORANGEPI_H3_ZEROPLUS2 
    printf (" +------+-----+----------+------+---+OrangePiH3+---+------+----------+-----+------+\n");
#elif CONFIG_ORANGEPI_ZERO
    printf (" +------+-----+----------+------+---+NanoPiNeo Air+---+---+------+---------+-----+--+\n");
#elif CONFIG_ORANGEPI_A64
    printf (" +------+-----+----------+------+---+OrangePi Win/Win+ +---+---+------+---------+-----+--+\n");
#elif CONFIG_ORANGEPI_LITE2 || CONFIG_ORANGEPI_3
    printf (" +------+-----+----------+------+---+OrangePiH6+---+------+----------+-----+------+\n");
#endif
    printf (" | GPIO | wPi |   Name   | Mode | V |  Physical  | V | Mode | Name     | wPi | GPIO |\n");
    printf (" +------+-----+----------+------+---+----+--+----+---+------+----------+-----+------+\n");

#ifdef CONFIG_ORANGEPI_H3
    for (pin = 1 ; pin <= 42 ; pin += 2)
#elif CONFIG_ORANGEPI_LITE2 || CONFIG_ORANGEPI_H3_ZEROPLUS2 || CONFIG_ORANGEPI_3
	for (pin = 1 ; pin <= 26 ; pin += 2)
#elif CONFIG_ORANGEPI_ZERO
    for (pin = 1 ; pin <= 24 ; pin += 2)
#endif
        readallPhys(pin);

    printf (" +------+-----+----------+------+---+----+--+----+---+------+----------+-----+------+\n");
    printf (" | GPIO | wPi |   Name   | Mode | V |  Physical  | V | Mode | Name     | wPi | GPIO |\n");
#ifdef CONFIG_ORANGEPI_PC2
    printf (" +------+-----+----------+------+---+OrangePi PC2+---+------+----------+-----+-----+\n");
#elif CONFIG_ORANGEPI_2G_IOT
    printf (" +------+-----+----------+------+---+OrangePi 2G-IOT+---+------+----------+-----+-----+\n");
#elif CONFIG_ORANGEPI_H3 || CONFIG_ORANGEPI_H3_ZEROPLUS2
    printf (" +------+-----+----------+------+---+OrangePiH3+---+------+----------+-----+------+\n");
#elif CONFIG_ORANGEPI_ZERO
    printf (" +------+-----+----------+------+---+NanoPiNeo Air+---+------+----------+-----+-----+\n");
#elif CONFIG_ORANGEPI_A64
    printf (" +------+-----+----------+------+---+OrangePi Win/Win+ +---+------+----------+-----+-----+\n");
#elif CONFIG_ORANGEPI_LITE2 || CONFIG_ORANGEPI_3
    printf (" +------+-----+----------+------+---+OrangePiH6+---+------+----------+-----+------+\n");
#endif
    wiringPiDebug = tmp;
}
