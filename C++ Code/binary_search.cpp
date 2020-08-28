vector<int> v = {1,2,3,4};    // Sorted

// Binary_search
bool r = binary_search(v.begin(), v.end(), target);


// Find (return iterator pointing to the found target in [v.begin() : v.end()]. Return v.end() if not found)
std::vector<int>::iterator res = find(v.begin(), v.end(), target);


// Lower bound (return the iterator pointing to the first element higher or equal to target)
std::vector<int>::iterator res = lower_bound(v.begin(), v.end(), target);


// Higher bound (return the iterator pointing to the first element higher than target)
std::vector<int>::iterator res = upper_bound(v.begin(), v.end(), target);