## Manipulating Strings
Este código surgiu da tentativa de réplicar os métodos Split e Strip da linguagem python, bem como praticar a conversão de letras maiusculas para minusculas e vice-versa.

## ToUppercase Function

### Explaning The 'While'
Note that the condition has an assignment. The C language will take the contents of this assignment and interpret it as true or false and the language interprets everything non-zero as true and everything equal to zero as false.

So, as long as the character in str is a valid character, it will transfer to aux and the i index will increment. When you get to '\0', the condition will be false and the loop ends because, guess what, the '\0' character has a binary code equal to zero. And you don't even need to put the \0 in aux after the loop, because that will be the last assignment.

### Explaning The 'For'
aux[i] - 'a' é pra saber quantos pulos esse meu caractere tem de distância do 'a' ... + 'A' pego a distancia e somo ao 'A' para chegar na mesma letra porém maiscula