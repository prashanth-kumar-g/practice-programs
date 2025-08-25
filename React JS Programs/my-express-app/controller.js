export const user = (req,res) => {
    const username = req.params.username;
    res.send(`Hello ${username}`);
}

export const username = (req,res) => {
    const user = req.query.user;
    res.send(`Searching user ${user}`);
}

export const adminlogin = (req,res) => {
    res.send('This is admin login page');
}

export const adminsignup = (req,res) => {
    res.send('This is admin signup page');
}