#include <stdexcept>
#include <vector>

void print_v(std::vector<int> v) {
    for (std::vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

class min_heap {
private:
    std::vector<int> elems;

public:
    int len();
    int parent_pos(int pos);
    std::vector<int> child_pos(int pos);
    void swap_child_up(int pos); // swaps child in pos up to parent
    bool check_and_swap(int &pos);  // check if the parent is larger, in which case swap
    void insert(int new_elem);
    void heapify(std::vector<int> new_elems);
    int extract();
    int min();
    void print_elems() { print_v(elems); }
};

int min_heap::len() {
    return elems.size();
}

int min_heap::parent_pos(int pos) {
    if (pos == 0) return -999;
    else return (pos - 1) / 2;
}

std::vector<int> min_heap::child_pos(int pos) {
    std::vector<int> res(0);
    // no children
    if (2 * pos + 1 >= len()) return res;
    // one child
    else if (2 * pos + 2 == len()) {
        res.push_back(2 * pos + 1);
    }
    // two children
    else {
        res.push_back(2 * pos + 1);
        res.push_back(2 * pos + 2);
    }

    return res;
}

void min_heap::swap_child_up(int pos) {
    if (pos == 0) return;

    int ppos = parent_pos(pos);

    elems[pos] += elems[ppos];
    elems[ppos] = elems[pos] - elems[ppos];
    elems[pos] = elems[pos] - elems[ppos];
}

bool min_heap::check_and_swap(int &pos) {
    if (pos == 0) return false;

    int ppos = parent_pos(pos);
    if (elems[ppos] > elems[pos]) {
        swap_child_up(pos);
        return true;
    }

    return false;
}

void min_heap::insert(int new_elem) {
    elems.push_back(new_elem);
    int new_elem_pos = len() - 1;

    bool continue_swapping = true;

    while (continue_swapping) {
        continue_swapping = check_and_swap(new_elem_pos);
        if (continue_swapping) new_elem_pos = parent_pos(new_elem_pos);
    }
}

void min_heap::heapify(std::vector<int> new_elems) {
    for (auto it = new_elems.begin(); it != new_elems.end(); it++) {
        insert(*it);
    }
}

int min_heap::extract() {
    int res = min();

    if (len() == 1) {
        elems.pop_back();
        return res;
    }

    elems[0] = elems.back();
    elems.pop_back();

    bool swap_check = true;
    int swap_pos = 0;

    while (swap_check) {
        auto children = child_pos(swap_pos);

        if (children.size() == 0) swap_check = false;
        else if (children.size() == 1) {
            check_and_swap(children[0]);
            swap_check = false;
        }
        else {
            int check_pos = -1;
            if (elems[children[0]] < elems[children[1]]) check_pos = children[0];
            else check_pos = children[1];

            swap_check = check_and_swap(check_pos);
            swap_pos = check_pos;
        }
    }

    return res;
}

int min_heap::min() {
    if (len() == 0) throw std::runtime_error("No min on heap of size 0.");
    return elems[0];
}


class KthLargest {
private:
    min_heap k_largest;
    int k;

public:
    KthLargest(int k, std::vector<int> nums);
    int add(int val);
    void print_heap() { k_largest.print_elems(); }
};

int KthLargest::add(int val) {
    if (k_largest.len() < k) {
        k_largest.insert(val);

        return k_largest.min();
    }
    else if (val <= k_largest.min()) {
        return k_largest.min();
    }
    else {
        k_largest.extract();
        k_largest.insert(val);

        return k_largest.min();
    }
}

KthLargest::KthLargest(int k_, std::vector<int> nums) {
    k = k_;

    for (auto it = nums.cbegin(); it < nums.cend(); it++) {
        add(*it);
    }
}
