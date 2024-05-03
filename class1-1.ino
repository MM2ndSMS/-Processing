 /*
함수를 호출한다 function call 
   주석처리. 프로세싱이 무시하고 건너뛰게 됩니다.
   */

// 창의 크기 설정
size( 300, 200);

// red, green, 
blue background(200);

//point(x, y) 
point(150, 100); 
point(151, 100); 
point(152, 100); 
point(153, 100); 
point(154, 100);

//line(x1,x2, y1, y2); 
line(300, 200, 0, 0);
line(300, 0, 0, 200);

//rect(x, y, w, h);
rectMode(CENTER);
//strokeWeight(4);
//stroke(0, 0, 255);
rect(158, 100, 50, 50);

// ellipse(x, y, m, h);
// ellipse(CORNER);
strokeWeight(5);
stroke(255, 0, 0);     //noStroke(0);
fill(0, 255, 0);       //nofill();
ellipse(150, 100, 120, 120);


//triangle
