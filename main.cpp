#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

unordered_map<int, std::string> fruitsEmojis = {
    {0, "\U0001F352"}, // Cherries
    {1, "\U0001F34B"}, // lemon
    {2, "\U0001F34A"}, // Apple
    {3, "\U0001F514"}, // Bell
    {4, "\U0001F347"}, // Grapes
    {5, "\U0001F349"}, // Strawberry
    //{6, "\U0001F171"}  // Bar
    {6, "\U0001F4B0"}  // money bag (replace bar)
};

int spinReel(vector<int> reel, vector<string> &reel_result) {             
    int index = rand() % 20;
    cout<< index << endl;
    int previous_index = (index - 1 + reel.size()) % reel.size();
    int next_index = (index + 1) % reel.size();

    reel_result[0] = fruitsEmojis[reel[previous_index]];
    reel_result[1] = fruitsEmojis[reel[index]];
    reel_result[2] = fruitsEmojis[reel[next_index]];
    return 0;
}

int main() {
    srand(time(NULL));
    vector<int> reel1 = {0, 1, 2, 0, 3, 1, 4, 0, 5, 6, 1, 2, 0, 4, 1, 3, 5, 2, 1, 0};
    vector<string> reel1_result(3);

    vector<int> reel2 = {0, 1, 2, 1, 1, 3, 4, 0, 5, 6, 1, 2, 0, 4, 3, 1, 5, 3, 1, 0};
    vector<string> reel2_result(3);

    vector<int> reel3 = {0, 1, 2, 2, 3, 1, 4, 0, 5, 6, 1, 2, 0, 4, 1, 3, 5, 2, 1, 0};
    vector<string> reel3_result(3);

    spinReel(reel1, reel1_result);
    spinReel(reel2, reel2_result);
    spinReel(reel3, reel3_result);

    cout << reel1_result[0]+ "  "+ reel2_result[0]+ "  "+ reel3_result[0] << endl;
    cout << reel1_result[1]+ "  "+ reel2_result[1]+ "  "+ reel3_result[1] << endl;
    cout << reel1_result[2]+ "  "+ reel2_result[2]+ "  "+ reel3_result[2] << endl;

    //for (int i = 0; i < 20; i++) {
    //   cout << fruitsEmojis[reel1[i]] + "  "+ fruitsEmojis[reel2[i]]+ "  "+ fruitsEmojis[reel3[i]] << endl;
    //} */
    
    return 0;
}
