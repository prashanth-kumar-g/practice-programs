// 9. Arrays Methods in JavaScript
    // var arr = [1, 2, 3, 4, 5];
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

// 10. String Methods in JavaScript
    // var str = "I love JavaScript";
    // Original string traversal
        // for(var i = 0; i < str.length; i++)
        // {
        //     console.log(str[i]);
        // }
    
    // Searching and checking
        // console.log(str.indexOf("JavaScript")); // returns the index of the first occurrence of "JavaScript", otherwise -1
        // console.log(str.lastIndexOf("a")); // returns the index of the last occurrence of "a", otherwise -1

        // console.log(str.includes("love")); // returns true if "love" is present in the string, otherwise false

        // console.log(str.startsWith("I")); // returns true if the string starts with "I", otherwise false
        // console.log(str.endsWith("Script")); // returns true if the string ends with "Script", otherwise false

    // Extracting Parts of a string
        // console.log(str.substring(2, 8)); // returns a portion of the string from start to end (end not included)
        // console.log(str.slice(2, 8)); // also returns a portion of the string from start to end (end not included)
        // console.log(str.substr(2, 6)); // returns a portion of the string from start with the specified length

        // console.log(str.charAt(2)); // returns the character at the specified index
        // console.log(str.charCodeAt(2)); // returns the Unicode of the character at the specified index

    // Changing case and formatting
        // console.log(str.toUpperCase()); // returns the string converted to uppercase
        // console.log(str.toLowerCase()); // returns the string converted to lowercase
        
        // console.log(str.trim()); // removes whitespace from both ends of the string
        // console.log(str.trimStart()); // removes whitespace from the start of the string
        // console.log(str.trimEnd()); // removes whitespace from the end of the string

        // console.log(str.padStart(20, " ")); // pads the string with the specified character (default is space) at the start
        // console.log(str.padEnd(20, " ")); // pads the string with the specified character (default is space) at the end

        // console.log(str.repeat(3)); // returns a new string that is the result of repeating the original string a specified number of times

        // console.log(str.concat(" and Python")); // concatenates the string with another string and returns a new string, or simply use the + operator: console.log(str + " and Python");

    // Replacing, Splitting and Utility methods
        // console.log(str.replace("JavaScript", "Python")); // returns a new string with the first occurrence of "JavaScript" replaced by "Python"
        // console.log(str.replaceAll("a", "o")); // returns a new string with all occurrences of "a" replaced by "o"

        // var words = str.split(" "); // splits the string into an array of substrings based on the specified separator
        // console.log(words);

        // var newStr = words.join(", "); // joins all elements of the array into a string, separated by the specified separator (default is comma)
        // console.log(newStr);

        // var newStr = str.split(" ").reverse().join(" "); // reverses the order of the words in the string
        // console.log(newStr);

        // var newStr = str.split(" ").sort().join(" "); // sorts the words in the string in alphabetical order
        // console.log(newStr);

// 11. Dates in JavaScript
    // Way to create a Date object
        // var date = new Date(); // creates a new Date object with the current date and time
        // console.log(date);

        // var date = new Date("2024-01-01"); // creates a new Date object with the specified date from a string
        // console.log(date);

        // var date = new Date(2024, 0, 1); // creates a new Date object with the specified year, month (0-based), and day
        // console.log(date);

        // var date = new Date("2024-01-01T10:30:00"); // creates a new Date object with the specified date and time from a string in ISO format
        // console.log(date);

        // var date = new Date(2024, 0, 1, 10, 30, 0); // creates a new Date object with the specified year, month (0-based), day, hour, minute, and second
        // console.log(date);

    // Getting and setting date components
        // var date = new Date();
        // console.log(date.getFullYear()); // returns the year of the date
        // console.log(date.getMonth()); // returns the month of the date (0-based)
        // console.log(date.getDate()); // returns the day of the month of the date
        // console.log(date.getHours()); // returns the hour of the date
        // console.log(date.getMinutes()); // returns the minute of the date
        // console.log(date.getSeconds()); // returns the second of the date
        // console.log(date);

        // date.setFullYear(2025); // sets the year of the date
        // date.setMonth(11); // sets the month of the date (0-based)
        // date.setDate(25); // sets the day of the month of the date
        // date.setHours(15); // sets the hour of the date
        // date.setMinutes(45); // sets the minute of the date
        // date.setSeconds(30); // sets the second of the date
        // console.log(date);

    // Date calculations and formatting
        // var date1 = new Date("2024-01-01");
        // var date2 = new Date("2024-12-31");
        // var timeDiff = date2.getTime() - date1.getTime(); // returns the difference in milliseconds between two dates
        // var daysDiff = timeDiff / (1000 * 3600 * 24); // converts the difference from milliseconds to days
        // console.log(daysDiff);

        // console.log(date.toDateString()); // returns the date portion of the date as a human-readable string
        // console.log(date.toTimeString()); // returns the time portion of the date as a human-readable string
        // console.log(date.toLocaleString()); // returns the date and time of the date as a human-readable string in the local format (based on the user's browser/locale settings, now its in en-IN format)
        // console.log(date.toLocaleString('en-US')); // returns the date and time of the date as a human-readable string in the specified locale format (in this case, US English)
        // console.log(date.toISOString()); // returns the date and time of the date in ISO format
        // console.log(date.toUTCString()); // returns the date and time of the date in UTC format
