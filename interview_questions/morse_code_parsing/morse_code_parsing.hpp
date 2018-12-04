#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using std::map;
using std::set;
using std::string;
using std::vector;

// Everything in this section was written by the interviewer

// parse a space-separated string of words into a vector
vector<string> parseWords(const string &wordList)
{
    vector<string> words;
    auto l = 0u;
    while(l != wordList.size())
    {
        auto m = wordList.find(" ", l);
        if (m == string::npos)
        {
            words.push_back(wordList.substr(l));
            l = wordList.size();
        }
        else
        {
            words.push_back(wordList.substr(l, m - l));
            l = m + 1;
        }
    }
    return words;
}

// only needed for making wordlist
const string wordlistStr = "a abet add adder ade an at ate bad bed beget bent bet beta bran dee deed did din dine dint due duet ease edit eel eft eh elf elite emu enter ere ere"
            " eta eve ewe fan fate fee feel fete fir fire get he i idea in instep iran irate ire keen kilt kin kite lea lee lens lid met net nil peer pen pet pie plea poem rate reel rein"
            " saute senate sent set set skin stain step stun tea tear tee teen teeth test that tide tie tie tier tiet time tin tine tit tun ute vain vet wee weed weir"
            " welt west win wine wit with wits yet";

// full list of english words we can use
const vector<string> allEnglishWords = parseWords(wordlistStr);

// definition of Morse code: encode each english letter with a unique sequence of dots and dashes
std::unordered_map<char, string> letter2morse = {{'A', ".-"}, {'B', "-..."}, {'C', "-.-."},
    {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."},
    {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"},
    {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}};

// goal: write a function to produce all possible sequences of english words from the word list that match a given Morse code string
// eg '.....' -> [['he'], ['eh']]
// eg '.-.-' -> [['a', 'a']]  // Alex: this is wrong, there is another parsing as ["eta"]

// Everything below this point is Alex T's work

// #### CONVENIENCE PRINT FUNCTIONS ####

template <typename T>
std::ostream& operator << (std::ostream& stream, const std::vector<T> &v) {
    auto it = v.cbegin();
    auto v_end = v.cend();

    if (it == v_end) {
        std::cout << "< empty-vector >";
        return stream;
    }

    std::cout << "< ";

    while (it != v_end) {
        std::cout << *it;
        it++;
        if (it != v_end) std::cout << ", ";
        else std::cout << " >";
    }

    return stream;
}


template <typename T>
std::ostream& operator << (std::ostream& stream, const set<T> &obj) {
    auto it = obj.cbegin();
    auto obj_end = obj.cend();
    std::cout << "{ ";

    while (it != obj_end) {
        std::cout << *it;
        it++;
        if (it != obj_end) std::cout << ", ";
        else std::cout << " }";
    }

    return stream;
}


template <typename S, typename T>
std::ostream& operator << (std::ostream& stream, const std::map<S, T> &m) {
    std::cout << "{\n";

    for (auto it = m.cbegin(); it != m.cend(); it++) {
        std::cout << "    " << it->first << ": " << it->second << ",\n";
    }
    std::cout << "}";

    return stream;
}


// #### IMPLEMENTATION ####

string mc_from_string(string input) {
    // convert input to mc
    string res = "";

    for (auto it = input.begin(); it != input.end(); it++) {
        res += letter2morse[(char)toupper(*it)];
    }

    return res;
}

template <typename T>
set<vector<T>> cartesian_product(set<vector<T>> s, set<vector<T>> t) {
    // returns a set of all possible concatenations of element in s and t,
    set<vector<T>> res;

    for (auto it_s = s.cbegin(); it_s != s.cend(); it_s++) {
        for (auto it_t = t.cbegin(); it_t != t.cend(); it_t++) {
            vector<T> new_elem = *it_s;
            new_elem.insert(new_elem.end(), (*it_t).begin(), (*it_t).end());
            res.insert(new_elem);
        }
    }

    return res;
}


class MCParser {
    private:
        vector<string> words;
        map<string, set<vector<string>>> single_word_dict;
        map<string, set<vector<string>>> known_parsings;
        int min_length_mc_word = 999;  // hack to make sure it's updated on first word
        int max_length_mc_word = 0;

    public:
        MCParser(const vector<string> &words_){ words = words_;}
        void generate_single_word_dict();
        set<vector<string>> parse_mc(string mc_string);
        map<string, set<vector<string>>> get_single_word_dict() { return single_word_dict; }
};


void MCParser::generate_single_word_dict() {
    for (auto it = words.cbegin(); it != words.cend(); it++) {
        string mc_it = mc_from_string(*it);
        set<vector<string>> current_res = single_word_dict[mc_it];
        current_res.insert({*it});

        single_word_dict[mc_it] = current_res;
        min_length_mc_word = std::min(int(mc_it.length()), min_length_mc_word);
        max_length_mc_word = std::max(int(mc_it.length()), max_length_mc_word);
    }
}


set<vector<string>> MCParser::parse_mc(string mc_string) {
    // use known results
    if (known_parsings.count(mc_string) > 0) return known_parsings[mc_string];

    // else compute results
    set<vector<string>> res;
    int L = mc_string.length();

    // first try to match to single words:
    if (mc_string.length() <= max_length_mc_word && single_word_dict.count(mc_string) > 0) {
        res = single_word_dict[mc_string];
    }

    // split up mc_string into prefix and suffix, where suffix must be a single word, and prefix
    // is recursively computed
    for (int i = min_length_mc_word;
         i <= std::min(max_length_mc_word, L - min_length_mc_word);
         i ++) {

        string prefix = mc_string.substr(0, L - i);
        string suffix = mc_string.substr(L - i, L);

        auto prefix_parsings = parse_mc(prefix);

        // prefix must have some parsings
        if (prefix_parsings.size() == 0) continue;

        // prefix can be any combination of words, but suffix must be a single word
        // suffix must have some parsings
        if (single_word_dict.count(suffix) == 0) {
            continue;
        }
        else {
            auto new_elems = cartesian_product(prefix_parsings, single_word_dict[suffix]);

            for (auto it = new_elems.cbegin(); it != new_elems.cend(); it++) {
                res.insert(*it);
            }
        }
    }

    // memoize
    known_parsings[mc_string] = res;

    return res;
}
