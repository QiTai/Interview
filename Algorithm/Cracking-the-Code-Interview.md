### 高难度题
+ 18.10

```java
LinkedList<String> transform(String startWord, String stopWord, Set<String> dictionary) {
    startWord = startWord.toUpperCase();
    stopWord = stopWord.toUpperCase();
    Queue<String> actionQueue = new LinkedList<String>();
    Set<String> visitedSet = new HashSet<String>();
    Map<String, String> backtrackMap = new TreeMap<String, String>();

    actionQueue.add(startWord);
    visitedSet.add(startWord);

    while (!actionQueue.isEmpty()) {
        String w = actionQueue.poll();
        for (String v : getOneEditWords(w)) {
            if (v.equals(stopWord)) {
                LinkedList<String> list = new LinkedList<String>();
                list.add(v);
                while (w != null) {
                    list.add(0, w);
                    w = backtrackMap.get(w);
                }
                return list;
            }
            if (dictionary.contains(v)) {
                if (!visitedSet.contains(v)) {
                    actionQueue.add(v);
                    visitedSet.add(v);
                    backtrackMap.put(v, w);
                }
            }
        }
    }
    return null;
}

Set<String> getOneEditWords(String word) {
    Set<String> words = new TreeSet<String>();
    for (int i = 0; i < word.length(); i++) {
        char[] wordArray = word.toCharArray();
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c != word.charAt(i)) {
                wordArray[i] = c;
                words.add(new String(wordArray));
            }
        }
    }
    return words;
}
```
