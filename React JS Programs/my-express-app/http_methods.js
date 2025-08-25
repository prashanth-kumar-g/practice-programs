import express from 'express';

const app = express();

const port = 3001;

const users = ['Alice', 'Bob', 'Cat'];

app.use(express.json());

app.get('/', (req, res) => {
    res.json(users);
});

app.post('/users', (req, res) => {

    const newUser = req.body.name;

    users.push(newUser);

    res.send(`User ${newUser} added`);
});

app.put('/users/:index', (req, res) => {
    
    const i = req.params.index;

    const newName = req.body.name;

    users[i] = newName;

    res.send(`User at index ${i} updated to ${newName}`);
});

app.delete('/users/:index', (req,res) => {
    
    const i = req.params.index;

    const removedUser = users.splice(i, 1);

    res.send(`User ${removedUser} deleted`);
});

app.listen(port, () => {
    console.log(`Running at http://localhost:${port}`);
});
