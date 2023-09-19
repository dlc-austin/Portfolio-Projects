const express = require(`express`);
const app = express();

const PORT = 3000;

app.get (`/`, (req,res) => {
    res.sendFile(__dirname + '/public/pages/index.html');
})

app.get (`/about`, (req,res) => {
    res.sendFile(__dirname + `/public/pages/about.html`);
});

app.get (`/contact`, (req,res) => {
    res.sendFile(__dirname + `/public/pages/contact.html`);
});

app.use ((req, res) => {
    res.status(404).send(`<h1>404 NOT FOUND:</h1>
                        <p>Sorry family, the requested resource could not be found on the server :(</p>
                        `);
});

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);

});

