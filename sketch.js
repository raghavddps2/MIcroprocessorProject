/*

  @Raghav Maheshwari
  @Date: 16th May, 2019.
  @Time: 08:57 A.M.
*/

let mobilenet; //This is a variable for the data set.
let video; //For setting the video

//Three labels.
let label = ''; 
let label1 = '';
let label2 = '';

function modelReady() {
  console.log('Model is ready!!!');
  mobilenet.predict(gotResults);
}
function gotResults(error, results) {
  if (error) {
    console.error(error);
  } else {
    
    //Classname and probability tell the items and the probability 
    label = results[0].className;
    label1 = results[0].probability;
    label2 = "The item is "+ label + " with a probability of " + label1;
    //Calling this function again and again to predict the results.
    mobilenet.predict(gotResults);
  }
}

function setup() {
  createCanvas(1350, 500);
  video = createCapture(VIDEO); //tells the video mode.
  video.hide();
  background(0); //Setting the color as black.
  mobilenet = ml5.imageClassifier('MobileNet', video, modelReady);
}

function draw() {
  background(0);
  image(video, 0, 0);
  fill(255);
  textSize(32);
  text(label2, 600, height - 100);
}