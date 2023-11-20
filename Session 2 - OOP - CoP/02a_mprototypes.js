
class Base {
    base_value

    constructor(value) {
        this.base_value = value
    }

    value = function() {
        return "['" + this.base_value + "' base.value()]"
    }

    calc = function() {
        return this.value() + " (from base.calc)"
    }
}

class Derived extends Base {

    calc = function() {
        return "Hello " + this.value() + " (from derived.calc)"
    }

}

let b = new Base("B")
    
console.log(b.value())
console.log(b.calc())

let d = new Derived("D")

console.log(d.value())
console.log(d.calc())

console.log("-------------------------------");








Derived.prototype.buh1 = function() { return "buh1"; }
d.buh2 = function() { return "buh2"; }

console.log(d.buh1())
console.log(d.buh2())







let d2 = new Derived("D2")

console.log(d2.buh1())
console.log(d2.buh2())








// Base.value = function() { return "['Fake: " + this.base_value + "' altbase.value()]" }

// let d3 = new Derived("D3")
// console.log(d3.calc())
