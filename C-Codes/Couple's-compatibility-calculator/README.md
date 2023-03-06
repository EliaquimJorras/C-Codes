## Couple's compatibility calculator

This code is based on a youtube video that talked about a way to calculate the chances of a couple getting along using their first names. Obviously it's just a math joke, but I thought it would be interesting to try implementing it in C.

I will attach the video link here, however it is in Portuguese which is my native language but don't worry I will explain the idea of the video here.

## The video idea

- Take the couple's first names. Example:
    ```
    Mary and Karl
    ```      
- Count how many times each letter appears in both names:
    ```
    - A letra M aparece 1 vez.
    - A letra A aparece 2 vezes: 1 em Mary e 1 em Karl.
    - A letra R aparece 2 vezes: 1 em Mary e 1 em Karl.
    - A letra Y aparece 1 vez.
    - A letra L aparece 1 vez.
    ```
- Write the values, from left to right, of occurrences of each letter.
    ```
    1 2 2 1 1
    ```
- Add the ends together and if there is a value left over, repeat it at the end.
    ```
    1 2 2 1 1
    2 3 2 = (1 + 1) (2 + 1) 2 [remaining]
    4 3 = (2 + 2) 3 [remaining]
    ```
- The goal is to carry out the above process until you have only two digits, or exactly 100, and then conclude that:
    ```
    Mary and Karl have a 43% chance of getting along
    ```

## Mentioned video

 - [Video explaining how to calculate couple's compatibility](https://www.youtube.com/watch?v=ssbHMs6EOhs)
