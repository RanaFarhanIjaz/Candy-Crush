#include"SFML\Graphics.hpp"
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;



void sort(int arr[][8], int& Score) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3]) {
				arr[i][j + 2] += 5;
				arr[i][j] = 0;
				arr[i][j + 1] = 0;
				arr[i][j + 3] = 0;
				Score += 10;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j]) {
				arr[i + 3][j] += 5;
				arr[i][j] = 0;
				arr[i + 1][j] = 0;
				arr[i + 2][j] = 0;
				Score += 10;
			}
		}
	}

	//For three in a row
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]) {
				arr[i][j] = 0;
				arr[i + 1][j] = 0;
				arr[i + 2][j] = 0;
				Score += 5;
			}
		}
	}
	//For three in a column 
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) {
				arr[i][j] = 0;
				arr[i][j + 1] = 0;
				arr[i][j + 2] = 0;
				Score += 5;
			}
		}
	}

	// moving gems down
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 0) {
				for (int k = j; k >= 1; k--) {
					int temp = arr[i][k - 1];
					arr[i][k - 1] = arr[i][k];
					arr[i][k] = temp;
				}
			}
		}
	}


	//for entering new gems
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = (rand() % 5) + 1;
			}
		}
	}

}
void elbow(int arr[][8], int& score) {
	// Elbow pattern - L-shape horizontally (row)
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j + 2]) {
				arr[i][j] += 10;
				arr[i][j + 1] = 0;
				arr[i][j + 2] = 0;
				arr[i + 1][j] = 0;
				arr[i + 2][j + 2] = 0;
				score += 15;
			}
		}
	}

	// Elbow pattern - L-shape vertically (column)
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2]) {
				arr[i][j] += 10;
				arr[i + 1][j] = 0;
				arr[i + 2][j] = 0;
				arr[i + 2][j + 1] = 0;
				arr[i + 2][j + 2] = 0;
				score += 15;
			}
		}
	}

	// Elbow pattern - Reverse L-shape horizontally (row)
	for (int i = 0; i < 8; i++) {
		for (int j = 2; j < 8; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j - 2]) {
				arr[i][j] += 10;
				arr[i][j - 1] = 0;
				arr[i][j - 2] = 0;
				arr[i + 1][j] = 0;
				arr[i + 2][j - 2] = 0;
				score += 15;
			}
		}
	}

	// Elbow pattern - Reverse L-shape vertically (column)
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j - 1] && arr[i][j] == arr[i + 2][j - 2]) {
				arr[i][j] += 10;
				arr[i + 1][j] = 0;
				arr[i + 2][j] = 0;
				arr[i + 2][j - 1] = 0;
				arr[i + 2][j - 2] = 0;
				score += 15;
			}
		}
	}

	sort(arr, score);

}

void specialmove(int arr[][8], int& score) {

	// For rows
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i + 1][j] + 5 && arr[i][j] == arr[i + 2][j] + 5) {
				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						if (k >= 0 && k < 8 && l >= 0 && l < 8) {
							arr[k][l] = 0;
						}
					}
				}
				arr[i][j] = 0;
				arr[i + 1][j] = 0;
				arr[i + 2][j] = 0;
				score += 20;
			}

			if (arr[i][j] != 0 && arr[i][j] == arr[i + 1][j] && arr[i][j] + 5 == arr[i + 2][j]) {
				for (int k = i + 1; k <= i + 3; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						if (k >= 0 && k < 8 && l >= 0 && l < 8) {
							arr[k][l] = 0;
						}
					}
				}
				arr[i][j] = 0;
				arr[i + 1][j] = 0;
				arr[i + 2][j] = 0;
				score += 20;
			}

			if (arr[i][j] != 0 && arr[i][j] + 5 == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]) {
				for (int k = i; k <= i + 2; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						if (k >= 0 && k < 8 && l >= 0 && l < 8) {
							arr[k][l] = 0;
						}
					}
				}
				arr[i][j] = 0;
				arr[i + 1][j] = 0;
				arr[i + 2][j] = 0;
				score += 20;
			}

		}
	}

	// For columns
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1] + 5 && arr[i][j] == arr[i][j + 2] + 5) {
				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						if (k >= 0 && k < 8 && l >= 0 && l < 8) {
							arr[k][l] = 0;
						}
					}
				}
				arr[i][j] = 0;
				arr[i][j + 1] = 0;
				arr[i][j + 2] = 0;
				score += 20;
			}

			if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1] && arr[i][j] + 5 == arr[i][j + 2]) {
				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j + 1; l <= j + 3; l++) {
						if (k >= 0 && k < 8 && l >= 0 && l < 8) {
							arr[k][l] = 0;
						}
					}
				}
				arr[i][j] = 0;
				arr[i][j + 1] = 0;
				arr[i][j + 2] = 0;
				score += 20;
			}

			if (arr[i][j] != 0 && arr[i][j] + 5 == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) {
				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j; l <= j + 2; l++) {
						if (k >= 0 && k < 8 && l >= 0 && l < 8) {
							arr[k][l] = 0;
						}
					}
				}
				arr[i][j] = 0;
				arr[i][j + 1] = 0;
				arr[i][j + 2] = 0;
				score += 20;
			}

		}
	}

	sort(arr, score);

}


