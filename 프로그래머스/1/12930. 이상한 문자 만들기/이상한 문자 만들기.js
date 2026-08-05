function solution(s) {
    const words = s.split(' ');
    const newWords = [];
    
    for (let word of words) {
        let newWord = "";
        
        for (let i = 0; i < word.length; i++) {
            let cur = word[i];
            const curCode = cur.charCodeAt();

            if (i % 2 === 0 && ('a'.charCodeAt() <= curCode && curCode <= 'z'.charCodeAt())) {
                cur = cur.toUpperCase();
            }

            if (i % 2 === 1 && ('A'.charCodeAt() <= curCode && curCode <= 'Z'.charCodeAt())) {
                cur = cur.toLowerCase();
            }

            newWord += cur;
        }
        
        newWords.push(newWord);
    }
    
    return newWords.join(" ");
}