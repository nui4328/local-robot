 #include <my_rp2040.h>
 #include <my_TCS34725.h>  
 #include <Wire.h>
#include <EEPROM.h>
#define EEPROM_ADDR 0x50
  
unsigned long lasts_time_servo=millis();

int servo_down = 50;
int servo_up = 127;

float boxcolor_red[3];
float boxcolor_green[3];
float boxcolor_blue[3];
float boxcolor_yello[3];

void setup()
  {    
      Serial.begin(9600);
      
      pos_motor_cal(10, 12, 10);
      to_set_motor_LR(100, 100);          //ตั้งค่ามอเตอร์ให้หุ่นยนต์วิ่งตรง
      
      to_slow_motor(25, 25);           // ตั้งค่า ความเร็วมอเตอร์เวลาเข้าแยก
      to_turn_center_l(-80, 80 );   // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวซ้ายแบบ center
      to_turn_center_r(80, -80 );   // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวขาวแบบ center
      to_turn_front_l(-20, 100);     // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวซ้ายแบบ เซนเซอร์หน้า  เดินหน้า
      to_turn_front_r(100, -20);     // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวขวาแบบ เซนเซอร์หน้า  เดินหน้า
      to_speed_turn_fl(100, 20, 40);  // ค่าพุ่งตัวออกหลังจากการเลี้ยว มีผลต่อตัวแปรสุดท้ายของคำสั่งเลี้ยว ถ้าเป็น 0
      to_speed_turn_fr(20, 100, 40);  // ค่าพุ่งตัวออกหลังจากการเลี้ยว มีผลต่อตัวแปรสุดท้ายของคำสั่งเลี้ยว ถ้าเป็น 0
      
      to_brake_fc(5, 25);            // ตั้งค่าในการหยุดมอเตอร์ก่อนหมุนซ้ายขวา to_brake_fc(...f..., ....c...);
      to_delay_f(5);                 // ระยะทางในการข้ามเส้นเวลาหมุนตัวแบบ f
    
      kp_sl(0.1, 0.1);  // kp และ ki ในฟังก์ เดินตามเส้นแบบช้า
      kd_fw(0.6);
      kd_bw(0.6);

      sensor_set();
      //setup_tcs();

      

      //servo_down_close();

      ///////////////////////////////////------->>>>  เก็บค่าสีกล่อง โดยเอากล่องมาวางหน้าเซนเซอร์แล้วกดปุ่ม sw-GP9 
      /*
      put_colorbox_red();
      put_colorbox_green();
      put_colorbox_blue();
      put_colorbox_yello();
      */
      ///////////////////////////////////------->>>>  เก็บค่าสีกล่อง โดยเอากล่องมาวางหน้าเซนเซอร์แล้วกดปุ่ม sw-GP9 
      
      sw();
      
      read_eep_box_red();     ///////////------->>>>  เก็บค่าสีกล่อง จาก eepprom ไว้ในตัวแปร  float boxcolor_red[3];
      read_eep_box_green();                                                       //  float boxcolor_green[3];
      read_eep_box_blue();                                                        //  float boxcolor_blue[3];
      read_eep_box_yello();                                                       //  float boxcolor_yello[3]
      
      
//\\------------------------------------------->>>>>  เขียนโค๊ดที่นี้      
     



//\\------------------------------------------->>>>>   เขียนโค๊ดที่นี้ 
     
      
  }

void loop() 
  {  

    check_box();
   
 /*
    float color[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
    for(int i = 0; i<3; i++)
      {
        Serial.print(color[i]);Serial.print("  ");
      }
     Serial.println(" ");
 */

  }
