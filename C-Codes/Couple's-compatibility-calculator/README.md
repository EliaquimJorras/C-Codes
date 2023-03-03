## Couple's compatibility calculator

This code is based on a youtube video that talked about a way to calculate the chances of a couple working out using their first names. Obviously it's just a math joke, but I thought it would be interesting to try implementing it in C.

I will attach the video link here, however it is in Portuguese which is my native language but don't worry I will explain the idea of the video here.

## The video idea

- Pegue os primeiros nomes do casal. Example:
    ```
    Mary and Karl
    ```      
- Conte quantas vezes aparece cada letra nos ambos os nomes:
    ```
    - A letra M aparece 1 vez.
    - A letra A aparece 2 vezes: 1 em Mary e 1 em Karl.
    - A letra R aparece 2 vezes: 1 em Mary e 1 em Karl.
    - A letra Y aparece 1 vez.
    - A letra L aparece 1 vez.
    ```
- Escreva os valores, da esquerda para direita, das ocorrências de cada letra.
    ```
    1 2 2 1 1
    ```


## Mentioned video

 - [Video explaining how to calculate couple's compatibility](https://www.youtube.com/watch?v=ssbHMs6EOhs)
