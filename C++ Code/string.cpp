// Substring
String s = "Hello World";
s.substr(0, 3)   // Get digit starting from 0 and has length of 3

// index of
int a = s.find('a');
int a = s.indexOf('a', index);    // index of "e" from beginning index


// Compare two strings s1 and s2 in alphabat order, 0 => s1 == s2; >0 => s1 > s2; <0 => s1 < s2
int a = s1.compare(s2);



// To char array
char char_array[s.length()];
strcpy(char_array, s.c_str());


// Integer to string
int a = 1;
string str = to_string(a);

// String to int
String a = "17";
int b = stoi(a);


// If string contains a char sequence behind index
s.find('c', index)


// Is letter?
isalpha(c);

// Is digit?
isdigit(c);

// Is lowercase letter?
islower(c);


// Char multiplies
string multiChars = string(2, 'a');    // "aa"


// Sort string in lexicographical order
sort(s.begin(), s.end());




// String View
string s = string(20, 'a');

string_view sv(s);
string_view svv = sv.substr(10, 10);