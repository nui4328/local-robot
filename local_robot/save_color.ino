void put_colorbox_red()
  {      
     while(digitalRead(9)==1)
        {
           float color[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
           for(int i = 0; i<3; i++)
              {
                Serial.print(color[i]);Serial.print("  ");
              }
           Serial.println(" ");
        }
     bz(200);
     delay(300);         
     float color_box[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
     EEPROM.put(100, color_box); // write data to EEPROM address 0
     EEPROM.commit(); // save changes to EEPROM
    
     float readData_sensor[3];
     EEPROM.get(100, readData_sensor); // read data from EEPROM address 0
     Serial.print("data -> EEPROM : ");
     for (int i = 0; i < 3; i ++) 
        {
           Serial.print(readData_sensor[i]);Serial.print("  ");
        }
     Serial.println("  ");
      
     bz(100);
     bz(100); 

  }
void read_eep_box_red()
  {
     float readData_sensor[3];
     EEPROM.get(100, readData_sensor); // read data from EEPROM address 0
     Serial.println("data -> EEPROM : ");
     for (int i = 0; i < 3; i ++) 
        {
          Serial.print(readData_sensor[i]);Serial.print("  ");
        }
     Serial.println("  ");
     for(int i=0; i<3; i++)
        {
          boxcolor_red[i]=readData_sensor[i];
        }
     bz(100);
     bz(100);
     Serial.print(" boxcolor_red_r ");Serial.print(boxcolor_red[0]);
     Serial.print(" boxcolor_red_g ");Serial.print(boxcolor_red[1]);
     Serial.print(" boxcolor_red_b ");Serial.println(boxcolor_red[2]);
  }
void put_colorbox_green()
  {      
     while(digitalRead(9)==1)
        {
            float color[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
            for(int i = 0; i<3; i++)
                {
                   Serial.print(color[i]);Serial.print("  ");
                }
             Serial.println(" ");
        }
     bz(200);
     delay(300);
         
     float color_box[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
     EEPROM.put(150, color_box); // write data to EEPROM address 0
     EEPROM.commit(); // save changes to EEPROM
    
     float readData_sensor[3];
     EEPROM.get(150, readData_sensor); // read data from EEPROM address 0
     Serial.print("data -> EEPROM : ");
     for (int i = 0; i < 3; i ++) 
        {
           Serial.print(readData_sensor[i]);Serial.print("  ");
        }
      Serial.println("  ");
      
      bz(100);
      bz(100); 

  }
void read_eep_box_green()
  {
      float readData_sensor[3];
      EEPROM.get(150, readData_sensor); // read data from EEPROM address 0
      Serial.println("data -> EEPROM : ");
      for (int i = 0; i < 3; i ++) 
        {
          Serial.print(readData_sensor[i]);Serial.print("  ");
        }
      Serial.println("  ");
     for(int i=0; i<3; i++)
        {
          boxcolor_green[i]=readData_sensor[i];
        }
      bz(100);
      bz(100);
  }
void put_colorbox_blue()
  {      
     while(digitalRead(9)==1)
        {
            float color[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
            for(int i = 0; i<3; i++)
                {
                  Serial.print(color[i]);Serial.print("  ");
                }
            Serial.println(" ");
        }
     bz(200);
     delay(300);
         
     float color_box[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
     EEPROM.put(200, color_box); // write data to EEPROM address 0
     EEPROM.commit(); // save changes to EEPROM
    
     float readData_sensor[3];
     EEPROM.get(200, readData_sensor); // read data from EEPROM address 0
     Serial.print("data -> EEPROM : ");
     for (int i = 0; i < 3; i ++) 
        {
           Serial.print(readData_sensor[i]);Serial.print("  ");
        }
     Serial.println("  ");
      
     bz(100);
     bz(100); 

  }
void read_eep_box_blue()
  {
     float readData_sensor[3];
     EEPROM.get(200, readData_sensor); // read data from EEPROM address 0
     Serial.println("data -> EEPROM : ");
     for (int i = 0; i < 3; i ++) 
        {
          Serial.print(readData_sensor[i]);Serial.print("  ");
        }
     Serial.println("  ");
     for(int i=0; i<3; i++)
        {
          boxcolor_blue[i]=readData_sensor[i];
        }
     bz(100);
     bz(100);
  }
void put_colorbox_yello()
  {      
     while(digitalRead(9)==1)
        {
            float color[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
            for(int i = 0; i<3; i++)
                {
                  Serial.print(color[i]);Serial.print("  ");
                }
            Serial.println(" ");
        }
     bz(200);
     delay(300);
         
     float color_box[3] = {my_tcs('r'), my_tcs('g'), my_tcs('b')};
     EEPROM.put(250, color_box); // write data to EEPROM address 0
     EEPROM.commit(); // save changes to EEPROM
    
     float readData_sensor[3];
     EEPROM.get(250, readData_sensor); // read data from EEPROM address 0
     Serial.print("data -> EEPROM : ");
     for (int i = 0; i < 3; i ++) 
        {
         Serial.print(readData_sensor[i]);Serial.print("  ");
        }
     Serial.println("  ");
      
     bz(100);
     bz(100); 
  }
void read_eep_box_yello()
  {
     float readData_sensor[3];
     EEPROM.get(250, readData_sensor); // read data from EEPROM address 0
     Serial.println("data -> EEPROM : ");
     for (int i = 0; i < 3; i ++) 
        {
          Serial.print(readData_sensor[i]);Serial.print("  ");
        }
     Serial.println("  ");
    for(int i=0; i<3; i++)
        {
          boxcolor_yello[i]=readData_sensor[i];
        }
     bz(100);
     bz(100);
  }
