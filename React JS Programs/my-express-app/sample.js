import express from 'express';

const app = express();

const port = 3000;

app.get('/', (req, res) => {
    res.send("Hello, World!");
});

app.get('/express', (req, res) => {

    const id = req.query.id;

    if(id == null)
    {
        res.send("Express JS Sample");
    }
    
    if(id % 2 == 0)
    {
        res.send(`${id} is a even number (dynamic - query)`);
    }
    else
    {
        res.send(`${id} is a odd number (dynamic - query)`);
    }
});

app.get('/express/1', (req, res) => {
    res.send('1 is a odd number (static)');
});

app.get('/express/:id', (req, res) => {

    const id = req.params.id;

    if(id % 2 == 0)
    {
        res.send(`${id} is a even number (dynamic)`);
    }
    else
    {
        res.send(`${id} is a odd number (dynamic)`);
    }
});

app.listen(port, () => {
    console.log(`Running at http://localhost:${port}`);
});