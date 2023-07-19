
float PID_outputs=0,errorss=0,integrals=0,derivatives=0;

void servo_up_open_delay()
  {
    servo(23,165); //ซ้าย
    servo(7,15); //ขวา
    delay(200);
    servo(8,servo_up );  //กลาง
  }
void  servo_up_open()  // ยก กางออก
  {
    servo(23,165); //ซ้าย
    servo(7,15); //ขวา  
    delay(100);
    servo(8,servo_up );  //กลาง
  }

void servo_down_open()   // ลง กางออก
  {
    servo(23,165); //ซ้าย
    servo(7,15); //ขวา 
    servo(8,servo_down );  //กลาง
  }

void  servo_up_close()  // ยก หุบเข้า
  {
    servo(23,56); //ขวา
    servo(7,115); //ซ้าย
    servo(8,servo_up );  //กลาง
  }

void  servo_down_close()  // ลง หุบเข้า
  {    
    servo(23,66); //ขวา
    servo(7,103); //ซ้าย
    servo(8,servo_down );  //กลาง
  }

void servo_big()    //
  {
      servo(23,66); //ขวา
      servo(7,105); //ซ้าย    
      servo(8,servo_down );  //กลาง 
  }

void  mission_L()
     {
          Motor(-1,30);
          delay(180);
          Motor(1,-30);
          delay(20);
          Motor(0,0);
          delay(20);
          
          servo_down_open();
    
          delay(300);
          Motor(1,-30);
          delay(200);
          Motor(-1,30);
          delay(20);
          Motor(0,0);
          delay(20);
     }
void  mission_R()
     {
          Motor(30,-1);
          delay(180);
          Motor(-30,1);
          delay(20);
          Motor(0,0);
          delay(40);
          
          servo_down_open();
    
          delay(300);
          Motor(-30,1);
          delay(200);
          Motor(30,-1);
          delay(20);
          Motor(0,0);
          delay(20);   
     }
void  mission_L_M()
     {
          Motor(-1,30);
          delay(300);
          Motor(1,-30);
          delay(30);
          Motor(0,0);
          delay(20);
          
          servo_sl_open();
          delay(100);
          servo(8,servo_up );
    
          delay(300);
          Motor(1,-30);
          delay(300);
          Motor(-1,30);
          delay(20);
          Motor(0,0);
          delay(20);   
     }
     
void  mission_R_M()
     {
          Motor(30,-1);
          delay(300);
          Motor(-30,1);
          delay(30);
          Motor(0,0);
          delay(40);
          
          servo_sl_open();
          delay(100);
          servo(8,servo_up );
    
          delay(300);
          Motor(-30,1);
          delay(300);
          Motor(30,-1);
          delay(20);
          Motor(0,0);
          delay(20);   
     }
void Ready_grab_small()
  {
      servo(23,86); //ขวา
      servo(7,85); //ซ้าย
      servo(8,servo_down );  //กลาง
  }
void Ready_grab_big()
  {
    servo(23,96); //ขวา
    servo(7,75); //ซ้าย
    servo(8,servo_down );  //กลาง
  }
void Ready_grab_big_L()
  {
    servo(23,96); //ขวา
    servo(7,25); //ซ้าย
    servo(8,servo_down );  //กลาง
  }
void mission(int SPL ,int SPR, float KP,int TIM,String box) 
    {       
          servo(29, 100);  
          servo(23,96); //ขวา
          servo(7,75); //ซ้าย  
          servo(8,servo_down );  //กลาง


           lasts_time_servo=millis();
                 while(millis()-lasts_time_servo<TIM  )
                       {
                         PID_output = (KP * error_F()) + (0.00015 * I) + (0.3* D);
                         Motor(SPL - PID_output,SPR + PID_output); 
                                     
                        }
           Motor(-20,-20);delay(15);
           Motor(0,0);delay(100);

          if (box == "big")
            {
               servo_big();        
            }
          else
            {
                servo_down_close();
            }
         
                  
    }
  void slow_servo()
  {
    for(int i = 160; i > 70 ; i-- )
      {
        servo(8, 160);
        delay(4);
      }
  }

