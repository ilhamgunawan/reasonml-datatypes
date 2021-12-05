type shirtSizes =
  | Small
  | Medium
  | Large
  | XLarge(int);

let mySize = Medium;
let bigSize = XLarge(1);
let veryBigSize = XLarge(2);

let shirtPrice = (size: shirtSizes): float => {
  switch (size) {
    | Small => 11.00;
    | Medium => 11.50;
    | Large => 12.00;
    | XLarge(n) => 12.50 +. (float_of_int(n-1) *. 0.50);
    };
};

let stringOfShirtSize = (size: shirtSizes): string => {
  switch (size) {
    | Small => "S";
    | Medium => "M";
    | Large => "L";
    | XLarge(n) => String.make(n, 'X') ++ "L";
    };
};

let shirtSizeOfString = (str: string): shirtSizes => {
  switch (str) {
    | "S" => Small;
    | "M" => Medium ;
    | "L" => Large;
    | "XL" => XLarge(1);
    | "XXL" => XLarge(2);
    | "XXXL" => XLarge(3);
    | "XXXXL" => XLarge(4);
    | _ => Medium;
    };
};

Js.log2("My price: ", shirtPrice(mySize));
Js.log2("Big price: ", shirtPrice(bigSize));
Js.log2("Very big price: ", shirtPrice(veryBigSize));

Js.log2("Very big size: ", stringOfShirtSize(veryBigSize));