// 1. Ways to print in JavaScript
    // console.log("Hello World!");
    // alert("me");
    // document.write("This is document write");

// 2. JavaScript console API
    // console.log("Hello World!", 4 + 6, "Another log");
    // console.warn("This is a warning");
    // console.error("This is an error");

/*
multi
line
comment
*/

// 3. JavaScript Variables
// What are variables? - Containers to store data values
    // var number1 = 34;
    // var number2 = 56;
    // console.log(number1 + number2);

// 4. Data types in JavaScript
    // Numbers
    // var num1 = 455;
    // var num2 = 56.32;
    // console.log(num1 + num2);

    // Strings
    // var str1 = "This is a string";
    // var str2 = 'This is also a string';
    // console.log(str1 + " " + str2);

    // Objects
    // var marks = {
    //     ravi: 34,
    //     shubham: 78,
    //     harry: 99.977
    // }
    // console.log(marks);

    // Booleans
    // var a = true;
    // var b = false;
    // console.log(a, b);

    // Undefined
    // var und = undefined;
    // console.log(und);
    // var und; // also undefined
    // console.log(und);

    // Null
    // var n = null;
    // console.log(n);

    /*
    At a very high level, there are two types of data types in JavaScript
    1. Primitive data types: undefined, null, number, string, boolean, symbol
    2. Reference data types: Arrays and Objects
    */

    // Arrays
    // var arr = [1, 2, "babbar", 4, 5];
    // console.log(arr);

// 5. Operators in JavaScript
    // Arithmetic Operators
    // var a = 100;
    // var b = 10;
    // console.log("The value of a + b is", a + b);
    // console.log("The value of a - b is", a - b);
    // console.log("The value of a * b is", a * b);
    // console.log("The value of a / b is", a / b);
    // console.log("The value of a % b is", a % b);

    // Assignment Operators
    // var c = 10;
    // c += 2; // c = c + 2
    // c -= 2; // c = c - 2
    // c *= 2; // c = c * 2
    // c /= 2; // c = c / 2
    // c %= 2; // c = c % 2
    // console.log(c);

    // Comparison Operators
    // var x = 34;
    // var y = 56;
    // console.log(x == y);
    // console.log(x != y);
    // console.log(x >= y);
    // console.log(x <= y);
    // console.log(x > y);
    // console.log(x < y);

    // Logical Operators
    // var p = true;
    // var q = false;
    // console.log(p && q);
    // console.log(p || q);
    // console.log(!p);

    // Type Operators
    // console.log(typeof 34);
    // console.log(typeof "Hello");
    // console.log(typeof true);
    // console.log(typeof [1, 2, 3]);
    // console.log(typeof {name: "John", age: 30});

    // Operator Precedence
    // var a = 100 + 50 * 3; // Multiplication has higher precedence than addition
    // console.log(a);
    // var b = (100 + 50) * 3; // Parentheses have the highest precedence
    // console.log(b);

// 6. Functions in JavaScript
// DRY = Do not Repeat Yourself
    // function avg(a, b) 
    // {
    //     return (a + b) / 2;
    // }
    // var c = avg(4, 6);
    // console.log("The average of 4 and 6 is", c);

    // Function Expressions
    // var avg = function(a, b)
    // {
    //     return (a + b) / 2;
    // }
    // var c = avg(4, 6);
    // console.log("The average of 4 and 6 is", c);

    // Arrow Functions
    // var avg = (a, b) => {
    //     return (a + b) / 2;
    // }
    // var c = avg(4, 6);
    // console.log("The average of 4 and 6 is", c);

    // One line Arrow Function
    // var avg = (a, b) => (a + b) / 2;
    // var c = avg(4, 6);
    // console.log("The average of 4 and 6 is", c);

    // Functions are first-class citizens in JavaScript
    // They can be passed as arguments to other functions
    // They can be returned from other functions
    // They can be assigned to variables

    // Higher-order functions
    // function greet(name) 
    // {
    //     return "Hello, " + name + "!";
    // }
    // function callGreet(greetFunction, name)  // greetFunction = greet, name = "Alice"
    // {
    //     return greetFunction(name);
    // }
    // console.log(callGreet(greet, "Alice"));

    // Closures
    // function outerFunction(outerVariable) 
    // {
    //     return function innerFunction(innerVariable) 
    //            {
    //                  console.log("Outer Variable: " + outerVariable);
    //                  console.log("Inner Variable: " + innerVariable);
    //            }
    // }
    // var newFunction = outerFunction("outside");
    // newFunction("inside");

    // Recursion
    // function factorial(n) {
    //     if (n === 0 || n === 1) {
    //         return 1;
    //     }
    //     return n * factorial(n - 1);
    // }
    // console.log(factorial(5));

