// Definition
multiset<int> set;    // Small to large
multiset<int, greater<int>> set;    // Large to small

// Add
set.insert(e);

// Remove (Remove all elements equals to e)
set.erase(e);

// Find a certain element
auto it = set.find(e);

// Remove (Remove the element iterator point to)
set.erase(it);

// Iteration
multiset<int> :: iterator it = set.begin();
auto it = set.begin();
auto it = set.rbegin();    // Reverse begin pointer

auto it = set.end();
auto it = set.rend();

auto it = set.cbegin();    // Constant begin pointer


// Move iterator back
it = next(it);
int a = *it;

// Move iterator back by n place
it = next(it, n);

// Move iterator front by n place
it = prev(it, n);