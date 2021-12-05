type scoreType = int;
type percentType = float;
type userId = int;

let person: userId = 60;

let calculatePercent = (score: scoreType, max: scoreType): percentType => {
  float_of_int(score) /. float_of_int(max) *. 100.0;
};

let result = calculatePercent(person, 75); //calculatePercent expecting scoreType, but we pass userId instead 
Js.log({j|Bogus result: $result|j});