// 14. Javascript Timing Events
    // The window object allows execution of code at specified time intervals. These time intervals are called timing events.
    // The two key methods to use with JavaScript for Timing Events are:

    // 1. setTimeout(function, milliseconds, arg1, arg2, ...)    // Executes a function, after waiting a specified number of milliseconds.
        setTimeout(myFunc, 1000);   // basic usage
        function myFunc() {
            console.log("World");
        }
        console.log("Hello");

        // (or) basic usage
        setTimeout(() => { console.log("World"); }, 1000);
        console.log("Hello");

        setTimeout((name) => { console.log(`Hello, ${name}!`); }, 3000, "Alice");   // with parameters

        <button onclick="myVar = setTimeout(myFunction, 3000)">Try it</button>  // its present on html element, when clicked it will call myFunction after 3 seconds
        function myFunction() {
        alert('Hello');
        }
        <button onclick="clearTimeout(myVar)">Stop it</button>  // its present on html element(for demo, i wrote here for learning purpose), it will immediately clear the setTimeout method when clicked

    // 2. setInterval(function, milliseconds, arg1, arg2, ...)   // Same as setTimeout(), but repeats the execution of the function continuously.
        let counter = 0;    // basic usage
        setInterval(myFunc, 1000);
        function myFunc() {
            counter++;
            console.log("World count:", counter);
        }

        // (Or) // basic usage
        let counter = 0;
        setInterval(() => {
            counter++;
            console.log("World count:", counter);
        }, 1000);

        // with parameters
        const names = ["Alice", "Bob", "Charlie", "Diana"];
        let index = 0;
        let intervalId = setInterval(() => {
            console.log(`Hello, ${names[index]}!`); // Grab the current name from the array
            index = (index + 1) % names.length; // Move to the next name (and loop back to 0 at the end)
        }, 1000);   // print names from list every 1 second
        setTimeout(() => { clearInterval(intervalId); }, 10000);    // clear interval after 10 seconds 

        // Display the current time every second
        setInterval(myTimer, 1000);
        function myTimer() {
            const d = new Date();
            document.getElementById("firstPara").innerText = d.toLocaleTimeString();
        }

// 15. localStorage & sessionStorage in JavaScript (only client side storage)
    // In JavaScript, localStorage is a built-in property of the window object that allows you to store key-value pairs in a user's web browser.
    // window object that allows you to store key-value pairs in a user's web browser. Unlike sessionStorage, data in localStorage has no expiration time; it persists even after the browser is closed or the computer is restarted.

    // You can interact with localStorage using these methods:

    // setItem(key, value)  // Adds a key and value to the storage or updates the value if the key already exists.
        localStorage.setItem('theme', 'dark');

    // getItem(key) // Retrieves the value associated with a specific key. Returns null if the key does not exist.
        const currentTheme = localStorage.getItem('theme');
        console.log(currentTheme);  // prints 'dark'

    // removeItem(key)  // Removes a specific item by its key.
        localStorage.removeItem('theme');
        
        const currentTheme = localStorage.getItem('theme');
        console.log(currentTheme);  // prints 'null'

    // clear()  // Deletes all key-value pairs stored for that specific domain.
        localStorage.clear();

    // localStorage only stores strings. To store complex data types like objects or arrays, you must convert them to a JSON string first and then parse them back when retrieving them.
        const user = { name: "Alex", age: 25 };     // JavaScript Object

        localStorage.setItem('user', JSON.stringify(user));     // Convert JavaScript Object to String using JSON.stringify() method and store them in localStorage

        const storedUser = JSON.parse(localStorage.getItem('user'));    // Retrieve String from the localStorage and Convert back String to JavaScript Object using JSON.parse() method
        console.log(storedUser);
    
    // The sessionStorage object let you store key/value pairs in the browser. The sessionStorage object stores data for only one session. The data is deleted when the browser is closed.
    // sessionStorage can be similarly used like localStorage with same methods like setItem(), getItem(), removeItem() and clear() but only for one session.