// 7. Conditional Statements in JavaScript
    // var age = 18;
    // Single if statement
    // if (age > 18) {
    //     console.log("You are eligible to vote.");
    // }

    // If-else statement
    // if (age < 18) 
    // {
    //     console.log("You are not eligible to vote.");
    // }
    // else 
    // {
    //     console.log("You are eligible to vote.");
    // }

    // If-else-if ladder
    // if (age < 13) 
    // {
    //     console.log("You are a child.");
    // }
    // else if (age >= 13 && age < 20) 
    // {
    //     console.log("You are a teenager.");
    // }
    // else if (age >= 20 && age < 60)
    // {
    //     console.log("You are an adult.");
    // }
    // else 
    // {
    //     console.log("You are a senior citizen.");
    // }

    // Nested if statements
    // var num = 10;
    // if (num > 0)
    // {
    //     console.log("The number is positive.");
    //     if (num % 2 === 0)
    //     {
    //         console.log("The number is even.");
    //     }
    //     else
    //     {
    //         console.log("The number is odd.");
    //     }
    // }
    // else
    // {
    //     console.log("The number is negative.");
    //     if (num % 2 === 0)
    //     {
    //         console.log("The number is negative and even.");
    //     }
    //     else
    //     {
    //         console.log("The number is negative and odd.");
    //     }
    // }

    // Switch statement
    // var day = 3;
    // switch (day)
    // {
    //     case 1:
    //         console.log("Monday");
    //         break;
    //     case 2:
    //         console.log("Tuesday");
    //         break;
    //     case 3:
    //         console.log("Wednesday");
    //         break;
    //     case 4:
    //         console.log("Thursday");
    //         break;
    //     case 5:
    //         console.log("Friday");
    //         break;
    //     case 6:
    //         console.log("Saturday");
    //         break;
    //     case 7:
    //         console.log("Sunday");
    //         break;
    //     default:
    //         console.log("Invalid day");
    // }

    // Ternary operator
    // var age = 18;
    // var eligibility = (age >= 18) ? "You are eligible to vote." : "You are not eligible to vote.";
    // console.log(eligibility);

// 8. Loops in JavaScript
    // For loop
    // var arr = [1, 2, 3, 4, 5];
    // for (var i = 0; i < arr.length; i++)
    // {
    //     console.log(arr[i]);
    // }

    // While loop
    // var i = 0;
    // while (i < arr.length)
    // {
    //     console.log(arr[i]);
    //     i++;
    // }

    // Do-while loop
    // var i = 0;
    // do
    // {
    //     console.log(arr[i]);
    //     i++;
    // }
    // while (i < arr.length);

    // For-each loop
    // arr.forEach(function(element) {
    //     console.log(element);
    // });

    // For-of loop
    // for (var element of arr)
    // {
    //     console.log(element);
    // }

    // For-in loop (used for objects)
    // var obj = {name: "John", age: 30, city: "New York"};
    // for (var key in obj)
    // {
    //     console.log(key + ": " + obj[key]);
    // }

    // Break and continue statements
    // for (var i = 0; i < arr.length; i++)
    // {
    //     if (arr[i] === 3)
    //     {
    //         break; // exits the loop when arr[i] is 3
    //     }
    //     console.log(arr[i]);
    // }
    // for (var i = 0; i < arr.length; i++)
    // {
    //     if (arr[i] === 3)
    //     {
    //         continue; // skips the current iteration when arr[i] is 3
    //     }
    //     console.log(arr[i]);
    // }

    // Nested loops
    // var n = 5
    // for (var i = 1; i <= n; i++)
    // {
    //     var row = "";
    //     for (var j = 1; j <= i; j++)
    //     {
    //         row += "* ";
    //     }
    //     console.log(row);
    // }

    // Infinite loops (be careful with these!)
    // while (true)
    // {
    //     console.log("This is an infinite loop.");
    // }
    // Do not run infinite loops in your browser as they can crash it!
    
    // Looping through strings
    // var str = "Hello";
    // for (var i = 0; i < str.length; i++) 
    // {
    //     console.log(str[i]);
    // }

    // Looping through NodeLists (e.g., from document.querySelectorAll)
    // var elements = document.querySelectorAll("p");
    // elements.forEach(function(element) {
    //     console.log(element.textContent);
    // });

    // Looping through Maps and Sets
    // var myMap = new Map();
    // myMap.set("name", "John");
    // myMap.set("age", 30);
    // myMap.forEach(function(value, key) {
    //     console.log(key + ": " + value);
    // });
    // var mySet = new Set();
    // mySet.add(1);
    // mySet.add(2);
    // mySet.add(3);
    // mySet.forEach(function(value) {
    //     console.log(value);
    // });

    // Looping through arrays with forEach and arrow functions
    // var arr = [1, 2, 3, 4, 5];
    // arr.forEach(element => console.log(element));   

    // Looping through objects with Object.keys and forEach
    // var obj = {name: "John", age: 30, city: "New York"};
    // Object.keys(obj).forEach(key => console.log(key + ": " + obj[key]));

