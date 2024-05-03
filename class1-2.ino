// 1
void setup(){
  size(400, 400);
  background(125,70,20);
  strokeWeight(2);
  stroke(0,255,0,100);
  rect(30,80, 350,200);
}

void draw(){

}


// 2
void setup(){
  size(400, 400);
  background(255);
  fill(0);
  text("Hello",200,100);
  
}

void draw(){
  
}


// 3
void setup(){
  size(400, 400);
  background(255);
  fill(0);
  textSize(50);
  text("Hello",200,200);

}

void draw(){
  
}


// 4
void setup(){
  size(400, 400);
  background(255);
  fill(0);
  textSize(50);
  text("Hello",200,100);
  
  PFont font = createFont("NanumGothic", 32);
  textFont(font);
  
   text("Hello",200,300);
}

void draw(){
  
}


// 5
void setup(){
  size(400, 400);
  background(255);
  PImage img = loadImage("apple.jpg");
  image(img, 20,50);
}

void draw(){
  
}


// 6
void setup(){
  size(400, 400);
  background(255);
  PImage img = loadImage("apple.jpg");
  image(img, 20,50, 200, 100);
}

void draw(){
  
}
