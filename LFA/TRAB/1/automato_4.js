/*
float -> accept!
char -> accept!
for -> accept!
!= float || char || for -> reject!
*/

let i = 0;
let string = "";

q0(string);

function q0(value_q0) {
  console.log(`State ${i}: q0`);
  if (value_q0[i] == "c") {
    i++;
    q8(value_q0);
  } else if (value_q0[i] == "f") {
    i++;
    q1(value_q0);
  } else {
    qError();
  }
}

function q1(value_q1) {
  console.log(`State ${i}: q1`);
  if (value_q1[i] == "l") {
    i++;
    q2(value_q1);
  } else if (value_q1[i] == "o") {
    i++;
    q3(value_q1);
  } else {
    qError();
  }
}

function q2(value_q2) {
  console.log(`State ${i}: q2`);
  if (value_q2[i] == "o") {
    i++;
    q5(value_q2);
  } else {
    qError();
  }
}

function q3(value_q3) {
  console.log(`State ${i}: q3`);
  if (value_q3[i] == "r") {
    q4();
  } else {
    qError();
  }
}

// accept
function q4() {
  console.log(`accept!`);
  console.log("Final state: q4");
}

function q5(value_q5) {
  console.log(`State ${i}: q5`);
  if (value_q5[i] == "a") {
    i++;
    q6(value_q5);
  } else {
    qError();
  }
}

function q6(value_q6) {
  console.log(`State ${i}: q6`);
  if (value_q6[i] == "t") {
    q7();
  } else {
    qError();
  }
}

//accept
function q7() {
  console.log(`accept!`);
  console.log("Final state: q7");
}

function q8(value_q8) {
  console.log(`State ${i}: q8`);
  if (value_q8[i] == "h") {
    i++;
    q9(value_q8);
  } else {
    qError();
  }
}

function q9(value_q9) {
  console.log(`State ${i}: q9`);
  if (value_q9[i] == "a") {
    i++;
    q3(value_q9);
  } else {
    qError();
  }
}

function qError() {
  console.log("reject!");
}