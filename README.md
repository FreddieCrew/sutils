# sutils
Some useful (or not) string/math functions

# String Functions
```cpp
native strcount(const src[], const word[], bool:casesen = true); // Counts how many occurrences of a word are in a string
native bool: isempty(const string[]); // Checks whether the string is null/empty
native bool: isdigits(const string[]); // Checks whether the string contains only numbers/digits
native bool: isip(const string[]); // Checks whether the string is a valid IP address
native strcpy(dest[], const origin[], len = sizeof(dest)); // Copies the string into another string
stock strtoupper(const src[], dest[], len = sizeof(src)); // Converts the string to uppercase
stock strtolower(const src[], dest[], len = sizeof(src)); // Converts the string to lowercase
```

# Math functions
```cpp
native abs(value); // Returns the absolute value of a number
native isnan(value); // Checks whether a value is NaN (Not-A-Number)
native nan(); // Returns a NaN value (Not-A-Number)
```

# Disclaimer
Keep in mind that, most, if not all, of these functions can be easily implemented in Pawn. I chose to implement them in C++ simply because it's enjoyable, and I wanted to brush up on my C++ skills, since it's been a while since I last worked with it.