// 16. cookies in JavaScript (client sends data to server)
    // JavaScript cookies are small data stored on a user's device by a web browser.
    // These cookies play a crucial role in web development, enabling websites to store and retrieve information about user preferences, session states, and other data.

    // Creating Cookie in JavaScript    // Creating cookies in JavaScript involves using the document.cookie object to set key-value pairs and additional parameters.
        document.cookie = "courseName = webDevelopment bootcamp; expires = Thu, 5 March 2030 12:00:00 UTC; path = /";
        console.log(document.cookie);

    // Reading Cookie in JavaScript     // To extract specific values, developers often create functions that parse this string. Security considerations, like proper decoding and HttpOnly attributes, are crucial.
        function getCookie(cookieName) {
             const cookies = document.cookie.split('; ');
             for (const cookie of cookies) {
                 const [name, value] = cookie.split('=');
                 if (name === cookieName) {
                     return decodeURIComponent(value);
                 }
             }
             return null;
        }
        const courseName = getCookie('courseName');
        console.log('Course Name:', courseName);

    // Changing Cookie in JavaScript    // JavaScript enables the modification of cookies by updating their values or attributes. Developers use the document.cookie property to both read and write cookies.
        document.cookie = "courseName=WebDevelopmentBootcamp; expires=Thu, 5 March 2030 12:00:00 UTC; path=/";
        console.log(document.cookie);    // original set cookie
        function changeCookieValue(cookieName, newValue) {
            document.cookie = `${cookieName}=${newValue}; expires=Thu, 5 March 2030 12:00:00 UTC; path=/`;
        }
        changeCookieValue('courseName', 'AdvancedJavaScriptCourse');
        console.log(document.cookie);    // cookie after course name change

    // Deleting Cookie in JavaScript    // JavaScript provides a way to delete cookies by setting their expiration date in the past. When a cookie's expiration date is in the past, the browser automatically removes it.
        document.cookie = "courseName=WebDevelopmentBootcamp; expires=Thu, 5 March 2030 12:00:00 UTC; path=/";
        console.log(document.cookie);   // original set cookie
        function deleteCookie(cookieName) {
            document.cookie = `${cookieName}=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;`;
        }
        deleteCookie('courseName');
        console.log(document.cookie);   // cookie deleted, displays empty string

// 17. JSON in JavaScript
    // JSON (JavaScript Object Notation) is a text-based, lightweight format for storing and exchanging data.
    // While it is derived from JavaScript's object syntax, it is language-independent and supported by virtually all modern programming languages.

    // JavaScript provides a built-in JSON object with two primary methods for converting data:

    // JSON.parse(text)    // Converts a JSON string into a native JavaScript object. This process is known as deserialization.
        const jsonString = '{"name":"Alice", "age":25}';
        const userObj = JSON.parse(jsonString);
        console.log(userObj); // prints entire javascript object
        console.log(userObj.name); // Output: Alice

    // JSON.stringify(object): Converts a JavaScript object into a JSON string. This process is known as serialization.
        const userObj = { name: "Bob", age: 30 };
        const jsonString = JSON.stringify(userObj);
        console.log(jsonString); // Output: '{"name":"Bob","age":30}'    // prints json string

    // Nested JavaScript Objects (An Object Inside an Object)
        const employee = {
            id: 101,
            name: "Charlie",
            department: {       // Nested JavaScript Object:
                deptName: "Engineering",
                location: "Building A"
            }
        };

        const nestedJsonString = JSON.stringify(employee);      // --- SERIALIZATION (Object to JSON String) ---
        console.log(nestedJsonString);       // Output: '{"id":101,"name":"Charlie","department":{"deptName":"Engineering","location":"Building A"}}'

        const parsedEmployee = JSON.parse(nestedJsonString);     // --- DESERIALIZATION (JSON String back to Object) ---
        console.log(parsedEmployee);    // prints entire javascript object
        console.log(parsedEmployee.department.deptName); // Output: Engineering    // You use dot notation sequentially to drill down into the nested object.

    // Arrays Inside JSON (Lists of Data)
        const course = {
            title: "JavaScript 101",
            skillsTaught: ["Variables", "Functions", "JSON"],   // Array inside a JavaScript Object
            students: [                                         // Array of Objects inside a JavaScript Object
                { name: "Dave", grade: "A" },
                { name: "Eva", grade: "B" }
            ]
        };

        const arrayJsonString = JSON.stringify(course);     // --- SERIALIZATION (Object to JSON String) ---
        console.log(arrayJsonString);   // Output: '{"title":"JavaScript 101","skillsTaught":["Variables","Functions","JSON"],"students":[{"name":"Dave","grade":"A"},{"name":"Eva","grade":"B"}]}'
        
        const parsedCourse = JSON.parse(arrayJsonString);       // --- DESERIALIZATION (JSON String back to Object) ---
        console.log(parsedCourse);      // prints entire javascript object
        console.log(parsedCourse.skillsTaught[1]); // Output: Functions    // You can access array elements using index numbers, just like regular arrays.
        console.log(parsedCourse.students[0].name); // Output: Dave    // You use dot notation sequentially to drill down into the nested object.

    // Allowed Data Types in JSON String: Strings, Numbers, Objects, Arrays, Booleans, and null.
    // Forbidden Data Types in JSON String: Functions, undefined, Symbols, and NaN.
    // An JavaScript Object supports all of the above data types, but JSON String doesnt support all data types as it is different from JavaScript Object.
    // Valid JSON string: '{"name": "Alice", "age": 25, "isStudent": true, "skills": ["JS", "HTML"], "address": null}'
    // Valid JS object:  { name: 'Alice', age: 25, isStudent: true, skills: ['JS', 'HTML'], greet: function() { return "Hi"; }, unassigned: undefined }
