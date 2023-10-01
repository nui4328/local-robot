#include <my_rp_4wd.h>
#include <Wire.h>
#include <my_TCS34725.h>  
#include <my_mpu6050.h> 
#include <EEPROM.h>
#define EEPROM_ADDR 0x50
  
unsigned long lasts_time=millis();
//------------------------->>
// กำหนดพินอินพุตตัวเข้ารหัส
const int encoderPinA = 0; 
const int encoderPinB = 1; 

// กำหนดตัวแปรเพื่อติดตามตำแหน่งและทิศทางของตัวเข้ารหัส
volatile int encoderPoss = 0;  // Variable to store the encoder position
int encoderPinALast = LOW;  
int n = LOW;
//------------------------->>

int ch_line_r = 0;
int dis_line_r = 600;  /////////////////------->>  สไลออกมา
volatile int time_bridge = 530;
volatile int time_chopsticks = 500;

float deg_90_R = 85.0;


int ch_bridge;
int chopsticks;
int bg_st;
String color_ch="none";
int none_yello = 0;

int sensor_maxs[] = {803, 805, 811, 835,870};   //------------------------------------------------>> ค่าเซนเซอร์ พื้นขาว
int sensor_mins[] = {220, 218, 217, 220, 210};   //----------------------------------------------->> ค่าเซนเซอร์ พื้นดำ


int red_box, green_box, blue_box, yello_box;
my_TCS34725 tcss = my_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12   
     setup_mpu();
    
     setup_encoder_fw();
     calibration_Yak();   
     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);
     pinMode(27,INPUT_PULLUP);
     pinMode(26,INPUT_PULLUP);

     servo(22, 90);
     servo(23, 90);
     //servo(28, 20);

   
     sw_start_n();    
         
//\\------------------------------------------->>>>>  เขียนโค๊ดที่นี้ 
    
 
    
    fw_begin(50, 2400); ///------------------------------------------>>  fw_begin(ความเร็ว, ค่ารอบมอเตอร์);  เดินออกจากแผ่นแรก
   
    bg_st = 1;
    for(int i = 0; i<200; i++)
      {
        fw_ch_r(45, 2400);      ///---------------------------------->>  fw_ch_r(ความเร็ว, ค่ารอบมอเตอร์);
      }

//\\------------------------------------------->>>>>   เขียนโค๊ดที่นี้ 
     
      
  }

void loop() 
  {  
    

   /*
    float red, green, blue;
     uint16_t r, g, b, c;
     tcss.getRawData(&r, &g, &b, &c);     
     float averag = (r+g+b)/3;
     red = r/averag; ;
     green = g/averag; 
     blue = b/averag;
    float color[3] = {red, green, blue};
    for(int i = 0; i<3; i++)
      {
        Serial.print(color[i]);Serial.print("  ");
      }
     Serial.println(" ");
     delay(4);
     check_color_roll_bz();
   */
   delay(10);
  }
