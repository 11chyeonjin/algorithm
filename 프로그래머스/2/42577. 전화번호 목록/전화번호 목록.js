function solution(phone_book) {
    phone_book.sort();
    
    for (let i = 0; i < phone_book.length - 1; i++) {
        let flag = false;
        for (let j = 0; j < phone_book[i].length; j++) {
            if (phone_book[i][j] !== phone_book[i + 1][j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return flag;
    }
    return true;
}