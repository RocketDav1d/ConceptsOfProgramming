var readline = require('readline-sync');

function input(pmsg : string) {
    return readline.question(pmsg);
}
//------------------------------------------------

function check(str : string) {
    return str.startsWith("good ")
}

class GoodInputString {
    value: string

    constructor(uncheckedInput : string) {
        if (!check(uncheckedInput)) {
            throw new RangeError()
            
        }
        this.value = uncheckedInput
    }
}

class BadInputString {
    name: string

    constructor(uncheckedInput : string) {
        this.name = uncheckedInput
    }
}

function use(goodString : GoodInputString) {
    let str = goodString.value
    if (! str.startsWith("good")) {
        throw new Error("Can never happen! Tis no good!");
    }

    console.log(str.slice(4), "is good!");
}

let unchecked = ""
while (unchecked != "quit") {
    unchecked = input("Enter a string > ");
    try {
        // let checked = new BadInputString(unchecked);  // Structural Typing can be wired. 
        let checked = new GoodInputString(unchecked);
        use(checked);
    } catch (e) {
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