// 9. Arrays Methods in JavaScript
    var arr = [1, 2, 3, 4, 5];
    // Original array traversal
    // for(var i = 0; i < arr.length; i++)
    // {
    //     console.log(arr[i]);
    // }

    // Adding, removing and replacing elements
    // arr.push(6); // adds 6 at the end of the array
    // arr.unshift(0); // adds 0 at the beginning of the array

    // arr.pop(); // removes the last element of the array
    // arr.shift(); // removes the first element of the array

    // arr.splice(2, 0, 2.5); // adds 2.5 at index 2 without removing any element
    // arr.splice(2, 1); // removes 1 element at index 2
    // arr.splice(2, 1, 2.5); // replaces 1 element at index 2 with 2.5

    // console.log(arr);

    // Searching and checking for elements
    // console.log(arr.indexOf(3)); // returns the index of the first occurrence of 3, otherwise -1
    // console.log(arr.lastIndexOf(3)); // returns the index of the last occurrence of 3
    
    // console.log(arr.includes(3)); // returns true if 3 is present in the array, otherwise false
    
    // console.log(arr.find(element => element > 3)); // returns the first element that is greater than 3, otherwise undefined
    // console.log(arr.findIndex(element => element > 3)); // returns the index of the first element that is greater than 3, otherwise -1

    // Transforming and iterating over arrays
    // arr.forEach(element => console.log(element)); // executes a provided function once for each array element

    // var newArr = arr.map(element => element * 2); // creates a new array with the results of calling a provided function on every element in the array
    // console.log(newArr);

    // var filteredArr = arr.filter(element => element > 3); // creates a new array with all elements that pass the test implemented by the provided function
    // console.log(filteredArr);

    // var sum = arr.reduce((accumulator, currentValue) => accumulator + currentValue, 0); // executes a reducer function on each element of the array, resulting in a single output value
    // console.log(sum);

    // Utility and cleanup methods
    // var newArr = arr.slice(1, 4); // returns a shallow copy of a portion of the array into a new array object selected from start to end (end not included)
    // console.log(newArr);

    // var newArr = arr.concat([6, 7, 8]); // returns a new array that is the result of merging the original array with the provided array(s)
    // console.log(newArr);

    // var str = arr.join(", "); // joins all elements of the array into a string, separated by the specified separator (default is comma)
    // console.log(str);

    // var str = "I love JavaScript";
    // var words = str.split(" "); // splits a string into an array of substrings based on the specified separator
    // console.log(words);

    // arr.sort((a, b) => a - b); // sorts the elements of the array in ascending order
    // console.log(arr);
    // arr.sort((a, b) => b - a); // sorts the elements of the array in descending order
    // console.log(arr);

    // var reversedArr = arr.reverse(); // reverses the order of the elements in the array
    // console.log(reversedArr);
