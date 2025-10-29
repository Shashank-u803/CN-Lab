#include <bits/stdc++.h>
using namespace std;

int main() {
    int no_of_queries = 4;    // number of times bucket is checked
    int bucket_size = 10;     // bucket capacity
    int input_pkt_size = 4;   // packets arriving at each time unit
    int output_pkt_size = 1;  // packets leaving at each time unit
    int storage = 0;          // current packets in buffer

    cout << left << setw(6)  << "Time"
         << setw(17) << "Buffer-Before"
         << setw(10) << "Arrival"
         << setw(17) << "Buffer-After"
         << setw(10) << "Dropped"
         << setw(12) << "Departure"
         << setw(17) << "Buffer-Capacity"
         << endl;

    cout << string(89, '-') << endl;

    for (int t = 1; t <= no_of_queries; t++) {
        int before = storage;
        int dropped = 0;

        int size_left = bucket_size - storage;
        if (input_pkt_size <= size_left) {
            storage += input_pkt_size;
        } else {
            dropped = input_pkt_size - size_left;
            storage = bucket_size;
        }

        int after = storage;
        storage = max(0, storage - output_pkt_size);

        cout << left << setw(6)  << t
             << setw(17) << before
             << setw(10) << input_pkt_size
             << setw(17) << after
             << setw(10) << dropped
             << setw(12) << output_pkt_size
             << setw(17) << storage
             << endl;
    }

    return 0;
}
