/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 100 ms - Beats 89.38% of submissions
 * Memory: 13.2 MB - Beats 68.61% of submissions
 * Data Structures: Graphs, Queues
 * Algorithms: BFS
 * Other:
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        queue<string> word_queue; 
        int level = 1;
        word_queue.push(beginWord);
        while (!word_queue.empty())
        {
            int word_queue_size = word_queue.size();
            for (int i = 0; i < word_queue_size; i++)
            {
                string current_word = word_queue.front();
                word_queue.pop();
                if (current_word == endWord)
                {
                    return level;
                }
                word_set.erase(current_word);
                for (int j = 0; j < current_word.size(); j++)
                {
                    char original_letter = current_word[j];
                    for (char letter = 'a'; letter <= 'z'; letter++)
                    {
                        current_word[j] = letter;
                        if (word_set.find(current_word) != word_set.end())
                        {
                            word_queue.push(current_word);
                        }
                    }
                    current_word[j] = original_letter;
                }
            }
            level++;
        }
        return 0;
    }
};
