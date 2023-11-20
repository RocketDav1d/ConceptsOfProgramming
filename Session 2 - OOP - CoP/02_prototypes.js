var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var Base = /** @class */ (function () {
    function Base(value) {
        this.value = function () {
            return "['" + this.base_value + "' base.value()]";
        };
        this.calc = function () {
            return this.value() + " (from base.calc)";
        };
        this.base_value = value;
    }
    return Base;
}());
var Derived = /** @class */ (function (_super) {
    __extends(Derived, _super);
    function Derived() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this.calc = function () {
            return "Hello " + this.value() + " (from derived.calc)";
        };
        return _this;
    }
    return Derived;
}(Base));
var b = new Base("B");
console.log(b.value());
console.log(b.calc());
var d = new Derived("D");
console.log(d.value());
console.log(d.calc());
