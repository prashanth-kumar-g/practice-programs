const express = require('express');
const path = require('path');
const multer = require('multer');

const app = express();
const port = 3003;

// Set view engine
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

// Middleware
app.use(express.urlencoded({ extended: true }));
app.use('/uploads', express.static(path.join(__dirname, 'uploads')));
app.use(express.static('public'));

// Multer Setup
const storage = multer.diskStorage({
  destination: (req, file, cb) => cb(null, 'uploads/'),
  filename: (req, file, cb) => cb(null, Date.now() + '-' + file.originalname)
});

const upload = multer({ storage: storage });

// Routes
app.get('/', (req, res) => {
  res.render('form');
});

app.post('/submit', upload.single('screenshot'), (req, res) => {
  const { name, email } = req.body;
  const screenshot = req.file ? `/uploads/${req.file.filename}` : null;

  res.render('success', { name, email, screenshot });
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
