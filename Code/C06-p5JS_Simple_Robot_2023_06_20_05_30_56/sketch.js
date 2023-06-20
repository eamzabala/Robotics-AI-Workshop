                    
/* 
 *  C06 - p5.js Screen Control Simple Robot
 *  Creating a fancy interactive user interface 
 *  capable of communicating via the Browser/Phone's Screen
 *  in p5.js
 *  
 */

let pulse_i = 0;  //0-Short 1-Long
let shortDuration =200;
let longDuration = 400;

var leftMove = 0;
var rightMove = 0;

var goButton;
var leButton;
var riButton;
var ButtonSize = 120;

function setup() {
  createCanvas(windowWidth,windowHeight);
  
  // moves forward
  goButton = createButton('Move Forward').size(ButtonSize, ButtonSize);
  goButton.position(((windowWidth - ButtonSize) /2) , ButtonSize);
  goButton.style('font-size', '25px');
  goButton.style('background-color', color('green'));
  goButton.style('user-select', 'none');
  goButton.style('-moz-user-select', '-moz-none');
  goButton.style('-khtml-user-select', 'none');
  goButton.style('-webkit-user-select', 'none');
  // both sensors light up the same duration, both wheels move
  goButton.mousePressed(()  => {
                                  leftMove = 2; 
                                  rightMove = 2; 
                                  setTimeout(resetMove, 2000);
                                })
  
  //moves to the left
  leButton = createButton('Escape to the Left').size(ButtonSize, ButtonSize);
  leButton.position((((windowWidth - ButtonSize) /2) - ButtonSize), 0);
  leButton.style('font-size', '25px');
  leButton.style('background-color', color('green'));
  leButton.style('user-select', 'none');
  leButton.style('-moz-user-select', '-moz-none');
  leButton.style('-khtml-user-select', 'none');
  leButton.style('-webkit-user-select', 'none');
  // right lights up more, right wheel moves more, allows car to swerve to left  
  leButton.mousePressed(()  => {
                                  leftMove = 2; 
                                  rightMove = 1;
                                  setTimeout(resetMove, 500);
                                })
  riButton = createButton('Escape to the Right').size(ButtonSize, ButtonSize);
  riButton.position((((windowWidth - ButtonSize) /2) + ButtonSize) , 0);
  riButton.style('font-size', '25px');
  riButton.style('background-color', color('green'));
  riButton.style('user-select', 'none');
  riButton.style('-moz-user-select', '-moz-none');
  riButton.style('-khtml-user-select', 'none');
  riButton.style('-webkit-user-select', 'none');
  riButton.mousePressed(()  => {
                                  leftMove = 1; 
                                  rightMove = 2;
                                  setTimeout(resetMove, 500);
                                })
pulse_i = 0;
  setTimeout(updatePulse, shortDuration);
}

function updatePulse() {
    pulse_i = (pulse_i == 0) ? 1 : 0;
    setTimeout(updatePulse, (pulse_i == 0) ? shortDuration : longDuration);
}



function resetMove() {
  leftMove = 0; 
  rightMove = 0;
}

function draw() {
  background(0);
  stroke('red');
  
  if (((leftMove == 1) && (pulse_i == 0)) || 
      ((leftMove == 2) && (pulse_i == 1))) {
      fill(255);     
      strokeWeight(0); 
  }
  else {
      fill(0);
      strokeWeight(1);
  }
  // Draw a rectangle at (x, y, width, height , rounded corners).
  rect(10, windowHeight - 250 , (windowWidth/2) - 20, 200, 20);
  
  if (((rightMove == 1) && (pulse_i == 0)) || 
      ((rightMove == 2) && (pulse_i == 1))) {
      fill(255);     
      strokeWeight(0); 
  }
  else {
      fill(0);
      strokeWeight(1);
  }
  // Draw a rectangle at (x, y, width, height , rounded corners).
  rect((windowWidth/2) + 10, windowHeight - 250 , (windowWidth/2) - 20, 200, 20);
}             