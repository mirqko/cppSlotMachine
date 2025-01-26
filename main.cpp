#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

unordered_map<int, std::string> fruitsEmojis = {
    {0, "\U0001F352"}, // Cherries
    {1, "\U0001F34B"}, // Lemon
    {2, "\U0001F34A"}, // Orange
    {3, "\U0001F514"}, // Bell
    {4, "\U0001F347"}, // Grapes
    {5, "\U0001F349"}, // Watermelon
    {6, "\U0001F4B0"}  // Money Bag 
};

unordered_map<int, int> payoutMultiplyerMap = {
    {0, 5}, // Cherries
    {1, 10}, // Lemon
    {2, 20}, // Orange
    {3, 100}, // Bell
    {4, 50}, // Grapes
    {5, 50}, // Watermelon
    {6, 500}  // Money Bag 
};


int spinReel(vector<int> reel, vector<int> &reel_result) {             
    int index = rand() % 20;
    //out<< index << endl;
    int previous_index = (index - 1 + reel.size()) % reel.size();
    int next_index = (index + 1) % reel.size();

    reel_result[0] = reel[previous_index];
    reel_result[1] = reel[index];
    reel_result[2] = reel[next_index];
    return 0;
}

void checkWin(vector<int> reel1, vector<int> reel2, vector<int> reel3) {

        int earnings = 0;
        int bet = 1;

        //check horizontal combinations
        if (reel1[0] == reel2[0] && reel2[0] == reel3[0]) {
            earnings += bet * payoutMultiplyerMap[reel1[0]];
            cout << "upper row combinatio, win: "+ to_string(bet * payoutMultiplyerMap[reel1[0]]) +"$"<< endl;
        }
        if (reel1[1] == reel2[1] && reel2[1] == reel3[1]) {
            earnings += bet * payoutMultiplyerMap[reel1[0]];
            cout << "middle row combination, win "+ to_string(bet * payoutMultiplyerMap[reel1[0]]) +"$"<< endl;
        }
        if (reel1[2] == reel2[2] && reel2[2] == reel3[2]) {
            earnings += bet * payoutMultiplyerMap[reel1[0]];
            cout << "bottom row combination, win " + to_string(bet * payoutMultiplyerMap[reel1[0]]) +"$"<< endl;
        }

        // check diagonal combinations
        if (reel1[0] == reel2[1] && reel2[1] == reel3[2]) {
            earnings += bet * payoutMultiplyerMap[reel1[0]];
            cout << "diagonal combination, win " + to_string(bet * payoutMultiplyerMap[reel1[0]]) +"$"<< endl;
        }
        if (reel1[2] == reel2[1] && reel2[1] == reel3[0]) {
            earnings += bet * payoutMultiplyerMap[reel1[0]];
            cout << "diagonal combination, win: "+ to_string(bet * payoutMultiplyerMap[reel1[0]]) +"$"<< endl;
        }
        if (earnings > 0) {
            cout << "total win: "+ to_string(earnings) +"$"<< endl;
        }
}


int main() {
    srand(time(NULL));
    vector<int> reel1 = {0, 1, 2, 0, 3, 1, 4, 0, 5, 6, 1, 2, 0, 4, 1, 3, 5, 2, 1, 0};
    vector<int> reel2 = {0, 1, 2, 1, 1, 3, 4, 0, 5, 6, 1, 2, 0, 4, 3, 1, 5, 3, 1, 0};
    vector<int> reel3 = {0, 1, 2, 2, 3, 1, 4, 0, 5, 6, 1, 2, 0, 4, 1, 3, 5, 2, 1, 0};
    vector<int> reel1_result(3);
    vector<int> reel2_result(3);
    vector<int> reel3_result(3);
    
    spinReel(reel1, reel1_result);
    spinReel(reel2, reel2_result);
    spinReel(reel3, reel3_result);

    cout << fruitsEmojis[reel1_result[0]]+ "  "+ fruitsEmojis[reel2_result[0]]+ "  "+ fruitsEmojis[reel3_result[0]] << endl;
    cout << fruitsEmojis[reel1_result[1]]+ "  "+ fruitsEmojis[reel2_result[1]]+ "  "+ fruitsEmojis[reel3_result[1]] << endl;
    cout << fruitsEmojis[reel1_result[2]]+ "  "+ fruitsEmojis[reel2_result[2]]+ "  "+ fruitsEmojis[reel3_result[2]] << endl;

    checkWin(reel1_result, reel2_result, reel3_result);
    
    return 0;
}
