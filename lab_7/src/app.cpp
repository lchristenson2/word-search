#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <LinkedList.h>
#include <Array.h>
#include <TimeSupport.h>

using namespace std;

//hash function
long f(string word) {
    long r = (long)word[0];
    long index = 1;

    while(index < 4 && index < word.length()) {
        r += (long)word[index] * 250 * index;

        index++;
    }

    return r;
}

bool isPalin(string word) {
    for(long i = 0; i < word.length()/2; i++) {
        if(word[i] != word[word.length()-1-i]) {
            return false;
        }
    }

    return true;
}

string reverse(string word){
    reverse(word.begin(), word.end());
    return word;
}

bool find(string word, LinkedList list[]) {

    return list[f(word)].search(word);
}

int main() {
    timestamp start = current_time();

    ifstream inputFile("words.txt");

    string word;
    long counter = 0;
    const long N = 150000;

    LinkedList table[N];
    ResizableArray wordsRev;

    while(inputFile) {
        inputFile >> word;

        if(isPalin(word)) {
            counter++;
        }

        else {
            wordsRev.append(reverse(word));

            table[f(word)].append(word);
        }
    }

    for(long i = 0; i < wordsRev.capacity; i++) {
        if(find(wordsRev[i], table)) {
            counter++;
        }
    }

    cout << counter << " matches found!" << endl;

    timestamp end = current_time();

    cout << "Took " << time_diff(start, end) << " ms" << endl;

return 0;

}
