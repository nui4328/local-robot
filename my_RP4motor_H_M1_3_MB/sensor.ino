int md_sensors(int sensor)
  {
    int sen_md = (sensor_maxs[sensor] + sensor_mins[sensor]) / 2;
    return sen_md;
  }

void sw_start()
  {
    bz(100);
    bz(100);
     while(digitalRead(9)==1)
        {

          //Serial.println(my_tcs('r'));
 
          String sen_mpu = String (error_Yaw());
          String sen_en = String (encoderPoss);    
          mydisplay_background(black);
          mydisplay("mpu "+ sen_mpu, 20, 10, 2, white);
          mydisplay("en "+ sen_en, 20, 40, 2, white);

          for(int i = 0; i<4; i++)
            {
              Serial.print(mcp_f(i));
              Serial.print("  ");
            }
           Serial.println(" ");
          for(int i = 0; i<4; i++)
            {
              Serial.print(md_sensors(i));
              Serial.print("  ");
            }
           Serial.println(" ");
            
        } 
     bz(300);
  }

void sw_start_n()
  {
    bz(100);
    bz(100);
     while(digitalRead(9)==1)
        {

          //Serial.println(my_tcs('r'));
           float red, green, blue;
           uint16_t r, g, b, c;
           tcss.getRawData(&r, &g, &b, &c);     
           float averag = (r+g+b)/3;
           red = r/averag; ;
           green = g/averag; 
           blue = b/averag;
 
          String sen_0 = String (mcp_f(0));
          String sen_1 = String (mcp_f(1));
          String sen_2 = String (mcp_f(2));
          String sen_3 = String (mcp_f(3));
          String sen_4 = String (mcp_f(4));
          String sen_5 = String (mcp_f(5));
          String sen_6 = String (mcp_f(6));
          String sen_7 = String (mcp_f(7));  
          String mpu = String (error_Yaw());  
          String sen_en = String (encoderPoss);
          String reds = String (red);
          String greens = String (green);
          String blues = String (blue);
          String sen_27 = String (digitalRead(27));
          String sen_26 = String (digitalRead(26));
          
          mydisplay_background(black);
          mydisplay(sen_0 +" "+ sen_1+" "+" "+sen_en, 10, 5, 2, red);
          mydisplay(sen_2 +" "+ sen_3+" "+" "+ mpu, 10, 30, 2, white);
          mydisplay(reds +" "+ greens +" "+ blues+" "+ sen_4+" "+ sen_26+" "+ sen_27, 10, 60, 1, white);
          Serial.print(mcp_f(4));
          Serial.print("  ");
          Serial.println(mcp_f(5));
         
            
        } 
     bz(300);
  }
