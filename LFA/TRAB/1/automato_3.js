// automato teste 3

let i = 0;
let number = 1010;

number = number
  .toString()
  .split("")
  .map((e) => (e = parseInt(e)));

q0();

function q0() {
  if (number[i] == 0) {
    !number[i + 1] ? qEnd() : qError()
  } else {
    q1();
  }
}

function q1() {
  if (number[i] == 0) {
    q0();
  } else {
    q2();
  }
  i++;
}

function q2() {
  if (number[i] == 0) {
    q0();
  } else {
    qFim();
  }
  i++;
}

function qFim() {
  if (number[i] == 0 || number[i] == 1) {
    console.log("accept");
    console.log("final state: q3");
  }
}

function qErro() {
  console.log("reject!");
}
