constexpr static int FIRST_LETTER = 'a';
constexpr static int LAST_LETTER = 'z';
constexpr static int ALPHABET_SIZE = LAST_LETTER - FIRST_LETTER + 1;

struct Node 
{
    array<unique_ptr<Node>, ALPHABET_SIZE> children{};
    bool isTerminal = false;
};

class Trie 
{
    unique_ptr<Node> root = make_unique<Node>();

public:
    Trie() 
    {
    }

private:
    Node* searchImpl(const string& word)
    {
        auto* node = root.get();
        for (int i = 0; i < word.length(); ++i) 
        {
            const int letter = word[i] - FIRST_LETTER;
            if (!node->children[letter]) 
            {
                return nullptr;
            }
            node = node->children[letter].get();
        }
        return node;
    }

public:
    void insert(const string& word) 
    {
        auto* node = root.get();
        for (int i = 0; i < word.length(); ++i) 
        {
            const int letter = word[i] - FIRST_LETTER;
            if (!node->children[letter]) 
            {
                node->children[letter] = make_unique<Node>();
            }
            node = node->children[letter].get();
        }
        node->isTerminal = true; 
    }
    
    bool search(const string& word) 
    {
        auto* node = searchImpl(word);
        if (!node)
            return false;
        return node->isTerminal;
    }
    
    bool startsWith(const string& word) 
    {
        auto* node = searchImpl(word);
        return node != nullptr;
    }
};