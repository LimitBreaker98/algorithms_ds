#!/usr/bin/env python
# coding: utf-8

# ## String Data Structures
# #### Author: Jorge A
# #### Inspired by CompProg3

# ### Trie

# In[142]:


class TrieNode:
    def __init__(self, char: str, isWord: bool):
        self.next_chars = {} #Dictionary of Trie Nodes, access and retrieval O(1) as hashing a char is constant time
        self.char = char
        self.ends_word = isWord
    
    def has_char(self, char: str) -> bool:
        return char in self.next_chars
    
    def count_words_prefix_dfs(self) -> int:
        cnt = 0
        for char in self.next_chars:
            cnt += self.next_chars[char].count_words_prefix_dfs()
        if self.ends_word:
            cnt += 1
        return cnt
    
    


# In[143]:


class Dictionary:
    def __init__(self):
        self.root = TrieNode(None, False)
    
    def add_word(self, word: str) -> None:
        curr_node = self.root
        for char in word:
            if not curr_node.has_char(char):
                curr_node.next_chars[char] = TrieNode(char, False)
            curr_node = curr_node.next_chars[char]
        curr_node.ends_word = True
    
    """
        get_prefix will return None if the word is not found, otherwise it will return the last node of the word. 
        This is not called get_word as maybe the input is not actually a word.
        Then, has word only has to call get_prefix and then ask if it is actually a word.
    """
    def get_prefix(self, word: str) -> TrieNode:
        curr_node = self.root
        for char in word:
            if not curr_node.has_char(char):
                return False
            curr_node = curr_node.next_chars[char]
        return curr_node

    def has_word(self, word: str) -> bool:
        curr_node = self.get_prefix(word)
        return curr_node and curr_node.ends_word
    
    def count_words_with_prefix(self, prefix: str) -> int:
        prefix_node = self.get_prefix(prefix)
        return prefix_node.count_words_prefix_dfs()


# In[144]:


dicc = Dictionary()


# In[145]:


dicc.add_word("rat")
dicc.add_word("rattata")
dicc.add_word("rat")
dicc.add_word("ratita")
dicc.add_word("ibai")
dicc.add_word("raton")
dicc.add_word("matrix")
dicc.add_word("matriz")
dicc.add_word("matrushka")
dicc.add_word("jorge")
dicc.add_word("jose")
dicc.add_word("jorge")
dicc.add_word("jorge")
dicc.add_word("jorgito")
dicc.add_word("jorge")


# #### Testing

# In[150]:


for word in ["rat", "rattata", "ratita", "ibai", "raton", "matrix", "matriz", "matrushka", "jorge", "jose", "jorgito"]:
    assert dicc.has_word(word)


# In[151]:


for word in ["ra", "ratata", "rati", "iai", "rato", "matri", "matriy", "matruzhka", "Jorge", "josé", "lemus"]:
    assert not dicc.has_word(word)


# In[152]:


assert dicc.count_words_with_prefix("ra") == 4


# In[155]:


assert dicc.count_words_with_prefix("rat") == 4


# In[157]:


assert dicc.count_words_with_prefix("raton") == 1


# In[ ]:




