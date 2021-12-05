type scoreType = Score(int);
type percentType = Percent(float);
type userId = UserId(int);

let calculatePercent = (score: scoreType, max: scoreType): percentType => {
  let Score(s) = score;
  let Score(m) = max;
  Percent(float_of_int(s) /. float_of_int(m) *. 100.0); 
};

let Percent(result) = calculatePercent(Score(40), Score(75));
Js.log({j|Expected result: $result|j});