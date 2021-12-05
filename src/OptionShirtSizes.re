type shirtSizes =
  | Small
  | Medium
  | Large
  | XLarge(int);

let mySize: option(shirtSizes) = Some(Medium);
let bigSize: option(shirtSizes) = Some(XLarge(1));
let veryBigSize: option(shirtSizes) = Some(XLarge(2));

let shirtPrice = (size: option(shirtSizes)): option(float) => {
  switch (size) {
    | Some(Small) => Some(11.00);
    | Some(Medium) => Some(11.50);
    | Some(Large) => Some(12.00);
    | Some(XLarge(n)) => Some(12.50 +. (float_of_int(n-1) *. 0.50));
    | None => None;
  }
};

let stringOfShirtSize = (size: option(shirtSizes)): option(string) => {
  switch (size) {
    | Some(Small) => Some("S");
    | Some(Medium) => Some("M");
    | Some(Large) => Some("L");
    | Some(XLarge(n)) => Some(String.make(n, 'X') ++ "L");
    | None => None;
  }
};

let shirtSizeOfString = (str: string): option(shirtSizes) => {
  switch (str) {
    | "S" => Some(Small);
    | "M" => Some(Medium);
    | "L" => Some(Large);
    | "XL" => Some(XLarge(1));
    | "XXL" => Some(XLarge(2));
    | "XXXL" => Some(XLarge(3));
    | "XXXXL" => Some(XLarge(4));
    | _ => None;
    };
};

let displayPrice = (inputSize: string): unit => {
  let size = shirtSizeOfString(inputSize);
  let price = shirtPrice(size);
  let text = 
    switch (price) {
      | Some(cost) => {
        let costFixed = Js.Float.toFixedWithPrecision(cost, ~digits = 2);
        {j|The $inputSize shirt price is \$$costFixed|j}
      } 
      | None => {j|The price of $inputSize shirt doesn't exist.|j}
    };
  Js.log(text);
}

displayPrice("XL");
displayPrice("XXXL");
displayPrice("M");
displayPrice("SS");

// Js.log2("My price: ", shirtPrice(mySize));
// Js.log2("Big price: ", shirtPrice(bigSize));
// Js.log2("Very big price: ", shirtPrice(veryBigSize));

// Js.log2("Very big size: ", stringOfShirtSize(veryBigSize));

// Js.log2("XXL is: ", shirtSizeOfString("XXL"));
// Js.log2("ZZZ is: ", shirtSizeOfString("ZZZ"));