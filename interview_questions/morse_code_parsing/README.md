# Morse Code parsing

In practice, [morse code](https://en.wikipedia.org/wiki/Morse_code) receivers can distinguish when a letter or word ends because a longer space between signals is used.  However, imagine that you have a continuous stream of morse code without any spaces distinguishing letters or words?  You can represent the `short`s as `.` and the `long`s as `-`, so that a transmission looks like, for example:

```
.-.-
```

Given a morse code sequence like the above, and given a dictionary of a subset of English words, find all possible parsings of a morse code sequence into words from the dictionary.

For example, if `a` and `eta` are both words in your dictionary, then:

```
"a" in morse code is ".-"
"e" in morse code is "."
"t" in morse code is "-"
"eta" in morse code is ".-.-"
["a", "a"] in morse code is ".-.-"
["eta"] in morse code is ".-.-"
```

so that two possible parsings of `.-.-` into words from your dictionary are `["a", "a"]` and `["eta"]`.

This problem was presented to me in an interview by [company you know].  I know very little about string processing in C++ - which just isn't that relevant to my work - which was an unexpected challenge during this interview, and a bit unwelcome.  However, I sort of bungled the problem anyway, struggling to land on data structure.

This is a dynamic programming solution that can be improved on.  However, note that because `.-.-` has 2 possible parsings, sequences of `N` repeating `.-.-` have at least `2^N` possible unique parsings.  So any solution is necessarily of exponential complexity in both time and space.  Which means that huge improvements only allow you to push the algorithm to slightly longer strings.

Which explains why IRL parsing algorithms don't produce all possible parsings, but instead produce a small subset, and usually use a greedy or probablistic approach.  And it also reinforces the importance of having good delimiters in all things, even morse code!

This solution makes use of `std::set` and `std::map`, which are implemented using trees, when ideally we would use a hash table.  However, `std::unordered_set` and `std::unordered_map`, which are hash tables, do not have a hash function for `vector` or `unordered_set`.  So, in order to use them, you would need to implement a hash function for these functions.

Other improvements:

- unroll the recursion
- profile to find speed and memory problems

**Update:**

My brother [@tbenthompson](https://github.com/tbenthompson), who is a genius `:) >^..^<` , noted that while this problem is necessarily exponential, you can generate graph representation of all possible parsings in linear time.  Yielding from the generator would then be exponential.

To do this, imagine finding all substrings of your morse code string that match a word in your dictionary, and imagine that you have a directed graph with `N + 1` vertices, labeled `v_0, ... , v_N`.  You can think of your nodes as interleaved with your string, so for example, for `mc_string = .-.-`, you have:

`v_0, ".", v_1, "-", v_2, ".", v_3, "-", v_4`

Then `(v_i, v_j)` is an edge iff:

1. `i < j`, and
2. `mc_string[i:j]`, the string between `v_i` and `v_j`, is a word in your dictionary.

A parsing is then a path from `v_0` to `v_N`.  Condition 1 is there to guarantee our paths move forward, never backward, and condition 2 guarantees that paths map to parsings.

Generating all unique parsings is exactly equivalent to finding all possible paths through the graph from `v_0` to `v_N`.  Determining if there is any parsing amounts to determining if there is any path.

Ben also noted that by converting everything to vectors of 1s and 0s, there might be significant speed up, since strings are effectively vectors, and this would reduce the size of the vectors.

The lesson here for me is to get a bit more abstract in thinking about how to represent a problem before trying to solve it.  And talk to smart people, that's always good too.

