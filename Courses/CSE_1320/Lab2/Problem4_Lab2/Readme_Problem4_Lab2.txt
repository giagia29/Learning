Line 89 and Line 90:
- Get the string from the keyboard.

From Line 63 to Line 83:
- Add the characters that have more than one appearance to a new characters array.
- if it's space character then skip. (Line 70).
- For every character, there is at least one appearance. That's why we set up sum = 1 inside the for loop for each element at position t. (Line 69)

From Line 74 to Line 79:
- Count the total appearance for each elements (Line 73) by calling a separate function called CountOccurence.
- If any character has the occurrence larger than 1, add to the new array.

Line 83: Once obtain an array contains characters that show up more than 1 times, we find how many different characters are there by calling function DifferentChar.

From Line 8 to Line 43:
- If the character is space then skip.
- Saying we are consider a character at position i, then we have to look through all the elements that stand before that characters, from 0 to i - 1, to see if there is any resemble characters.
-  If one character is found to be similar, break from the loop move to the next character of position i + 1.
(Line 24 to Line 29)
- If it is not marked as true, then add the character into the new array and increment the total numbers of different characters. (Line 36 to Line 40).
