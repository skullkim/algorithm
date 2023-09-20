#include <iostream>
#include <vector>
using namespace std;

bool isSame(vector<int> deck, vector<int> deck2) {
	for (int i = 0; i < deck.size(); i++) {
		if (deck[i] != deck2[i]) return false;
	}	
	return true;
}

vector<int> shuffleCard(vector<int> deck, vector<int> rule) {
	vector<int> shuffledDeck(deck.size());
	for (int i = 0; i < deck.size(); i++) {
		shuffledDeck[rule[i]] = deck[i];
	}
	return shuffledDeck;
}

bool hasCard(vector<int> cards, int target) {
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i] == target) return true;
	}
	return false;
}

bool isAnswer(vector<int> deck, vector<vector<int>> shuffleResult) {
	int player = 0;
	for (int i = 0; i < deck.size(); i++) {
		if (player == 3) player = 0;
		int card = deck[i];
		if (!hasCard(shuffleResult[player], card)) return false;
		player++;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const int PLAYER_NUM = 3;

	int cardNum;
	vector<vector<int>> shuffleResult(PLAYER_NUM);
	cin >> cardNum;
	for (int card = 0; card < cardNum; card++) {
		int owner;
		cin >> owner;
		shuffleResult[owner].push_back(card);
	}

	vector<int> shuffleRule(cardNum);;
	for (int i = 0; i < cardNum; i++) {
		cin >> shuffleRule[i];
	}

	vector<int> deck(cardNum);
	for (int i = 0; i < cardNum; i++) {
		deck[i] = i;
	}
	const vector<int> ORIGINAL_DECK = deck;

	int totalShuffles = 0;
	while (true) {
		if (isSame(deck, ORIGINAL_DECK) && totalShuffles >= 1) {
			totalShuffles = -1;
			break;
		} else if (isAnswer(deck, shuffleResult)) {
			break;
		}
		deck = shuffleCard(deck, shuffleRule);
		totalShuffles++;
	}
	cout << totalShuffles;
}
