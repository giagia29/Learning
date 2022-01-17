Line 8 to 12:
- Ask the user to enter the array elements:
+ It must have 20 integers.
+ It has to be sorted.
Line 13: 
- Ask the user to enter the target.
Line 15 to Line 40:
- Whenever reach an element that is larger than the target, we don't have to search for the rest of the array as all remaining elements will be larger than the target. (Line 23)
- This will save running times for the problem.
- For every elements, find all the elements after it that the target subtract equals to that element. (Line 29)
- once found, print out the result. (Line 35)
- increment the number of matched pair.(Line 36)
- after found then break to move to the next elements. (Line 37)