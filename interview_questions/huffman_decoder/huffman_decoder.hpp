/*
From an interview, given a binary string, and a set codes from binary strings to characters, find the unique
decomposition of a binary string into characters.  Huffman Codes are used, the primary useful
property of which is that any one Huffman code is not a prefix of any other, ensuring that the
decomposition, if it exists, is unique.
 */

#include <string>
#include <unordered_map>

using namespace std;

string decode(vector<string> codes, string encoded) {
    std::unordered_map<string, char> decoding;
    string res;

    for (auto code : codes) {
        size_t found = code.find('\t');
        string character = code.substr(0, found);

        if (character == "[newline]") {
            character = "\n";
        }

        string encoding = code.substr(found + 1);

        decoding[encoding] = character[0];
    }

    // optimization would be to iterate only over seen lenghts of encodings in map
    int pos = 0;

    while (pos < encoded.length()) {
        int match_len = 1;

        while (match_len < 30) {
            std::cout << encoded.substr(pos, match_len) << std::endl;
            if (decoding.count(encoded.substr(pos, match_len)) != 0) {
                res += decoding[encoded.substr(pos, match_len)];
                pos += match_len;
                break;
            }

            match_len++;
        }
    }

    return res;
}