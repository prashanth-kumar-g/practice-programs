import express from 'express';

import router from './router.js';

import {user, username} from './controller.js';

const app = express();

const port = 3001;

app.get('/', (req, res) => {
    res.send("Hello Express");
});

app.get('/user/:username',user);

app.get('/search',username);

app.use('/admin',router);

app.listen(port, () => {
    console.log(`Running at http://localhost:${port}`);
});