bool match(int arr[8][8], int X_cursor, int& Y_cursor) {


	for (int i = X_cursor - 1; i <= X_cursor; i++) {
		int temp = 0;
		for (int j = Y_cursor - 1; j <= Y_cursor; j++) {
			if (arr[i][j] == arr[X_cursor][Y_cursor])
				temp++;
			if (temp == 3)
				return true;
		}
	}

	return false;
}

void saveHighscore(int highScore) {

	ofstream file("highScore.txt");
	file << highScore;
	file.close();
}

int main() {

	const int gridSize = 8;
	const float spacing = 40.0f;
	bool timeEnd = false;

	int score = 0;
	int highScore = 0;
	ifstream file("highScore.txt");
	if (file.is_open()) {
		file >> highScore;
		file.close();
	}

	//cursor tracker
	int X_cursor = 0;
	int Y_cursor = 0;

	RenderWindow window(VideoMode(880, 490), "Matrix", Style::Default);

	Font font;
	font.loadFromFile("pricedown bl.otf");
	Text timerText("", font, 30);
	timerText.setFillColor(Color::White);
	timerText.setPosition(480, 70);

	Text scoreText("", font, 30);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(480, 100);

	Text highScoreText("", font, 30);
	highScoreText.setFillColor(Color::White);
	highScoreText.setPosition(480, 130);

	//Gems
	Texture YellowTexture;
	YellowTexture.loadFromFile("yellow.jpeg");
	Sprite YellowSprite(YellowTexture);
	YellowSprite.setScale(0.15f, 0.15f);

	Texture GreenTexture;
	GreenTexture.loadFromFile("green.jpeg");
	Sprite GreenSprite(GreenTexture);
	GreenSprite.setScale(0.15f, 0.15f);

	Texture OrangeTexture;
	OrangeTexture.loadFromFile("orange.jpeg");
	Sprite OrangeSprite(OrangeTexture);
	OrangeSprite.setScale(0.15f, 0.15f);

	Texture PurpleTexture;
	PurpleTexture.loadFromFile("purple.jpeg");
	Sprite PurpleSprite(PurpleTexture);
	PurpleSprite.setScale(0.15f, 0.15f);

	Texture redTexture;
	redTexture.loadFromFile("red.jpeg");
	Sprite redSprite(redTexture);
	redSprite.setScale(0.15f, 0.15f);

	Texture Specialyellow;
	Specialyellow.loadFromFile("red1.jpeg");
	Sprite Spe_yellowSprite(Specialyellow);
	Spe_yellowSprite.setScale(1.3f, 1.3f);

	Texture Specialpurple;
	Specialpurple.loadFromFile("green1.jpeg");
	Sprite Spe_purpleSprite(Specialpurple);
	Spe_purpleSprite.setScale(0.6f, 0.6f);

	Texture Specialorange;
	Specialorange.loadFromFile("o1.jpeg");
	Sprite Spe_orangeSprite(Specialorange);
	Spe_orangeSprite.setScale(0.6f, 0.6f);

	Texture Specialred;
	Specialred.loadFromFile("red1.jpeg");
	Sprite Spe_redSprite(Specialred);
	Spe_redSprite.setScale(0.6f, 0.6f);

	Texture Specialgreen;
	Specialgreen.loadFromFile("green1.jpeg");
	Sprite Spe_greenSprite(Specialgreen);
	Spe_greenSprite.setScale(0.45f, 0.45f);

	////destroyer
	//Texture des_yellowTexture;
	//des_yellowTexture.loadFromFile("red1.jpeg");
	//Sprite des_yellow(des_yellowTexture);
	//des_yellow.setScale(1.3f, 1.3f);

	//Texture des_greenTexture;
	//des_greenTexture.loadFromFile("greendestroyer.jpeg");
	//Sprite des_green(des_greenTexture);
	//des_green.setScale(1.3f, 1.3f);

	//Texture des_orangeTexture;
	//des_orangeTexture.loadFromFile("orangedestoryer.jpeg");
	//Sprite des_orange(des_orangeTexture);
	//des_orange.setScale(1.3f, 1.3f);

	//Texture des_redTexture;
	//des_redTexture.loadFromFile("reddestroyer.jpeg");
	//Sprite des_red(des_redTexture);
	//des_red.setScale(1.3f, 1.3f);

	//Texture des_purpleTexture;
	//des_purpleTexture.loadFromFile("purpledestroyer.jpeg");
	//Sprite des_purple(des_purpleTexture);
	//des_purple.setScale(1.3f, 1.3f);

	//Randomised gem grid
	int Grid[8][8];
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Grid[i][j] = (rand() % 5) + 1;
		}
	}



	// Set cursor position
	//Cursor
	RectangleShape cursor(Vector2f(spacing * 1.0f, spacing * 1.0f));
	cursor.setFillColor(Color::Transparent);
	cursor.setOutlineThickness(2.5f);
	cursor.setOutlineColor(Color::Red);

	// Timer
	Time gameDuration = seconds(120); // Set the duration of the game in seconds
	Clock timer; // Create a clock to track elapsed time
	Time totalTime = Time::Zero; // Total elapsed time

	while (window.isOpen() && !timeEnd) {

		Time elapsedTime = timer.getElapsedTime(); // Get the elapsed time
		totalTime = elapsedTime; // Accumulate the elapsed time

		float gameDurationSeconds = gameDuration.asSeconds(); // Get game duration in seconds
		float totalTimeSeconds = totalTime.asSeconds(); // Get total elapsed time in seconds

		if (totalTime >= gameDuration) {
			cout << "Time's up!" << endl;
			timeEnd = true;
			window.close();
		}
		int remainingTime = gameDurationSeconds - totalTimeSeconds;
		int minutes = remainingTime / 60;
		int seconds = remainingTime % 60;

		// Set the time directly into the text object
		timerText.setString("Time: " + to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + to_string(seconds));
		scoreText.setString("Score: " + to_string(score));
		highScoreText.setString("High Score: " + to_string(highScore));

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}

			if (score > highScore) {
				highScore = score; // Update high score if the current score is higher
				saveHighscore(highScore); // Save the new high score
			}

			if (event.type == Event::KeyPressed) {


				// X_cursor > 0 to restrict movement out of grid (left)
				if (Keyboard::isKeyPressed(Keyboard::Left) && X_cursor > 0) {
					X_cursor--;
				}
				// X_cursor < gridsize-1   to restrict movement out of grid (right)
				else if (Keyboard::isKeyPressed(Keyboard::Right) && X_cursor < gridSize - 1) {
					X_cursor++;
				}
				// Y_cursor > 0 to restrict movement out of grid (UP)
				else if (Keyboard::isKeyPressed(Keyboard::Up) && Y_cursor > 0) {
					Y_cursor--;
				}
				// Y_cursor < gridSize-1 to restrict movement out of grid (Down)
				else if (Keyboard::isKeyPressed(Keyboard::Down) && Y_cursor < gridSize - 1) {
					Y_cursor++;
				}
				// swap (left)
				if (Keyboard::isKeyPressed(Keyboard::A) && X_cursor > 0) {
					int i = X_cursor;
					int j = Y_cursor;
					if (i > 0) {
						swap(Grid[i][j], Grid[i - 1][j]);
					}
				}

				// swap (right)
				if (Keyboard::isKeyPressed(Keyboard::D) && X_cursor < gridSize - 1) {
					int i = X_cursor;
					int j = Y_cursor;

					if (i < gridSize) {
						swap(Grid[i][j], Grid[i + 1][j]);
					}
				}
				// swap (up)
				if (Keyboard::isKeyPressed(Keyboard::W) && Y_cursor > 0) {
					int i = X_cursor;
					int j = Y_cursor;

					if (j >= 0) {
						swap(Grid[i][j], Grid[i][j - 1]);
					}
				}
				// swap(down)
				if (Keyboard::isKeyPressed(Keyboard::S) && Y_cursor < gridSize - 1) {
					int i = X_cursor;
					int j = Y_cursor;

					if (j >= 0) {
						swap(Grid[i][j], Grid[i][j + 1]);
					}
				}

			}

			elbow(Grid, score);


			// Check for special moves
			specialmove(Grid, score);

			//gem clearing
			for (int k = 0; k < 3; k++)
				sort(Grid, score);


			//move cursor
			cursor.setPosition(X_cursor * spacing + 0, Y_cursor * spacing + 0);


			window.clear();

			// Redraw the updated grid
			for (int x = 0; x < gridSize; x++) {
				for (int y = 0; y < gridSize; y++) {

					float spriteX = static_cast<float>(x) * spacing;
					float spriteY = static_cast<float>(y) * spacing;

					if (Grid[x][y] == 1 || Grid[x][y] == 6 || Grid[x][y] == 11) {
						YellowSprite.setPosition(spriteX, spriteY);
						window.draw(YellowSprite);
					}
					if (Grid[x][y] == 2 || Grid[x][y] == 7 || Grid[x][y] == 12) {
						PurpleSprite.setPosition(spriteX, spriteY);
						window.draw(PurpleSprite);
					}
					if (Grid[x][y] == 3 || Grid[x][y] == 8 || Grid[x][y] == 13) {
						redSprite.setPosition(spriteX, spriteY);
						window.draw(redSprite);
					}
					if (Grid[x][y] == 4|| Grid[x][y] == 9 || Grid[x][y] == 14) {
						OrangeSprite.setPosition(spriteX, spriteY);
						window.draw(OrangeSprite);
					}
					if (Grid[x][y] == 5) {
						GreenSprite.setPosition(spriteX, spriteY);
						window.draw(GreenSprite);
					}
					/*if (Grid[x][y] == 6 || Grid[x][y] == 11) {
						Spe_yellowSprite.setPosition(spriteX, spriteY);
						window.draw(Spe_yellowSprite);
					}

					if (Grid[x][y] == 7 || Grid[x][y] == 12) {
						Spe_purpleSprite.setPosition(spriteX, spriteY);
						window.draw(Spe_purpleSprite);
					}

					if (Grid[x][y] == 8|| Grid[x][y] == 13) {
						Spe_redSprite.setPosition(spriteX, spriteY);
						window.draw(Spe_redSprite);
					}

					if (Grid[x][y] == 9|| Grid[x][y] == 14) {
						Spe_orangeSprite.setPosition(spriteX, spriteY);
						window.draw(Spe_orangeSprite);
					}

					if (Grid[x][y] == 10 || Grid[x][y] == 15) {
						Spe_greenSprite.setPosition(spriteX, spriteY);
						window.draw(Spe_greenSprite);
					}*/

					//if (Grid[x][y] == 11) {
					//	des_yellow.setPosition(spriteX, spriteY);
					//	window.draw(des_yellow);
					//}

					//if (Grid[x][y] == 12) {
					//	des_purple.setPosition(spriteX, spriteY);
					//	window.draw(des_purple);
					//}

					//if (Grid[x][y] == 13) {
					//	des_red.setPosition(spriteX, spriteY);
					//	window.draw(des_red);
					//}

					//if (Grid[x][y] == 14) {
					//	des_orange.setPosition(spriteX, spriteY);
					//	window.draw(des_orange);
					//}

					//if (Grid[x][y] == 15) {
					//	des_green.setPosition(spriteX, spriteY);
					//	window.draw(des_green);
					//}
				}
			}

			window.draw(cursor);


			window.draw(timerText);
			window.draw(scoreText);
			window.draw(highScoreText);

			window.display();
		}
	}
	return 0;
}