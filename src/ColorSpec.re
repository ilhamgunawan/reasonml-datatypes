type colorSpec = 
  | White
  | Black
  | Grey(float)
  | RGB(int, int, int);

let stringOfColorSpec = (cspec: colorSpec): string => {
  switch(cspec) {
    | White => "rgb(255,255,255)";
    | Black => "rgb(0,0,0)";
    | Grey(n) => {
      let code = Js.Float.toString(Js.Math.round(255.0 *. n));
      {j|rgb($code,$code,$code)|j};
    }
    | RGB(red, green, blue) => {j|rgb($red,$green,$blue)|j};
  }
};

Js.log(stringOfColorSpec(White));
Js.log(stringOfColorSpec(Black));
Js.log(stringOfColorSpec(Grey(0.5)));
Js.log(stringOfColorSpec(RGB(64, 128, 192)));