#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // Disable synchronization with C stdio for faster I/O
    cin.tie(NULL);               // Untie cin and cout for faster I/O

    int street_len; // Total length of the street
    int light_num;  // Number of traffic lights to be added
    cin >> street_len >> light_num;

    // A set to store the positions of traffic lights
    // It starts with the boundaries of the street (0 and street_len)
    set<int> lights{0, street_len};

    // A multiset to store the lengths of all the passages between traffic lights
    // Initialize with the full length of the street since there are no lights yet
    multiset<int> dist{street_len};

    // Loop to add each traffic light
    for (int l = 0; l < light_num; l++)
    {
        int pos; // Position of the new traffic light
        cin >> pos;

        // Find the upper bound for the given position in the 'lights' set
        // This is the first element greater than 'pos'
        auto it1 = lights.upper_bound(pos);

        // 'it2' is the previous element from 'it1'
        // This gets the interval between two existing lights where the new light will be placed
        auto it2 = it1;
        --it2;

        // Remove the previous interval from the 'dist' multiset
        // This is the interval that will be split by adding the new traffic light
        dist.erase(dist.find(*it1 - *it2)); // (*it1 - *it2) is the length of the current interval

        // Add the new intervals created by the addition of the traffic light
        dist.insert(pos - *it2); // New interval from 'it2' to 'pos'
        dist.insert(*it1 - pos); // New interval from 'pos' to 'it1'

        // Insert the new traffic light position into the 'lights' set
        lights.insert(pos);

        // Find the maximum interval in 'dist'
        auto ans = dist.end();
        --ans; // The last element in the multiset is the largest interval

        // Output the longest passage without traffic lights after this addition
        cout << *ans << " "; // Print the longest distance
    }
}