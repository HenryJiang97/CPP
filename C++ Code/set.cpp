// Definition
set<int> set;

// Add
set.insert(a);

// Lower bound
// Returns an iterator to the first element that is equal to 'a' or just less than 'a'
iterator it = set.lower_bound(a);

// Upper bound
// Returns an iterator to the first element that is equal to 'a' or just higher than 'a'
iterator it = set.upper_bound(a);


// Distance between iterator
int dis = distance(set.begin(), set.end());