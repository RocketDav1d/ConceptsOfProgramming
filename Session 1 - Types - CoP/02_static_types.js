var readline = require('readline-sync');
function input(pmsg) {
    return readline.question(pmsg);
}
//------------------------------------------------
function check(str) {
    return str.startsWith("good ");
}
var GoodInputString = /** @class */ (function () {
    function GoodInputString(uncheckedInput) {
        if (!check(uncheckedInput)) {
            throw new RangeError();
        }
        this.value = uncheckedInput;
    }
    return GoodInputString;
}());
var BadInputString = /** @class */ (function () {
    function BadInputString(uncheckedInput) {
        this.name = uncheckedInput;
    }
    return BadInputString;
}());
function use(goodString) {
    var str = goodString.value;
    if (!str.startsWith("good")) {
        throw new Error("Can never happen! Tis no good!");
    }
    console.log(str.slice(4), "is good!");
}
var unchecked = "";
while (unchecked != "quit") {
    unchecked = input("Enter a string > ");
    try {
        // let checked = new BadInputString(unchecked);  // Structural Typing can be wired. 
        var checked = new GoodInputString(unchecked);
        use(checked);
    }
    catch (e) {
        console.error("Try again!\n[Error]: " + e.name + ': ' + e.message);
    }
}
// the technique of using thin wrappers to statically 
// check semantic domain properties is also known as 
// tagged types or branded types (e.g. https://www.totaltypescript.com/workshops/advanced-typescript-patterns/branded-types/what-is-a-branded-type)
// creating these can be "automated" using generics in some languages:
// declare const brand: unique symbol;
// export type Brand<T, TBrand> = T & { [brand]: TBrand };
// type Password = Brand<string, "Password">;
// class BadInputString {
//     value: string
//     constructor(uncheckedInput : string) {
//         this.value = uncheckedInput
//     }
// }
//         let checked = new BadInputString(unchecked);
