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
