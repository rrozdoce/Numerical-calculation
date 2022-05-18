// AFD test 1

/*
a -> reject! 
b -> reject! 
ab -> reject! 
abb -> reject!
c -> accept! 
abbc -> accept!
abbabbabbc -> accept!
*/

let i = 0;
let string = "a"; // input test

q0(string);

function q0(value_q0) {
  console.log(`State ${i}: q0`)
  if (value_q0[i] == "a") {
    i++;
    q1(value_q0);
  } else if (value_q0[i] == "c") {
    !value_q0[i + 1] ? qEnd() : qError()
  } else {
    qError();
  }
}
function q1(value_q1) {
  console.log(`State ${i}: q1`)
  if (value_q1[i] == "b") {
    i++;
    q2(value_q1);
  } else {
    qError();
  }
}

function q2(value_q2) {
  console.log(`State ${i}: q2`)
  if (value_q2[i] == "b") {
    i++;
    q0(value_q2);
  } else {
    qError();
  }
}

function qError() {
  console.log("reject!");
}

function qEnd() {
  console.log("accept!");
  console.log("final state: q3");
}