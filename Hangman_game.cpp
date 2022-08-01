#include <iostream>
#include <string>
#include <vector>

void closed_word(std::vector<int>& c_letters, std::string& word) {
    for (char i{}; i < word.size(); ++i) {
        c_letters.push_back ('*');
    }
    for (int i{}; i < word.size(); ++i) {
        std::cout << static_cast <char> (c_letters[i]) << " ";
    }
    std::cout << std::endl;
}

void start_game(std::string& word, std::vector<int>& letter) {
    std::cout << "you have to collect the word by opening the letters " << std::endl;
    char input_letter = 0;
    int count_of_letter = 0;
    for (int i{}; i < word.length(); ++i) {
        if (i < word.length()) {
            ++count_of_letter;
        }
    }
    std::cout << " please input " << count_of_letter << " letters" << std::endl;
    for (int i{}; i < letter.size(); ++i) {
        std::cin >> input_letter;
        char tmp = std::cin.get();
        if (tmp != '\n') {
            std::cout << "Please input only one letter!" << std::endl;
            std::cin.ignore(1);
            std::cin.clear();
            --i;
            continue;
        }
        if ((input_letter < 'A' || input_letter > 'z') || (input_letter > 'Z' && input_letter < 'a')) {
            std::cout << "Please input letter!" << std::endl;
            --i;
            continue;	
        }
        bool is_valid = false;
        bool is_repeated = false;
        for (int j{}; j < word.length(); ++j) {
            if (input_letter == word[j] || input_letter == word[j] + 32 || input_letter + 32 == word[j]) {
                if ((input_letter == letter[j] || input_letter == letter[j] + 32 || input_letter + 32 == letter[j])) {
                    is_repeated = true;
                    break;                       
                }
                letter[j] = input_letter;
                is_valid = true;
                for (int v_i{}; v_i < letter.size(); ++v_i) {
                    std::cout << static_cast <char> (letter[v_i]) << " ";
                }
                std::cout << std::endl;	 
            }
        }
        if (is_repeated) {
            std::cout << "Your input is repeated. Please input other letter" << std::endl;
            --i;
            continue;
        }
        if (!is_valid) {
            std::cout << "The given letter is missing in the word" << std::endl;
        }
    }
    std::cout << std::endl;
}

void final_look(std::vector<int>& letter) {
    std::cout << "what you did : ";
    for (char i{}; i < letter.size(); ++i) {
        std::cout << static_cast <char> (letter[i]) << " "; 
    }
}

void check_answer(std::vector<int>& letter, std::string& word) {
    int count_of_asterisk = 0;
    for (int v_i{}; v_i < letter.size(); ++v_i) {
        if (letter[v_i] == '*') {
            ++count_of_asterisk;
        }
    }
    if (count_of_asterisk == 0) {
        std::cout << "YOU ARE WIN";
    }
    else {	
        std::cout << "You are lose because you can't open " << count_of_asterisk << " letter" << std::endl;
        std::cout << "saved word was : " << word << std::endl;
        final_look(letter);
    }
    std::cout << std::endl;
}

int main() {
    srand(time(0));
    const std::string word_list[5] = { "compiler", "computer", "algorithm", "goodbye", "PicsartAcademy" };
    std::string word = word_list[rand() % 5];
    std::vector<int> letter;
    closed_word(letter,word);
    start_game(word,letter);
    check_answer(letter, word);
}
