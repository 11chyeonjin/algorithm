function solution(n, words) {
    const set = new Set();
    set.add(words[0]);
    
    for (let i = 1; i < words.length; i++) {
        if (set.has(words[i]) || (words[i - 1].slice(-1) !== words[i].slice(0, 1))) {
            return [((i + 1) % n) || n, Math.floor(i / n) + 1];
        }
        
        set.add(words[i]);
    }
    
    return [0, 0];
}