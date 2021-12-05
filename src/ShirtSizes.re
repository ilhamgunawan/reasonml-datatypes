type shirtSizes =
  | Small
  | Medium
  | Large
  | XLarge;

let mySize: shirtSizes = Small;
let otherSize = Large;
let yourSize: shirtSizes = XLarge; 

let getShirtPrice = (size: shirtSizes): float => {
  switch (size) {
    | Small => 11.00;
    | Medium => 11.50;
    | Large => 12.00;
    | XLarge => 12.50;
    };
};

let getStringOfShirtSize = (size: shirtSizes): string => {
  switch (size) {
    | Small => "S";
    | Medium => "M";
    | Large => "L";
    | XLarge => "XL";
    };
};

let getShirtSizeOfString = (str: string): shirtSizes => {
  switch (str) {
    | "S" => Small;
    | "M" => Medium ;
    | "L" => Large;
    | "XL" => XLarge;
    | _ => Medium;
    };
}

Js.log2("My price: ", getShirtPrice(mySize));
Js.log2("Other price: ", getShirtPrice(otherSize));
Js.log2("Your price: ", getShirtPrice(yourSize));

Js.log2("My size: ", getStringOfShirtSize(mySize));
Js.log2("Other size: ", getStringOfShirtSize(otherSize));
Js.log2("Your size: ", getStringOfShirtSize(yourSize));