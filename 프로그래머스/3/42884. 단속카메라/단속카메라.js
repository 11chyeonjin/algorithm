function solution(routes) {
    routes.sort(function(a, b) {
        return a[1] - b[1];
    })
    
    let curCamera = -30001;
    let answer = 0;
    
    for (let value of routes) {
        if (value[0] > curCamera) {
            answer++;
            curCamera = value[1];
        }
    }
    
    return answer;
}