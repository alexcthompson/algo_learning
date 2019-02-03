/*
From an interview: the idea is that you are given a string representing safe tiles and unsafe tiles.  The last
character denotes the safe tile and you must jump from the -1 position to the end position without
stepping on an unsafe tile.  The function should return the max distance you need to jump to complete the
course safely.
 */

 #include <algorithm>

int powerJump(string game) {
    int N = game.length();
    char safe_tile = game[N-1];
    int max_run_unsafe = 0;
    int current_run = 0;

    // idea: count up the unsafe tiles, then the needed power is == the max run of unsafe tiles + 1
    for (auto c : game) {
        if (c != safe_tile) {
            current_run++;
        }
        else {
            current_run = 0;
        }

        max_run_unsafe = std::max(max_run_unsafe, current_run);
    }

    return max_run_unsafe + 1;
}