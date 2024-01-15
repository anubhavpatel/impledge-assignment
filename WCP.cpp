#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


//..................................Trie implementation....................................

struct Trie_implementation                 
{
    Trie_implementation *nodes[26];
    bool flag;
    bool check_key(char ch)
    {
        return nodes[ch - 'a'] != NULL;
    }
    Trie_implementation *take(char ch)
    {
        return nodes[ch - 'a'];
    }
    void update(char ch, Trie_implementation *node)
    {
        nodes[ch - 'a'] = node;
        return;
    }
    bool is_finish()
    {
        return flag;
    }
    void set_finish()
    {
        flag = true;
        return;
    }
    void update_false()
    {
        flag = false;
        return;
    }
};

//..................................... solution class...............................................

class Result                                    
{
    Trie_implementation *root;

public:
     Result()
    {
        root = new Trie_implementation();
    }

    static bool comparator(string i, string j)   //sorting comparator
    { 
        if (i.length() == j.length())
            return i < j;
        return i.length() > j.length();
    }

    void initialize_word(string word)          // used to initialize word in trie
    {
        Trie_implementation *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->check_key(word[i]))
            {
                node->update(word[i], new Trie_implementation());
            }
            node = node->take(word[i]);
        }
        node->set_finish();
    }

    void obj(string str, int ind, Trie_implementation *temp_node)   // used to reset flag as false
    {
        if (ind == str.length())
        {
            temp_node->update_false();
            return;
        }
        obj(str, ind + 1, temp_node->take(str[ind]));
        return;
    }

    bool isformed(string str, int ind, Trie_implementation *temp_node)   // used to check formed by other words or not
    {
        if (ind == str.length())
        {
            return temp_node->is_finish();
        }
        if (temp_node->is_finish())
        {
            if (isformed(str, ind, root))
                return true;
        }
        if (temp_node->check_key(str[ind]))
        {
            return isformed(str, ind + 1, temp_node->take(str[ind]));
        }
        else
        {
            return false;
        }
    }

    void Longest_word_finder(vector<string> &word)    //function to find largest word
    {
        vector<string> result;
        for (int i = 0; i < word.size(); i++)
        {
            result.push_back(word[i]);
            initialize_word(word[i]);
        }
        sort(result.begin(), result.end(), comparator);   // used to acces words in largest to smallest order for fast answer finding
        string result1 = "", result2 = "";
        for (int i = 0; i < result.size(); i++)
        {
            obj(result[i], 0, root);                    // used to reset for second largest

            if (isformed(result[i], 0, root))
            {
                if (result1.length() == 0)
                    result1 = result[i];
                else
                {
                    result2 = result[i];
                    break;
                }
            }
            initialize_word(result[i]);                // used to set is_finish as true(end of word)
        }
        cout << "Longest Compounded word: " << result1 << endl;
        cout << "Second Longest Compounded word: " << result2 << endl;
        return;
    }
};

//...........................Driver Code................................................

int main()
{
    Result obj;
    fstream fs;
    vector<string> result;                       // Stores words from input file
    fs.open("Input_02.txt", ios::in);
    if (fs.fail())
    {
        cout << "file not imported";
    }
    else
    {
        string s;
        while (fs >> s)
        {
            result.push_back(s);
        }
        fs.close();

        auto initial_time = high_resolution_clock::now();
        obj.Longest_word_finder(result);
        auto end_time = high_resolution_clock::now();
        auto time_taken = duration_cast<microseconds>(end_time - initial_time);
        cout << "Time taken to process the inupdate file: " << time_taken.count() << " microseconds" << endl;
    }
    return 0;
}
