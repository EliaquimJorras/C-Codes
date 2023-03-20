# Manipulating Strings
This code came from an attempt to replicate the python language's Split and Strip methods, as well as practice converting uppercase to lowercase and vice versa.

## Explaining The Functions Created

### Strip Function
This function is responsible for removing possible additional white spaces. Example:

```c
phrase = Strip("   Eliaquim   Jorras    ");
// phrase is equals to "Eliaquim Jorras"
```

### Split Function
This function is responsible for storing the substrings of a name, example:

```c
List = Split("Eliaquim Jorras Alves");
// List[0] is equals to "Eliaquim"
// List[1] is equals to "Jorras"
// List[2] is equals to "Alves"
```

### ToUppercase Function

#### Explaning The 'While'

```c
while( (strHelp[i] = str[i]) ) i++;
```

Note that the condition has an assignment. The C language will take the contents of this assignment and interpret it as true or false and the language interprets everything non-zero as true and everything equal to zero as false.

So, as long as the character in 'str' is a valid character, it will transfer to 'strHelp' and the 'i' index will increment. When you get to '\0', the condition will be false and the loop ends because, guess what, the '\0' character has a binary code equal to zero. And you don't even need to put the \0 in aux after the loop, because that will be the last assignment.

#### Explaning The 'For'

```c
for (int i = 0; strHelp[i] != '\0'; i++)
    if (strHelp[i] >= 'a' && strHelp[i] <= 'z')
        strHelp[i] = strHelp[i] - 'a' + 'A';
```

- strHelp[i] - 'a' is to know how many jumps this character has away from the letter 'a'
- +'A' I take the distance and add it to 'A' to arrive at the same letter but capitalized

Note: the logic is similar for converting an uppercase letter to lowercase.