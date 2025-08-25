/* ===================== REACT APPLICATION ENTRY POINT ===================== */
/* Initializes the React application and mounts the root component */

import React from 'react';
import ReactDOM from 'react-dom/client';  // React DOM rendering library
import './index.css';                     // Global styles
import App from './App';                  // Main application component

// -------- STYLE IMPORTS --------
// Import specialized styles in the same order as original project
import './styles/inputStyles.css';        /* Input forms & buttons styling */
import './styles/calculateStyles.css';    /* Statistical results & equations */
import './styles/graphStyles.css';        /* Chart containers layout */
import './styles/analysisStyles.css';     /* Comparison report styling */

// -------- APPLICATION RENDERING --------
// Create root element and render application
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  // StrictMode for highlighting potential problems
  <React.StrictMode>
    {/* Main application component */}
    <App />
  </React.StrictMode>
);