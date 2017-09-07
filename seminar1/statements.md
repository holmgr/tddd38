# Exercises: Statements

## Statements

### 1
Given the following for statement where line is a character array with length length.

```
for (int i = 0; i < length; ++i)
    if (line[i] == ’ ’)
        ++space_count;
```
Rewrite it as a corresponding while statement.

##### Answer
```
int i;
while(i < length) {
    if (line[i] == ’ ’)
        ++space_count;
    ++i;
}
```

### 2
Rewrite the for statement in exercise 1 above, so it steps through line using a pointer instead of
indexing.
Note 1: These dual constructs for accessing array elements shows two well-known idioms in C and C++;
the ”array indexing idiom” and the ”pointer idiom”.
Note 2: Using pointer arithmetic to step through an array is a source optimization technique frequently
used in C programs, by tradition. A modern C or C++ compiler may produce better code if you refrain
from this!

##### Answer
```
for (char* line_ptr = line; line_ptr != line + length; ++line_ptr)
    if (*line_ptr == ’ ’)
        ++space_count;
```

### 3
Rewrite the for statement in exercise 1 above, using range access functions.

##### Answer
```
for (auto it = begin(line); it < end(line); ++it)
    if (*it == ’ ’)
        ++space_count;
```

### 4
Rewrite the for statement in exercise 1 above, using a range based for statement.

##### Answer
```
for (auto& line_seg: &line)
    if (line_seg == ’ ’)
        ++space_count;
```
