#include <iostream>
#include <fstream>
#include <string>

#include <iomanip>

using namespace std;

const int NUM_IDS = 12;

void storeMessage(string message, int edges[NUM_IDS][NUM_IDS]);

int getTopFriend(int edges[NUM_IDS][NUM_IDS], int from_id);

int main() {
    // Initialize all edges to 0
    int edges[NUM_IDS][NUM_IDS] = {};

    // Open the input file
    ifstream message_log;
    message_log.open("messages.csv");

    // Read each line of the input file and store it in our graph
    string message;
    while (getline(message_log, message)) {
        storeMessage(message, edges);
    }

    // Print the graph
    // Not necessary, but good to see for learning purposes
    for (int i = 0; i < NUM_IDS; i++) {
        for (int j = 0; j < NUM_IDS; j++)
            cout << setw(3) << edges[i][j] << ' ';
        cout << endl;
    }
    cout << endl;

    // Get top friends of each id
    int top_friends[NUM_IDS];
    for (int i = 0; i < NUM_IDS; i++)
        top_friends[i] = getTopFriend(edges, i);

    // Print out the top friends
    for (int i = 0; i < NUM_IDS; i++) {
        int top_friend = top_friends[i];
        if (top_friends[top_friend] == i)
            cout << i << "'s best friend is " << top_friend << endl;
        else
            cout << i << "'s top friend is " << top_friend << endl;
    }
}

void storeMessage(string message, int edges[NUM_IDS][NUM_IDS]) {
    // Get from and to ids, from the message using the comma positions
    int comma_1_pos = message.find(',');
    int comma_2_pos = message.find(',', comma_1_pos + 1);

    int from_id = stoi(message.substr(comma_1_pos + 1, comma_2_pos - comma_1_pos - 1));
    int to_id = stoi(message.substr(comma_2_pos + 1, -1));

    // Increment the edge
    edges[from_id][to_id] += 1;
}

int getTopFriend(int edges[NUM_IDS][NUM_IDS], int from_id) {
    // Search through from_id's row to find the edge leaving the node with the highest weight
    int top_friend = 0;
    for (int i = 1; i < NUM_IDS; i++) {
        if (edges[from_id][i] > edges[from_id][top_friend])
            top_friend = i;
    }

    // Return the id associated with the max
    return top_friend;
}
