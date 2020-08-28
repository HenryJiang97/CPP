// Definition
map<int, int> m;

// Add
map[1] = 2;
map.insert({1, 2});

// Remove
map.erase(1);

// Lower bound (Find the iterator which has value equal or just larger than the target)
auto it = m.lower_bound(target);
// Access
int key = (*it).first;
int val = (*it).second;


// Higher bound (Find the iterator which has value just larger than the target)
auto it = m.upper_bound(target);

// Get the iterator having value just less than the target
auto it = --m.upper_bound(target);

