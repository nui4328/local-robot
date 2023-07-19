void check_box()
  {
    if(my_tcs('r') >= boxcolor_red[0] - 0.2 && my_tcs('r') <= boxcolor_red[0] + 0.2 
      &&my_tcs('g')>= boxcolor_red[1] - 0.2 && my_tcs('g') <= boxcolor_red[1] + 0.2
      &&my_tcs('b')>= boxcolor_red[2] - 0.2 && my_tcs('b') <= boxcolor_red[2] + 0.2)
      {
        Serial.println("red");
        bz(100); delay(100);
      }
    else if(my_tcs('r') >= boxcolor_green[0] - 0.1 && my_tcs('r') <= boxcolor_green[0] + 0.1 
      &&my_tcs('g')>= boxcolor_green[1] - 0.1 && my_tcs('g') <= boxcolor_green[1] + 0.1
      &&my_tcs('b')>= boxcolor_green[2] - 0.15 && my_tcs('b') <= boxcolor_green[2] + 0.15)
      {
        Serial.println("green");
        bz(100); delay(100);
        bz(300); delay(100);
      }
    else if(my_tcs('r') >= boxcolor_blue[0] - 0.2 && my_tcs('r') <= boxcolor_blue[0] + 0.2 
      &&my_tcs('g')>= boxcolor_blue[1] - 0.2 && my_tcs('g') <= boxcolor_blue[1] + 0.2
      &&my_tcs('b')>= boxcolor_blue[2] - 0.2 && my_tcs('b') <= boxcolor_blue[2] + 0.2)
      {
        Serial.println("blue");
        bz(100); 
        bz(100);delay(100);
        bz(300); delay(100);
      }
    else if(my_tcs('r') >= boxcolor_yello[0] - 0.2 && my_tcs('r') <= boxcolor_yello[0] + 0.2 
      &&my_tcs('g')>= boxcolor_yello[1] - 0.2 && my_tcs('g') <= boxcolor_yello[1] + 0.2
      &&my_tcs('b')>= boxcolor_yello[2] - 0.2 && my_tcs('b') <= boxcolor_yello[2] + 0.2)
      {
        Serial.println("yello");
        bz(100); 
        bz(100);
        bz(100);delay(100);
        bz(300); delay(100);
      }
    else
      {
        Serial.println("none");
      }
  }
