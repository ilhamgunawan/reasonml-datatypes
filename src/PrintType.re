type shirtSizes =
  | Small
  | Medium
  | Large
  | XLarge;

let mySize = Medium;

/* 
  This will display a numeric value.
  ReasonML data types only exist only at compile time.
  If you want to display readable value, you must provide a function that convert the type to string. 
  See ShirtSizes.re file.
*/
Js.log2("My size is ", mySize);