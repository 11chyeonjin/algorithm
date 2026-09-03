function solution(elements) {
    const rst = new Set();
    
    const eL = elements.length;
    
    elements.push(...elements);
    
    function sol(_size) {
        let cur = 0;
        
        for (let i = 0; i < _size; i++) {
            cur += elements[i];
        }
        
        rst.add(cur);
        
        for (let i = 0; i < eL; i++) {
            cur += elements[_size + i];
            cur -= elements[i];
            rst.add(cur);
        }
    }
    
    for (let i = 1; i <= eL; i++) {
        sol(i);
    }
    
    return rst.size;
}