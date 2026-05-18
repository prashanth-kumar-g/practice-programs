// 13. Event Handling in JavaScript
    // Event handling in JavaScript refers to the process of responding to user interactions or other events that occur in the browser. Events can be triggered by various actions, such as clicking a button, hovering over an element, submitting a form, or even loading a page.
    // In JavaScript, you can handle events using event listeners. An event listener is a function that is called when a specific event occurs on an element. You can attach event listeners to elements using methods like addEventListener or by setting the event handler properties directly on the element.
    
    // Here are some common techniques for event handling in JavaScript:

    // 1. Inline HTML Handlers
    // You can add event handlers directly to HTML elements using attributes like onclick, onmouseover, onsubmit, etc. For example:
        <button onclick="alert('Button clicked!')">Click Me</button> ; // This will display an alert message when the button is clicked. (button is an HTML element, onclick is the event handler attribute, and alert('Button clicked!') is the JavaScript code that will be executed when the event occurs)
        
        <button onclick="handleClick()">Click Me</button> // This will call the handleClick function when the button is clicked. (button is an HTML element, onclick is the event handler attribute, and handleClick() is the JavaScript function that will be executed when the event occurs)
        function handleClick() {
            alert('Button clicked!');
        }

    // 2. DOM Property Handlers
    // You can set event handlers using DOM properties on the elements. For example:
        const button = document.getElementById('myButton');
        button.onclick = function() {
            alert('Button clicked!');
        };  // This will set the onclick event handler for the button element to a function that displays an alert message when the button is clicked.
        
        button.onclick = handleClick;  // This will set the onclick event handler for the button element to the handleClick function, which will be called when the button is clicked.

    // 3. addEventListener Handler (most recommended)
    // You can use the addEventListener method to attach event listeners to elements. This method allows you to attach multiple event listeners to the same element and provides better control over the event handling. For example:
        const button = document.getElementById('myButton');
        button.addEventListener('click', function() {
            alert('Button clicked!');
        });  // This will add a click event listener to the button element that displays an alert message when the button is clicked.

        const button = document.getElementById('myButton');
        button.addEventListener('click', () => {
            alert('Button clicked!');
        });  // This will add a click event listener to the button element that displays an alert message when the button is clicked, using an arrow function for the event handler.

        button.addEventListener('click', handleClick);  // This will add a click event listener to the button element that calls the handleClick function when the button is clicked.

    // 4. Removing Event Listeners
    // You can remove event listeners using the removeEventListener method. This method requires you to pass the same function reference that was used to add the event listener. For example:    
        const button = document.getElementById('myButton');
        function handleClick() {
            alert('Button clicked!');
        }
        button.addEventListener('click', handleClick);  // This will add a click event listener to the button element that calls the handleClick function when the button is clicked.
        button.removeEventListener('click', handleClick);   // This will remove the click event listener from the button element, so clicking the button will no longer trigger the alert message.

        // It's important to note that when using addEventListener, you need to use the same function reference when removing the event listener. If you use an anonymous function or a different function reference, the event listener will not be removed.

    // Event Types
    // There are many different types of events that you can listen for in JavaScript
    // Some common event types include:
        // - Mouse Events: click, dblclick, mouseover, mouseout, mousemove, mousedown, mouseup
        // - Keyboard Events: keydown, keyup, keypress
        // - Form Events: submit, change, input, focus, blur
        // - Window Events: load, resize, scroll, unload
        // - Touch Events: touchstart, touchmove, touchend
        // - Drag and Drop Events: dragstart, drag, dragenter, dragleave, drop, dragend
        // - Clipboard Events: copy, cut, paste
        // - Media Events: play, pause, ended, volumechange
        // - Animation Events: animationstart, animationend, animationiteration
        // - Transition Events: transitionstart, transitionend, transitionrun
    // These are just some of the many event types available in JavaScript. You can listen for these events on various elements in your web page to create interactive and dynamic user experiences.

    // Event Object
    // When an event occurs, an event object is created and passed to the event handler function. This event object contains information about the event, such as the type of event, the target element, and other relevant data. 
    // You can access this event object in your event handler function to get more information about the event and perform actions based on that information. For example:
        const button = document.getElementById('myButton');
        button.addEventListener('click', function(event) {
            console.log('Event Type:', event.type);  // This will log the type of the event (e.g., 'click')
            console.log('Target Element:', event.target);  // This will log the element that triggered the event (e.g., the button element)
            alert('Button clicked!');
        });  // This will add a click event listener to the button element that logs information about the event and displays an alert message when the button is clicked.

    // Event Propagation
    // When an event occurs on an element, it can propagate through the DOM tree in two phases: capturing and bubbling. 
    // In the capturing phase, the event is first captured by the outermost element and then propagated down to the target element. 
    // In the bubbling phase, the event is first triggered on the target element and then propagated up to the outermost element. You can control event propagation using methods like stopPropagation and stopImmediatePropagation. For example:
        const parentElement = document.getElementById('parent');
        const childElement = document.getElementById('child');
        
        parentElement.addEventListener('click', function() {
            console.log('Parent element clicked!');
        });  // This will add a click event listener to the parent element that logs a message when the parent element is clicked.
        
        childElement.addEventListener('click', function(event) {
            console.log('Child element clicked!');
            event.stopPropagation();  // This will stop the event from propagating to the parent element, so only the child element's click event will be triggered.
        });  // This will add a click event listener to the child element that logs a message and stops event propagation when the child element is clicked.

    // Event Delegation
    // Event delegation is a technique where you attach a single event listener to a parent element instead of attaching event listeners to multiple child elements. This is useful when you have a large number of child elements or when the child elements are dynamically added or removed from the DOM. 
    // The event listener on the parent element can handle events for all of its child elements by using the event object's target property to determine which child element triggered the event. For example:
        const parentElement = document.getElementById('parent');
        parentElement.addEventListener('click', function(event) {
            if (event.target && event.target.matches('button.childButton')) {
                console.log('Child button clicked:', event.target);  // This will log the child button that was clicked, using event delegation to handle clicks on all child buttons within the parent element.
            }
        });  // This will add a click event listener to the parent element that uses event delegation to handle clicks on child buttons with the class 'childButton'.

    // Preventing Default Behaviour
    // Certain elements have default actions(e.g., links navigating to URLS).
    // Use preventDefault() to override them.
        const linkElement = document.querySelector('a');
        linkElement.addEventListener('click', (e) => {
        e.preventDefault();
        console.log("Link click prevented");
        });  // The link will not open when clicked, preventing default behaviour of an element

    // These are just some of the fundamental techniques for event handling in JavaScript. There are numerous other events and methods available in the JavaScript Event API that you can use to create interactive and responsive web applications.
    // It's important to remember that event handling is a core aspect of creating dynamic web pages. When working with events, consider performance implications, especially when using event delegation for elements with many children.
    // Additionally, always clean up event listeners when they're no longer needed (using removeEventListener) to prevent memory leaks and ensure your application runs efficiently.
    // Understanding event handling, event propagation, and event delegation is essential for building robust, interactive web applications. Mastering these techniques will significantly enhance your ability to create responsive user experiences.
