#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(apiUrl, (error, response, body) => {
  if (error) {
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  const printCharacter = (index) => {
    if (index >= characters.length) {
      return;
    }

    request(characters[index], (error, response, body) => {
      if (error) {
        return;
      }

      const character = JSON.parse(body);
      console.log(character.name);
      printCharacter(index + 1);
    });
  };

  printCharacter(0);
});
