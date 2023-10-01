void bridge(int sp, volatile int encoderPos_fw)
  {
    if(chopsticks == 1)
      {
        while(encoderPoss < time_chopsticks)      
          {          
            //check_color_roll();
            errors = error_Yaw_float();
            I = 0;
            previous_I = 0;
            previous_error = 0;
            P = errors;
            I = I + previous_I;
            D = errors - previous_error ;            
            previous_I=I;
            previous_error=errors  ;  
            PID_output = (5 * P) + (0.00015 * I) +(15* D); 
            
            Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
           
         }
       Motor(-60,-60,-60,-60);delay(70);
       Motor(0,0,0,0);delay(300);
      
        goto end_bridge;
      }
    else
      {
          while(encoderPoss < encoderPos_fw)      
              {          
                //check_color_roll();
                errors = error_Yaw_float();
                I = 0;
                previous_I = 0;
                previous_error = 0;
                P = errors;
                I = I + previous_I;
                D = errors - previous_error ;            
                previous_I=I;
                previous_error=errors  ;  
                PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                
                Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
               
             }
          Motor(-60,-60,-60,-60);delay(70);
          Motor(0,0,0,0);delay(300);
      }

    for(int i=0; i<4; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }


    //--------------------------------->> สไลข้างขวาพร้อมเช็ค เส้นดำ
    encoderPoss=0;
    while(encoderPoss > -300)         
        {          
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (6 * P) + (0.00015 * I) +(15* D); 
          
          Motor(50-PID_output, -(50 - PID_output),-(50 + PID_output), 50 + PID_output); 
         // Motor(55, -55,-55, 55);
         if( mcp_f(4)<sensor_maxs[4]-100)
            {
              Motor(-80,80,80,-80);delay(60);
              Motor(0,0,0,0);delay(150);
              if( mcp_f(4)<sensor_maxs[4]-100 && mcp_f(4)>md_sensors(4) )
                {
                  
                  break;
    
                }
              else 
                {
                
                  ch_line_r = 1;
                  //sw_start_n(); //-----------------------------------------
                  Motor(-60,60,60,-60);delay(70);
                  Motor(0,0,0,0);delay(300);
                  encoderPoss=0;
                  while(encoderPoss < 30)        
                     {                  
                       errors = error_Yaw_float();
                       I = 0;
                       previous_I = 0;
                       previous_error = 0;
                       P = errors;
                       I = I + previous_I;
                       D = errors - previous_error ;            
                       previous_I=I;
                       previous_error=errors  ;  
                       PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                            
                       Motor(-(65 + PID_output), 65+PID_output, 65 - PID_output, -(65 - PID_output));
                       //Motor(-55, 55, 55, -55);    
                     }
                   Motor(55,-55,-55,55);delay(30);
                   Motor(0,0,0,0);delay(200);
                  goto end_line;

                }
            }
       }
     if(ch_line_r == 0)  //------------------>>  ด้านข้างไม่มีเส้น
      {
        Motor(-60,60,60,-60);delay(70);
        Motor(0,0,0,0);delay(300);
        encoderPoss=0;
        while(encoderPoss < 40)        
           {                  
             errors = error_Yaw_float();
             I = 0;
             previous_I = 0;
             previous_error = 0;
             P = errors;
             I = I + previous_I;
             D = errors - previous_error ;            
             previous_I=I;
             previous_error=errors  ;  
             PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                  
             Motor(-(65 + PID_output), 65+PID_output, 65 - PID_output, -(65 - PID_output));
             //Motor(-55, 55, 55, -55);    
           }
         Motor(55,-55,-55,55);delay(30);
         Motor(0,0,0,0);delay(200);

         //-------------------------------------------->>> หมุน 90 องศา
         calibration_Yak(); 
         do{Motor(55,-55,55,-55);}while(error_Yaw_float()< 87);
         Motor(-55,55,-55,55);delay(100);
         Motor(0,0,0,0);delay(200);
         calibration_Yak(); 
         slide_r_blalan();   
      } 

    end_line:delay(10);
    re_bri: delay(10);
    encoderPoss=0; 
    ch_line_r = 0;
    calibration_Yak();    
    while(digitalRead(26)==1)     //----->> เดินลงสะพาน 
        {          
          //check_color_roll();
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(15* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
          if(mcp_f(0) < md_sensors(0)-220||mcp_f(1) < md_sensors(1)-220)
            {              
               Motor(-70,-70,-70,-70);delay(80);
               Motor(0,0,0,0);delay(200);               
               set_bl(1);
               encoderPoss=0; 
               ch_line_r = 0;
               calibration_Yak();
               
               bw(55, 170);
               calibration_Yak(); 
               do{Motor(-55,55,-55,55);}while(error_Yaw_float()> -85);
               Motor(55,-55,55,-55);delay(70);
               Motor(0,0,0,0);delay(300);
               calibration_Yak(); 
               goto re_bri;  //------------->> กลับขึ้นข้างบน ลงสะพานใหม่
            }  
         
       }
     
      encoderPoss=0; 
      while(encoderPoss < 330)     //----->> เดินลงสะพาน 
        {          
          //check_color_roll();
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(15* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
         
       }
    Motor(-60,-60,-60,-60);delay(70);
    Motor(0,0,0,0);delay(300);
    end_bridge:delay(10);
     encoderPoss=0; 

    
  }


void slide_r_blalan()
  {
    encoderPoss=0;
    while(encoderPoss < 1000)        
        {          
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(10* D); 
          
          Motor(-(65 + PID_output), 65+PID_output, 65 - PID_output, -(65 - PID_output));
          if(mcp_f(0)<md_sensors(0) || mcp_f(2)<md_sensors(2))
            {
              Motor(70,-70,-70,70);delay(100);
              Motor(0,0,0,0);delay(100); 
              if(mcp_f(0)<md_sensors(0)&& mcp_f(2)>md_sensors(2))
                {
                  do{Motor(10,-10,70,-70);}while(mcp_f(2)>md_sensors(2));
                  Motor(0,0,-70,70);delay(70);
                  Motor(0,0,0,0);delay(200);
                  break; 
                }
              else if(mcp_f(2)<md_sensors(2)&& mcp_f(0)>md_sensors(0))
                {
                  do{Motor(-70,70,-10,10);}while(mcp_f(0)>md_sensors(0));
                  Motor(70,-70,0,0);delay(70);   
                  Motor(0,0,0,0);delay(200); 
                  break;              
                }
              else
                {                   
                   Motor(0,0,0,0);delay(200);
                   break; 
                }

             }
        }
     encoderPoss=0;
        while(encoderPoss > -270)     //----------------------->> สไลขวาออกมา     
           {                  
             errors = error_Yaw_float();
             I = 0;
             previous_I = 0;
             previous_error = 0;
             P = errors;
             I = I + previous_I;
             D = errors - previous_error ;            
             previous_I=I;
             previous_error=errors  ;  
             PID_output = (7 * P) + (0.00015 * I) +(10* D); 
                  
             Motor(65-PID_output, -(65 - PID_output),-(65 + PID_output), 65 + PID_output);
                 
           }
         Motor(-55,55,55,-55);delay(50);
         Motor(0,0,0,0);delay(300);
    
  }
