// 12. DOM Manipulation in JavaScript
    // DOM stands for Document Object Model. It is a programming interface for HTML and XML documents. It represents the structure of a document as a tree of objects, where each object corresponds to a part of the document (such as an element, attribute, or text).
    // DOM manipulation refers to the process of changing the structure, style, or content of a web page using JavaScript. This can be done by accessing and modifying the DOM elements using various methods and properties provided by the DOM API.
    // Here are some common DOM manipulation techniques in JavaScript:

    // Accessing DOM Elements
    // You can access DOM elements using methods like getElementById, getElementsByClassName, getElementsByTagName, querySelector, and querySelectorAll. For example:
        // const firstContainer = document.getElementById('firstContainer');   // Accessing an element by its Unique ID
        // console.log(firstContainer);

        // const containers = document.getElementsByClassName('container');    // Accessing elements by their Class Name (returns a collection of elements)
        // console.log(containers);

        // const paragraphs = document.getElementsByTagName('p');  // Accessing elements by their Tag Name (returns a collection of elements)
        // console.log(paragraphs);

        // const firstParagraph = document.querySelector('.container p');  // Accessing elements using CSS selectors (returns the first matching element)
        // console.log(firstParagraph);

        // const allParagraphs = document.querySelectorAll('.container p');  // Accessing elements using CSS selectors (returns a NodeList of all matching elements)
        // console.log(allParagraphs);

    //  Changing the Content of DOM Elements
    // You can change the content of DOM elements using properties like innerHTML, textContent, and innerText. For example:
        // const firstParagraph = document.getElementById('firstPara');
        // firstParagraph.innerHTML = '<strong>This is the updated content of the first paragraph using innerHTML.</strong>';   // This will update the content of the first paragraph and can include HTML tags
        // firstParagraph.textContent = 'This is the updated content of the first paragraph using textContent.';   // This will update the content of the first paragraph as plain text, ignoring any HTML tags
        // firstParagraph.innerText = 'This is the updated content of the first paragraph using innerText.';   // This will update the content of the first paragraph as plain text, but it will also consider the CSS styles (like display: none) when rendering the text

    // Set CSS Styles Using JavaScript
    // You can set CSS styles of DOM elements using the style property. For example:
        // const firstContainer = document.getElementById('firstContainer');
        // firstContainer.style.backgroundColor = 'lightblue';   // This will set the background color of the first container to light blue
        // firstContainer.style.fontSize = '20px';  // This will set the font size of the first container to 20 pixels
        // firstContainer.style.padding = '10px';    // This will set the padding of the first container to 10 pixels
        // firstContainer.style.cssText = 'color: red; border: 1px solid black;';   // This will set multiple CSS properties at once using cssText

    // Manipulate Element Attributes
    // You can manipulate the attributes of DOM/HTML elements attributes(id, src, href, alt,...etc) using methods like setAttribute, getAttribute, and removeAttribute. For example:
        // let imageElement = document.getElementById('imageId').getAttribute('src');   // This will get the value of the 'src' attribute of the image element
        // console.log(imageElement);
        // document.getElementById('imageId').setAttribute('src', 'image2.jpg');   // This will change the value of the 'src' attribute of the image element to 'image2.jpg'
        // document.getElementById('imageId').removeAttribute('src');  // This will remove the 'src' attribute from the image element

    // Manipulate the Class Attribute
    // You can manipulate the class attribute of DOM elements using the classList property. For example:
        // const secondContainer = document.getElementById('secondContainer');
        // secondContainer.classList.add('bg-red');   // This will add a new class to the second container
        // secondContainer.classList.remove('container');    // This will remove the 'container2' class from the second container
        // secondContainer.classList.toggle('bg-red');   // This will toggle the 'bg-red' class on the second container (add it if it's not present, remove it if it is present)
        // secondContainer.classList.contains('container2');   // This will check if the second container has the 'container2' class and return true or false

    // Create, Add and Remove DOM Elements
    // You can create new DOM elements using the createElement method, add them to the document using methods like appendChild/append and before/insertBefore, and remove them using the removeChild/remove method. For example:
        // const newParagraph = document.createElement('p');   // This will create a new paragraph element
        // newParagraph.textContent = 'This is a new paragraph created using JavaScript.';  // This will set the text content of the new paragraph
        // document.getElementById('thirdContainer').appendChild(newParagraph);   // This will add the new paragraph to the third container
        // document.getElementById('thirdContainer').append(newParagraph);  // This is an alternative modern way to add the new paragraph to the third container

        // const firstContainer = document.getElementById('firstContainer');
        // const newButton = document.createElement('button');   // This will create a new button element
        // newButton.textContent = 'New Button';    // This will set the text content of the new button
        // firstContainer.before(newButton, firstContainer.firstChild);   // This will insert the new button before the first child of the first container
        // firstContainer.after(newButton, firstContainer.firstChild);   // This is an alternative way to insert the new button before the first child of the first container

        // firstContainer.removeChild(firstContainer.querySelector('button'));  // This will remove the first button from the first container
        // newButton.remove();  // This will remove the new button from the document (alternative modern way to remove an element) 

    // These are just some of the basic techniques for DOM manipulation in JavaScript. There are many more methods and properties available in the DOM API that you can use to create dynamic and interactive web pages.
    // It's important to note that when manipulating the DOM, it's best practice to minimize the number of changes you make to the DOM, as it can be expensive in terms of performance. Instead, you can make changes to a document fragment or use techniques like batching updates to improve performance.
    // DOM manipulation is a powerful tool for creating dynamic and interactive web pages, but it should be used judiciously to ensure good performance and maintainability of your code.

// 13. Event Handling in JavaScript
    // Event handling in JavaScript refers to the process of responding to user interactions or other events that occur in the browser. Events can be triggered by various actions, such as clicking a button, hovering over an element, submitting a form, or even loading a page.
    // In JavaScript, you can handle events using event listeners. An event listener is a function that is called when a specific event occurs on an element. You can attach event listeners to elements using methods like addEventListener or by setting the event handler properties directly on the element.
    // create an form html for this and new script5.js for event handling practice
