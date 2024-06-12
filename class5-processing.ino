import processing.serial.*;
Serial port;

String Serial_Data_String = null;

void setup()
{
  size(600,400);
  background(255);
  rectMode(CENTER);     //중앙을 기준으로 도형을 그립니다.
  //rectMode(CORNER):    //모서리를 기준으로 도형을 그립니다.
  display_button(0);
  
  port = new Serial(this, "COM6", 115200);
}

void send_serial_motor_command(int mode)
{
  switch(mode)
  {
    case 1:
          port.write("#"); port.write("M"); port.write("1"); port.write("255"); port.write(" *\n");
          break;
    case 0:
          port.write("#"); port.write("M"); port.write("0"); port.write("0"); port.write(" *\n");
          break;
    case -1:
          port.write("#"); port.write("M"); port.write("-1"); port.write("255"); port.write(" *\n");
          break;
  }

}

void display_button(int mode)  // mode 0: stop mode 1: go mode -1:back 
{
  background(255);
  switch(mode)
  {
    case 1:
            fill(255,255,255);        // 색상 채우기
            rect(300,200,50,50);  //사각형 그리기
  
            // 전진을 위한 버튼
            fill(0,0,255);    // 색상 채우기
            rect(300,150,50,50);  //사각형 그리기
 
            // 후진을 위한 버튼
            fill(255,255,255);    // 색상 채우기
            rect(300,250,50,50);  //사각형 그리기
          break;
    case 0:
            fill(255,0,0);        // 색상 채우기
            rect(300,200,50,50);  //사각형 그리기
  
            // 전진을 위한 버튼
            fill(255,255,255);    // 색상 채우기
            rect(300,150,50,50);  //사각형 그리기
  
            // 후진을 위한 버튼
            fill(255,255,255);    // 색상 채우기
            rect(300,250,50,50);  //사각형 그리기
          break;
    case -1:
            fill(255,255,255);        // 색상 채우기
            rect(300,200,50,50);  //사각형 그리기
  
            // 전진을 위한 버튼
            fill(255,255,255);    // 색상 채우기
            rect(300,150,50,50);  //사각형 그리기
 
            // 후진을 위한 버튼
            fill(0,255,0);    // 색상 채우기
            rect(300,250,50,50);  //사각형 그리기
          break;
  }
}

void draw()
{

 
}

void mousePressed(){

  if((mouseX >=275) && (mouseX <=325) && (mouseY >=125) && (mouseY <=175))
  {
    println("Go");
    display_button(1);
  }
  else if((mouseX >=275) && (mouseX <=325) && (mouseY >=225) && (mouseY <=275))
  {
    println("Back");
    display_button(-1);
  }
  else if((mouseX >=275) && (mouseX <=325) && (mouseY >=175) && (mouseY <=225))
  {
    println("Stop");
    display_button(0);
  }
  else
  {
    println(mouseX,mouseY);
  }
  delay(100);



}
