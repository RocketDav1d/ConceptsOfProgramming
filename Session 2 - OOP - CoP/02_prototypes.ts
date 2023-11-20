
class Base {
    base_value : string 

    constructor(value : string) {
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
