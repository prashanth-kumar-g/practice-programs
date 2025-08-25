const express = require('express');
const path = require('path');
const app = express();
const port = 3002;

// Middleware
app.set('view engine', 'pug');
app.set('views', path.join(__dirname, 'views'));
app.use(express.urlencoded({ extended: true }));
app.use('/assets', express.static(path.join(__dirname, 'public/images')));
app.use(express.static('public'));

// Routes
app.get('/', (req, res) => {
  const recipe = {
    name: 'Veggie Pasta',
    ingredients: ['Pasta', 'Tomatoes', 'Bell Peppers', 'Olive Oil', 'Basil'],
    steps: [
      'Boil the pasta.',
      'Sauté vegetables in olive oil.',
      'Add tomatoes and cook.',
      'Mix pasta and vegetables.',
      'Serve hot with basil garnish.'
    ]
  };
  res.render('recipe', { recipe });
});

app.get('/feedback', (req, res) => {
  res.render('feedback');
});

app.post('/feedback', (req, res) => {
  const { name, message } = req.body;
  res.send(`<h2>Thank you, ${name}!</h2><p>Your message: "${message}" has been received.</p>`);
});

app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
