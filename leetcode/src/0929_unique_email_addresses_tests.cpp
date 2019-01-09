#define CATCH_CONFIG_MAIN

#include <string>
#include <unordered_set>
#include <vector>

#include "catch2/catch.hpp"
#include "0929_unique_email_addresses.hpp"


TEST_CASE ("All tests") {


    SECTION ("known results") {
        Solution s;
        std::vector<std::string> emails;
        std::unordered_set<std::string> unique_emails;

        emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
            "testemail+david@lee.tcode.com"};
        CHECK ( s.numUniqueEmails(emails) == 2 );
    }
}