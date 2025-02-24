#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Input number of symbols
    int no_of_symbol;
    cout << "Number of input symbols : ";
    cin >> no_of_symbol;

    // Input symbols
    vector<char> symbols(no_of_symbol);
    cout << "Input symbols : ";
    for (int i = 0; i < no_of_symbol; i++) {
        cin >> symbols[i];
    }

    // Input number of states
    int states;
    cout << "Enter number of states : ";
    cin >> states;

    // Input initial state
    int initial_state;
    cout << "Initial state : ";
    cin >> initial_state;

    // Input accepting states
    int no_accept;
    cout << "Number of accepting states : ";
    cin >> no_accept;

    vector<int> accept_states(no_accept);
    cout << "Accepting states : ";
    for (int i = 0; i < no_accept; i++) {
        cin >> accept_states[i];
    }

    // Input transition table
    vector<vector<int>> transition_table(states + 1, vector<int>(no_of_symbol));
    cout << "Transition table : " << endl;
    for (int i = 1; i <= states; i++) {
        for (int j = 0; j < no_of_symbol; j++) {
            cout << i << " to " << symbols[j] << " -> ";
            cin >> transition_table[i][j];
        }
    }

    // Loop for testing multiple strings
    char test_more;
    do {
        // Input string
        string str;
        cout << "\nInput string : ";
        cin >> str;

        // Process the string
        int current_state = initial_state;
        cout << "\nTransitions: " << endl;
        cout << "Initial state: " << current_state << endl;

        for (char c : str) {
            int symbol_index = -1;
            for (int j = 0; j < no_of_symbol; j++) {
                if (c == symbols[j]) {
                    symbol_index = j;
                    break;
                }
            }

            if (symbol_index == -1) {
                cout << "Invalid symbol '" << c << "' in the string!" << endl;
                return 1;
            }

            current_state = transition_table[current_state][symbol_index];
            cout << "On input '" << c << "' moves to state " << current_state << endl;
        }

        // Check if final state is accepting
        bool is_accepted = false;
        for (int accept_state : accept_states) {
            if (current_state == accept_state) {
                is_accepted = true;
                break;
            }
        }

        cout << "\nFinal state: " << current_state << endl;
        if (is_accepted) {
            cout << "String is accepted" << endl;
        } else {
            cout << "String is not accepted" << endl;
        }

        // Ask if the user wants to test another string
        cout << "\nDo you want to test another string? (y/n): ";
        cin >> test_more;

    } while (test_more == 'y' || test_more == 'Y');

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}