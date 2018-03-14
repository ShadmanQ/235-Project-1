# 235-Project-1
## Word Jumble

#### Rules: 
    - The player receives a scrambled word, they must guess the word to win the round.
    - They have three tries to guess the word
    - If the player wins the round, they receive a new more difficult word at the start of the round
    - The player has the option has to swap out the word, up to five times in a single game session. This is a lifeline.

#### Logic: 
    - Game displays a welcome message, explaining the rules
    - Goes through input file to find appropriate word and jumbles
    - Game starts by displaying current difficulty and word to solve
    - if guess is correct, win counter goes up, option to continue is presented
    - if yes, prior logic is continued, if not game stats are saved to text file
    - game difficulty goes up every 3 rounds, as high as the player is willing to go
