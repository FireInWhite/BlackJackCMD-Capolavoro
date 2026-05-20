#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

void pcards(vector<int> cards, bool hideC)
{

	if (hideC == true)
	{
		cards[1] = -1;
	}

	cout << "\n";
	for (int i : cards)
	{
		cout << " ----- ";
	}
	cout << "\n";
	for (int value : cards)
	{
		if (value == -1)
		{
			cout << "|     |";
		}
		if (value == 1)
		{
			cout << "|  A  |";
		}
		if (value == 11)
		{
			cout << "|  A  |";
		}
		else if (value == 2)
		{
			cout << "|  2  |";
		}
		else if (value == 3)
		{
			cout << "|  3  |";
		}
		else if (value == 4)
		{
			cout << "|  4  |";
		}
		else if (value == 5)
		{
			cout << "|  5  |";
		}
		else if (value == 6)
		{
			cout << "|  6  |";
		}
		else if (value == 7)
		{
			cout << "|  7  |";
		}
		else if (value == 8)
		{
			cout << "|  8  |";
		}
		else if (value == 9)
		{
			cout << "|  9  |";
		}
		else if (value == 10)
		{
			cout << "|  10 |";
		}
		else if (value == 12)
		{
			cout << "|  J  |";
		}
		else if (value == 13)
		{
			cout << "|  Q  |";
		}
		else if (value == 14)
		{
			cout << "|  K  |";
		}
	}
	cout << "\n";
	for (int i : cards)
	{
		cout << " ----- ";
	}
}

void pointsys(vector<int> &cards, int &sum)
{
	sum = 0;

	// if cards value is 12+ convert to 10
	// conv 11 to 1 if over 21

	for (int &i : cards)
	{
		if (i >= 12)
		{
			sum += 10;
		}
		else
		{
			sum += i;
		}
		if (sum > 21 && i == 11)
		{
			sum -= 10;
		}
	}
}

int main()
{

	srand(time(0));
	const int max = 21;
	bool hideAI = true, hideP = false;
	string action, resoult;
	struct
	{
		int sum;
		vector<int> cards;
	} player, AI;

	AI.cards.push_back(rand() % 13 + 2);
	AI.cards.push_back(rand() % 13 + 2);
	player.cards.push_back(rand() % 13 + 2);
	player.cards.push_back(rand() % 13 + 2);

	pointsys(player.cards, player.sum);
	pointsys(AI.cards, AI.sum);

	//-------------------GAME START
	cout << "Blackjack 21:\n";

	//-------------------AI
	cout << "\nTable: ";

	pcards(AI.cards, hideAI);

	//--------------PLAYER
	cout << "\n\nPlayer: " << player.sum;

	pcards(player.cards, hideP);

	//--------------------------------------

	cout << "\n\nPlayer turn: ";

	// PLAYER PLAYS
	do
	{

		if (player.sum < 22)
		{

			do
			{
				cout << "\nStand or Hit? ";
				cin >> action;

			} while (action != "stand" && action != "hit");

			if (action == "hit")
			{
				player.cards.push_back(rand() % 13 + 1);
				pointsys(player.cards, player.sum);

				system("cls");

				cout << "\nTable: ";
				pcards(AI.cards, hideAI);

				cout << "\n\nPlayer: " << player.sum;
				pcards(player.cards, hideP);
			}
			if (action == "stand")
			{
			}
		}
		else
		{
			resoult = "OVER 21!";
		}

		pointsys(player.cards, player.sum);

	} while (action == "hit" && player.sum <= 21);

	if (player.sum < 22)
	{

		// AI TURN
		while (AI.sum < 17)
		{
			AI.cards.push_back(rand() % 13 + 1);
			pointsys(AI.cards, AI.sum);
		}

		// Winner?
		if (AI.sum < 22)
		{

			if (player.sum > AI.sum)
			{
				resoult = "WIN";
			}
			if (player.sum == AI.sum)
			{
				resoult = "TIE";
			}
			if (player.sum < AI.sum)
			{
				resoult = "LOST";
			}
		}
		else
		{
			resoult = "WIN - TABLE BUST";
		}
	}
	else
	{
		resoult = "OVER 21!";
	}

	hideAI = false;

	system("cls");

	cout << "---------Final Score:---------\n";
	cout << "\nTable: " << AI.sum;
	pcards(AI.cards, hideAI);
	cout << "\nPlayer: " << player.sum;
	pcards(player.cards, hideP);
	cout << "\n\nPLAYER " << resoult;

	cout << "\n\n";

	system("pause");
}