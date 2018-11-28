#pragma once

#include <iostream>
#include <map>
#include <numeric>
#include <vector>

class Sox {
    private:
        std::vector<int> sock_list;
        std::map<int, int> counts;
    public:
        Sox(std::vector<int> sock_list_) { sock_list = sock_list_; }
        std::vector<int> get_socks() { return sock_list; }
        void count_socks();
        int total_pairs();
};

void Sox::count_socks() {
    for (std::vector<int>::iterator it = sock_list.begin(); it != sock_list.end(); it++) {
        counts[*it]++;
    }
}

int Sox::total_pairs() {
    // if this is the first time through, count up the socks
    if (counts.empty() & (sock_list.size() > 0)) {
        count_socks();
    }

    return std::accumulate(counts.cbegin(), counts.cend(), 0,
                           [](int previous, const std::map<int, int>::value_type& p)
                           { return previous + (p.second / 2); });
}
