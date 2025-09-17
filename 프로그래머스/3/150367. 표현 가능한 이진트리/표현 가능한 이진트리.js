function solution(numbers) {
    let answer = [];
    
    const binaryArr = [ 1 ];
    
    for (let i = 1; i < 51; i++) {
        binaryArr[i] = binaryArr[i - 1] + 2 ** i;
    }
    
    function func(number) {
        let str = number.toString(2);
        let str_length = str.length;
        
        for (let i = 0; i < 51; i++) {
            if (str_length === binaryArr[i]) {
                break;
            }
            
            if (str_length < binaryArr[i]) {
                let tmp_str = "";
                for (let j = 0; j < binaryArr[i] - str_length; j++) {
                    tmp_str += "0";
                }
                str = tmp_str + str;
                break;
            }
        }
        
        // 트리라는 자료구조의 특징을 가지고 루트 노드부터 접근이 가능함.
        
        let flag = true;
        
        function validCheck(bt) {        
            const bt_length = bt.length;
            if (bt_length <= 1) {
                return;
            }
            
            const mid = Math.floor(bt_length / 2);
            const root = bt[mid];
            const lc_bt = bt.slice(0, mid);
            const rc_bt = bt.slice(mid + 1);
            
            if (root === '0') {
                if (lc_bt.includes('1') || rc_bt.includes('1')) {
                    flag = false;
                    return;
                }
            }
            
            validCheck(lc_bt);
            validCheck(rc_bt);
        }
        
        validCheck(str);
        
        return flag ? 1 : 0;
    }
    
    numbers.forEach((num) => {
        answer.push(func(num));
    })
    
    return answer;
}