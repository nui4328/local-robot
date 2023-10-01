void check_color_roll()
  {
     float red, green, blue;
     uint16_t r, g, b, c;
     tcss.getRawData(&r, &g, &b, &c);     
     float averag = (r+g+b)/3;
     red = r/averag; ;
     green = g/averag; 
     blue = b/averag;
      if(red > 1.6 )
        {
          color_ch = "red";
        }
      if(green > 1.3 && blue > red  )
        {
          color_ch = "green";
        } 
      if(blue >1.3 )
        {
          color_ch = "blue";
        }
      if(red >1.3 && red <1.6 && green > blue )
        {
          color_ch = "yello";
        }
     else
        {
          color_ch = "none";
        }
  }

void check_color_roll_bz()
  {
     float red, green, blue;
     uint16_t r, g, b, c;
     tcss.getRawData(&r, &g, &b, &c);     
     float averag = (r+g+b)/3;
     red = r/averag; ;
     green = g/averag; 
     blue = b/averag;
      if(red > 1.6 )
        {
          bz(50);
          bz(300);
          color_ch = "red";
        }
      else if(green > 1.2 && blue > red  )
        {
          bz(50);
          bz(50);
          bz(300);
          color_ch = "green";
        } 
      else if(blue > 1.3 )
        {
          bz(50);
          bz(50);
          bz(50);
          bz(300);
          color_ch = "blue";
        }
      else if(red >1.3 && red <1.6 &&green > blue )
        {
          bz(50);
          bz(50);
          bz(50);
          bz(50);
          bz(300);
          color_ch = "yello";
        }
      else
        {
          color_ch = "none";
        }
  }
