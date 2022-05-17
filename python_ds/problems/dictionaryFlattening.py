"""
    IMPORTANT: A commented asterisk means lines added after a 45 minute session, simulating an
    interview setting. 

   Idea: 
    The nested dictionary describes a tree.

    For example, this tree 
             head
        key1.    key2  
                a   b   c
                      d   e
                         "" x

    Corresponds to this dictionary:
    "Key1": "1",
            "Key2" : {
                "a" : "2",
                "b" : "3",
                "c" : {
                    "d" : "3",
                    "e" : {
                        "" : "1",
                        "x": "5",
                      	"e2" : {
                        	"" : "1",
                        	"x": "5"
                    	}
                    }
                }
            }
    
    Problem:                      
  # Take a possibly multi-depth dictionary and transform it into a plain (one-depth) dictionary.
  # Every nested level key is separated by a . in the output dictionary. 
  # Possibly use a recursion traversal.
  # Every time we see an empty key, we guarantee there is an extra depth level for the dictionary. 
  # We only have base-values or dictionaries inside the dictionary.

  ## there's one function processKey(key, dict)
  ## processKey has 2 cases
  ## one is that its a base-value -> Key1 -> "1"
  ## Other case (recursive case) is that the value at the key is another dictionary. 
  
  Every time that the function goes with the recursive case, we have to put the currentKey first in the newKey.
  
  The main program (flatten_dictionary) has a loop to iterate over all the depth-1 keys. 
  Inside the loop, we call the processKey() function for all depth-1 keys.
  We have to make sure that the recrusive call loops through all the depth-1 keys relative to the key being called.
  
  Time Complexity: O(keys * processingKey), where processingKey is the time it takes to build the accumulated key at every recursive call.
"""

import unittest 

def build_new_accumulated_key(accumulated_key, next_depth_key):
    next_level_key = ""
    if next_depth_key != "":
        # "".join() would make this faster (linear time)
        if accumulated_key:
            next_level_key = accumulated_key + "." 
        next_level_key += next_depth_key
    return next_level_key


def process_keys(key, accumulated_key, dictionary, output_dictionary):
    value = dictionary[key]
    if type(value) != dict:
        output_dictionary[accumulated_key] = value
    else:
        for next_depth_key in value:
            new_accumulated_key = build_new_accumulated_key(accumulated_key, next_depth_key)
            process_keys(next_depth_key, new_accumulated_key, value, output_dictionary)

def flatten_dictionary(dictionary):
    output_dictionary = {}
    for key in dictionary:
        process_keys(key, key, dictionary, output_dictionary)
    return output_dictionary

# Tests!


class TestDictionaryFlattening(unittest.TestCase):
    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

    def test_flat_dict(self):
        input = {"a": "3", "b": "5", "zxy": "7", "c": "9"}
        expected = input.copy()
        result = flatten_dictionary(input)
        self.assertEqual(expected, result, "Both dictionaries were not equal")

    def test_nested_dict(self):
        input = {
            "a": {
                "b": "5"
            }
        }
        expected = {"a.b": "5"}
        result = flatten_dictionary(input)
        self.assertEqual(expected, result, "Both dictionaries were not equal")
    
    def test_shallow_nested_dict(self):
        input = {
            "a": {
                "b": "5"
            }
        }
        expected = {"a.b": "5"}
        result = flatten_dictionary(input)
        self.assertEqual(expected, result, "Both dictionaries were not equal")
    
    def test_deep_nested_dict_multi_types(self):
        input = {
            "a": {
                "b": "5",
                "c": "7",
                "d": {
                    "e": "9",
                    "f": "11",
                    "g": {
                        "h": [1,3,5],
                        "i": 1
                    }
                }
            },
            "d2": {
                    "e2": "10",
                    "f2": "12",
                    "g2": {
                        "h2": [2,4,6],
                        "i2": 2
                    }
            }
        }
        expected = {
            "a.b": "5",
            "a.c": "7",
            "a.d.e": "9",
            "a.d.f": "11",
            "a.d.g.h": [1,3,5],
            "a.d.g.i": 1,
            "d2.e2": "10",
            "d2.f2": "12",
            "d2.g2.h2": [2,4,6],
            "d2.g2.i2": 2,
        }
        result = flatten_dictionary(input)
        self.assertEqual(expected, result, "Both dictionaries were not equal")
    
    def test_empty_string_keys(self):
        input = {
            "": {
                "b": "5"
            }
        }
        expected = {"b": "5"}
        result = flatten_dictionary(input)
        self.assertEqual(expected, result, "Both dictionaries were not equal")

if __name__ == '__main__':
    unittest.main()
