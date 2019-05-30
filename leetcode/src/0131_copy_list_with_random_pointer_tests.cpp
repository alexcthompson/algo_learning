#define CATCH_CONFIG_MAIN

#include <iostream>
#include <string>
#include <unordered_map>

#include "catch2/catch.hpp"
#include "0131_copy_list_with_random_pointer.hpp"


struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer )
        : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};


class List {
public:
    Node* head;
    List() {}
    List(Node* _head) : head(_head) {}
};


std::ostream& operator << (std::ostream& ostream, const List l) {
    ostream << "List[" << std::endl;

    auto temp = l.head;
    int i = 0;
    std::unordered_map<Node*, int> node_index_map;

    while (temp != NULL) {
        node_index_map[temp] = i;
        temp = temp->next;
        i++;
    }

    temp = l.head;
    i = 0;

    while (temp != NULL) {
        ostream << "\tNode " << i
                << ": val = " << temp->val
                << ", random = ";
        if (temp->random == NULL) {
            ostream << "NULL" << std::endl;
        }
        else if (node_index_map.count(temp) == 0) {
            ostream << temp->next << std::endl;
        }
        else {
            ostream << "index " << node_index_map[temp->next] << std::endl;
        }

        temp = temp->next;
        i++;
    }

    ostream << "]";

    return ostream;
}


bool operator == (const List& L, const List& M) {
    std::stringstream buffer;

    buffer << L;
    std::string output_L = buffer.str();
    buffer.str("");

    buffer << M;
    std::string output__M = buffer.str();
    buffer.str("");

    return output_L == output__M;
}

bool operator != (const List& L, const List& M) {
    return ! (L == M);
}


TEST_CASE ( "all tests" ) {
    Solution s;

    Node* A = new Node(6, NULL, NULL);
    A = new Node(77, A, NULL);
    A = new Node(888, A, NULL);
    A->random = A->next->next;
    A->next->next->random = A->next->next;

    List L(A);

    Node* B = new Node(6, NULL, NULL);
    B = new Node(77, B, NULL);
    B = new Node(888, B, NULL);
    B->random = B->next->next;
    B->next->next->random = B->next->next;

    List M(B);

    SECTION ( "List operator overloads") {
        std::string output;
        std::string expected;

        // check << overload
        expected = "List[\n"
                   "\tNode 0: val = 888, random = index 1\n"
                   "\tNode 1: val = 77, random = NULL\n"
                   "\tNode 2: val = 6, random = index 0"
                   "\n]";

        {
            std::stringstream buffer;
            cout_redirect C(buffer.rdbuf());

            std::cout << L;

            output = buffer.str();
        }

        CHECK ( output == expected );

        // check == and != overload
        CHECK ( L == M );
        B->next->next->val = -1;
        CHECK ( L != M );
    }

    SECTION ( "known examples" ) {
        Node* res = s.copyRandomList(L.head);
        List R(res);

        CHECK ( L == R );
    }
}