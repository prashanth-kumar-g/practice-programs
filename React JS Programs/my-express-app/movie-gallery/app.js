const express = require('express');
const path = require('path');
const expressLayouts = require('express-ejs-layouts');

const app = express();
const port = 3001;

// Movies Data
const movies = [
  { title: 'Inception', rating: 8.8 },
  { title: 'The Dark Knight', rating: 9.0 },
  { title: 'Interstellar', rating: 8.6 },
  { title: 'The Flash', rating: 6.9 },
  { title: 'Tenet', rating: 7.5 },
];

// View Engine Setup
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

// Middleware
app.use(expressLayouts);
app.set('layout', 'layout');
app.use(express.static(path.join(__dirname, 'public')));

// Route
app.get('/', (req, res) => {
  res.render('index', { movies });
});

// Start Server
app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
