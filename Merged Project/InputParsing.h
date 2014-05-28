#include <vector>
#include <string>

using namespace std;

/*
ParseInput
Input: string to be parsed
Output: vector containing the first word and the rest of the input string
Usage: Call this function to split a string into two parts. The first is a single word, the second is the rest of the string (if there is anything left).
The function does not split the rest of the string into words as this game only allows for 1 or 2-word input.
Example: ParseInput("kill evil ogre")
		-returns a vector containing two strings: "kill" and "evil ogre"
Example: ParseInput("north")
		-returns a vector containing one string: "north"
*/
vector<string> ParseInput(string p_input)
{
	//Vector where parsed strings will be stored
	vector<string> finalInput;
	//Buffer to keep track of each letter, so the program can iterate through the string until a break point is reacahed
	string buffer = "";
	//Iterate through the input string character by character
	for (int i = 0; i < p_input.size(); i++)
	{
		//If the current character is not a space, add the character to the buffer
		if (p_input[i] != ' ')
		{
			buffer += p_input[i];
		}
		else
		{
			//If the current character is a space, the first of two words has been found. Add this word to the output vector.
			finalInput.push_back(buffer);
			//This will erase the first word and the following space from the p_input string, leaving the rest of the string ("evil ogre" in "kill evil ogre")
			p_input.erase(0, i+1);
			//Push the rest of the input string into the vector
			finalInput.push_back(p_input);
			//Return the two strings here.
			return finalInput;
		}
	}
	//If the for loop ends without hitting a space character, then the input is one word. Add this word to the output vector and return it.
	finalInput.push_back(buffer);
	return finalInput;
}