void box_throw()
  {
    servo_down_open();
    delay(500);
    fline(60,60,0.5,200,'n','s',100, "a5", 20);
    delay(500); 
    servo(8,servo_up );
    delay(500);

    bline(0,0,0.5,50,'c','r',100, "a5", 20);
    //bline(0,0,0.5,50,'c','l',100, "a2", 20);
  }

void servo_sl_close()
    {
      for(int i = 0; i < 70; i++ )
        {
          servo(7,165-i); //ขวา
          servo(23,15+i); //ซ้าย 
          delay(5);
        }

      /*
       servo(7,165); //ขวา
       servo(23,15); //ซ้าย 

       servo(7,95); //ขวา
       servo(23,80); //ซ้าย 
      */
    }
void servo_sl_open()
    {
      for(int i = 0; i < 20; i++ )
        {
          servo(7,66+i); //ขวา
          servo(23,105-i); //ซ้าย 
          delay(15);
        }

      /*
             servo(7,66); //ขวา
      servo(23,105); //ซ้าย  

       servo(7,96); //ขวา
       servo(23,75); //ซ้าย
      */
    }
void fline_2sensor(int sl, int sr, float kp, int tm, int sensor, char sp, int ofset)
  {

    if(tm > 0)
      {
        unsigned long lasts_time = millis();
        while(millis() - lasts_time < tm)
          {
            float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
            float error_R = map(mcp_f(4), min_mcp_f(4), max_mcp_f(4), 0, 30 );
            errors = error_L - error_R;  
            I = 0;
            previous_I = 0;
            previous_error = 0;
            P = errors;
            I = I + previous_I;
            D = errors - previous_error ;            
            previous_I=I;
            previous_error=errors  ;  
            PID_output = (kp * P) + (0.00015 * I) + (kp* D); 

            Motor(sl + PID_output, sr - PID_output);
            //Serial.println(errors);
  
          }
          
      }
    else
      {
        while(1)
          {
            float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
            float error_R = map(mcp_f(4), min_mcp_f(4), max_mcp_f(4), 0, 30 );
            errors = error_L - error_R;  
            I = 0;
            previous_I = 0;
            previous_error = 0;
            P = errors;
            I = I + previous_I;
            D = errors - previous_error ;            
            previous_I=I;
            previous_error=errors  ;  
            PID_output = (kp * P) + (0.00015 * I) + (kp* D); 

            Motor(sl + PID_output, sr - PID_output);
            //Serial.println(errors);
            if(sensor == 0)
                  {
                      if(mcp_f(0)<md_mcp_f(0))
                          {
                              break;
                          }
                  }
              else if(sensor == 7)
                  {
                      if(mcp_f(7)<md_mcp_f(7))
                          {
                              break;
                          }
                  }
  
          }
      }

 ///////////////////////////////////////////////////////////////     
    if(sp == 's')
      {
        Motor(-sl, -sr);
        delay(ofset);
        Motor(0, 0);
        delay(50);
      }
    else
      {
        
        while(1)
          {
            float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
            float error_R = map(mcp_f(4), min_mcp_f(4), max_mcp_f(4), 0, 30 );
            errors = error_L - error_R;  
            I = 0;
            previous_I = 0;
            previous_error = 0;
            P = errors;
            I = I + previous_I;
            D = errors - previous_error ;            
            previous_I=I;
            previous_error=errors  ;  
            PID_output = (kp * P) + (0.00015 * I) + (kp* D); 

            Motor(sl + PID_output, sr - PID_output);
            //Serial.println(errors);
            if(mcp_f(sensor)<md_mcp_f(sensor))
                  {
                    break;
                  }
              
          }
          
        unsigned long lasts_time = millis();
        while(millis() - lasts_time < 50)
          {
            float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
            float error_R = map(mcp_f(4), min_mcp_f(4), max_mcp_f(4), 0, 30 );
            errors = error_L - error_R;  
            I = 0;
            previous_I = 0;
            previous_error = 0;
            P = errors;
            I = I + previous_I;
            D = errors - previous_error ;            
            previous_I=I;
            previous_error=errors  ;  
            PID_output = (kp * P) + (0.00015 * I) + (kp* D); 

            Motor(sl + PID_output, sr - PID_output);
            //Serial.println(errors);
  
          }
      }
 //////////////////////////////////////////////////////////////     
  }
