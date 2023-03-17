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
    - The letter 'M' appears 1 time.
    - The letter 'A' appears 2 times: 1 in Mary and 1 in Karl.
    - The letter 'R' appears 2 times: 1 in Mary and 1 in Karl.
    - The letter 'Y' appears 1 time.
    - The letter 'K' appears 1 time.
    - The letter 'L' appears 1 time.
    ```
- Write the values, from left to right, of occurrences of each letter.
    ```
    1 2 2 1 1 1
    ```
- Add the ends together and if there is a value left over, repeat it at the end.
    ```
    1 2 2 1 1 1
    2 3 3 = (1 + 1) (2 + 1) (2 + 1)
    5 3 = (2 + 3) 3 [remaining]
    ```
- The goal is to carry out the above process until you have only two digits, or exactly 100, and then conclude that:
    ```
    Mary and Karl have a 53% chance of getting along
    ```

## Mentioned video

 - [Video explaining how to calculate couple's compatibility](https://www.youtube.com/watch?v=ssbHMs6EOhs)
