function solution(clothes) {
    const _map = new Map();
    
    for (const [value, type] of clothes) {
        if (_map.get(type))  {
            _map.set(type, _map.get(type) + 1);
        } else {
            _map.set(type, 1);
        }
    }
    
    let answer = 1;
    
    for (const [key, value] of _map) {
        answer *= value + 1;
    }
    
    answer -= 1;
    
    return answer;
}