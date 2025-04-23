#include <iostream>
#include <vector>
using namespace std;

enum State { q0, q1, q2, q3, q4, q5, q6, q7, h2 };

string stringReverser(string input) {
    for (char c : input) {
        if (c != 'a' && c != 'b') return "Invalid input";
    }

    vector<char> tape(input.begin(), input.end());
    tape.push_back('#');

    State state = q0;
    int head = 0;

    while (state != h2) {
        if (head < 0 || head >= tape.size()) {
            return "Error: head out of bounds.";
        }

        char symbol = tape[head];

        switch (state) {
            case q0:
                if (symbol == '#') state = h2;
                else state = q1;
                break;

            case q1:
                if (symbol == 'a') {
                    tape[head] = 'A';
                    head++; state = q2;
                } else if (symbol == 'b') {
                    tape[head] = 'B';
                    head++; state = q4;
                } else if (symbol == '#') {
                    state = h2;
                } else head++;
                break;

            case q2:
                if (symbol == 'a' || symbol == 'b' || symbol == 'A' || symbol == 'B') head++;
                else if (symbol == '#') {
                    head--; state = q3;
                }
                break;

            case q3:
                if (symbol == 'a' || symbol == 'b') {
                    tape[head] = (symbol == 'a' ? 'A' : 'B');
                    head--; state = q6;
                } else if (symbol == '#') {
                    head++; state = q1;
                } else head--;
                break;

            case q4:
                if (symbol == 'a' || symbol == 'b' || symbol == 'A' || symbol == 'B') head++;
                else if (symbol == '#') {
                    head--; state = q5;
                }
                break;

            case q5:
                if (symbol == 'a' || symbol == 'b') {
                    tape[head] = (symbol == 'a' ? 'A' : 'B');
                    head--; state = q7;
                } else if (symbol == '#') {
                    head++; state = q1;
                } else head--;
                break;

            case q6:
            case q7:
                if (symbol == 'a' || symbol == 'b' || symbol == 'A' || symbol == 'B') head--;
                else if (symbol == '#') {
                    head++; state = q1;
                }
                break;
        }
    }

    string reversed = "";
    for (int i = tape.size() - 2; i >= 0; i--) {
        if (tape[i] == 'A') reversed += 'a';
        else if (tape[i] == 'B') reversed += 'b';
    }

    return reversed;
}

int main() {
    string input;
    cout << "Enter the string to reverse (a’s and b’s only): ";
    cin >> input;
    string reversed = stringReverser(input);
    cout << "Reversed string: " << reversed << endl;
    return 0;
}
