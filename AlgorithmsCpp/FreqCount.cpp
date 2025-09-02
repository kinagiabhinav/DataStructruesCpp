#include <iostream>
#include <vector>
#include <unordered_map>

// Anagram check Time O(N) Space O(1)
bool validAnagram(std::string first, std::string second) {
    // Check the length of both strings if diff return false
    if (first.size() != second.size()) {
        return false;
    }
    // Count the number of occurences
    std::unordered_map<char, int> anagramMap = {};
    
    // Loop through each char, append it to map
    for (const char &c : first) {
        anagramMap[c]++;
    }

    // Decrement the count for each character in the second string
    for (const char &c : second) {
        if (anagramMap.find(c) == anagramMap.end() || anagramMap[c] == 0) {
            return false;
        }
        anagramMap[c]--;
    }
    
    return true;
}

int main() {
    std::cout << validAnagram("abbc", "ccba") << std::endl;
    std::cout << validAnagram("", "") << std::endl;
    std::cout << validAnagram("", "a") << std::endl;
    std::cout << validAnagram("ab", "cc") << std::endl;
    
}