#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

unordered_map<int, std::string> fruitsEmojis = {
    {0, "\U0001F352"}, // Cherries
    {1, "\U0001F34B"}, // Banana
    {2, "\U0001F34A"}, // Apple
    {3, "\U0001F514"}, // Bell
    {4, "\U0001F347"}, // Grapes
    {5, "\U0001F349"}, // Strawberry
    {6, "\U0001F171"}  // Red circle
};

string spinReel(vector<int> reel) {             
    int index = rand() % 20;  
    string emoji = fruitsEmojis[reel[index]];
    cout << emoji;
    return emoji;
}

int main() {
    srand(time(NULL));
    vector<int> reel1 = {0, 1, 2, 0, 3, 1, 4, 0, 5, 6, 1, 2, 0, 4, 1, 3, 5, 2, 1, 0};
    vector<int> reel2 = {0, 1, 2, 1, 1, 3, 4, 0, 5, 6, 1, 2, 0, 4, 3, 1, 5, 3, 1, 0};
    vector<int> reel3 = {0, 1, 2, 2, 3, 1, 4, 0, 5, 6, 1, 2, 0, 4, 1, 3, 5, 2, 1, 0};
    spinReel(reel1);
    spinReel(reel2);
    spinReel(reel3);
    return 0;
}
