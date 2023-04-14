"""
    Note for graders: 
    My program assumes the following:
    1. Items returned by the API do not have repeated keys.
      - If that was the case, I'd have to add additional checks to not count a same element twice.
      - Also, it could be that data is corrupt (2 equal keys having distinct age values) and I'd need further info on how to tiebreak this case.
"""

import requests
import numpy as np
import pandas as pd

def equal_or_greater_age(age: str, target: int):
  # Age comes in this format: 'age=xxx' where xxx represents each of the digits of the age.
  age_int = int(age.split("=")[1])
  return age_int >= target


r = requests.get('https://coderbyte.com/api/challenges/json/age-counting')
response_dict = r.json()
data_list = response_dict["data"].split(", ")

# First, get rid of list items of the form 'key=xxxxx' since we don't need them
data_list = [data_list[i] for i in range(len(data_list)) if i % 2 == 1]

# Now filter the data_list using the equal_or_greater_age helper function
data_list = [age for age in data_list if equal_or_greater_age(age, 50)]


print(len(data_list))