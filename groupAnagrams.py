def groupAnagrams(strs):
   """
   :type strs: List[str]
   :rtype: List[List[str]]
   """
   anagram_map = {}
   for word in strs:
       #word : eat, tea, tan, ate, nat, bat
       sorted_word = "".join(sorted(word))
       #sorted word: aet, aet, ant, aet, ant, abt
       if sorted_word not in anagram_map:
           anagram_map[sorted_word] = []
           #anagram_map : {'aet': [], 'ant': [], 'abt': []}
       anagram_map[sorted_word].append(word)
       #anagram_map : {'aet': ['eat', 'tea', 'ate'], 'ant': ['tan', 'nat'], 'abt': ['bat']}
   return(list(anagram_map.values()))
strs1 = ["eat","tea","tan","ate","nat","bat"]
result = groupAnagrams(strs1)
print(result)