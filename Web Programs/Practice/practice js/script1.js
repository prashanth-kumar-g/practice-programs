// Note: Created for learning and revision. Because single script files cover multiple concepts, running everything at once will cause conflicts. Please 
// comment out any unused files or code blocks, leaving only your target code uncommented to see the correct output.

// 1. Ways to print in JavaScript

    console.log("Hello World!");
    alert("me");
    document.write("This is document write");

// 2. JavaScript console API
    console.log("Hello World!", 4 + 6, "Another log");
    console.warn("This is a warning");
    console.error("This is an error");

/*
multi
line
comment
*/

// 3. JavaScript Variables
    // What are variables? - Containers to store data values
        var number1 = 34;
        var number2 = 56;
        console.log(number1 + number2);

// 4. Data types in JavaScript
    // Numbers
        var num1 = 455;
        var num2 = 56.32;
        console.log(num1 + num2);

    // Strings
        var str1 = "This is a string";
        var str2 = 'This is also a string';
        console.log(str1 + " " + str2);

    // Objects
        var marks = {
            ravi: 34,
            shubham: 78,
            harry: 99.977
        }
        console.log(marks);

    // Booleans
        var a = true;
        var b = false;
        console.log(a, b);

    // Undefined
        var und = undefined;
        console.log(und);
        var und; // also undefined
        console.log(und);

    // Null
        var n = null;
        console.log(n);

    /*
    At a very high level, there are two types of data types in JavaScript
    1. Primitive data types: undefined, null, number, string, boolean, symbol
    2. Reference data types: Arrays and Objects
    */

    // Arrays
        var arr = [1, 2, "babbar", 4, 5];
        console.log(arr);

// 5. Operators in JavaScript
    // Arithmetic Operators
        var a = 100;
        var b = 10;
        console.log("The value of a + b is", a + b);
        console.log("The value of a - b is", a - b);
        console.log("The value of a * b is", a * b);
        console.log("The value of a / b is", a / b);
        console.log("The value of a % b is", a % b);

    // Assignment Operators
        var c = 10;
        c += 2; // c = c + 2
        c -= 2; // c = c - 2
        c *= 2; // c = c * 2
        c /= 2; // c = c / 2
        c %= 2; // c = c % 2
        console.log(c);

    // Comparison Operators
        var x = 34;
        var y = 56;
        console.log(x == y);
        console.log(x != y);
        console.log(x >= y);
        console.log(x <= y);
        console.log(x > y);
        console.log(x < y);

    // Logical Operators
        var p = true;
        var q = false;
        console.log(p && q);
        console.log(p || q);
        console.log(!p);

    // Type Operators
        console.log(typeof 34);
        console.log(typeof "Hello");
        console.log(typeof true);
        console.log(typeof [1, 2, 3]);
        console.log(typeof {name: "John", age: 30});

    // Operator Precedence
        var a = 100 + 50 * 3; // Multiplication has higher precedence than addition
        console.log(a);
        var b = (100 + 50) * 3; // Parentheses have the highest precedence
        console.log(b);
